/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:55:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/09 12:27:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_asm_parser.h"

#define TOKEN_DEF(S,DATA)	((t_token_def){SUBC(S), V(DATA)})

static t_token_map			*ft_token_map_build(t_vector const *t)
{
	t_token_map *const			map = NEW(t_token_map);
	uint32_t					i;

	*map = TOKEN_MAP();
	i = 0;
	while (i < t->length)
		ft_token_map(map, VECTOR_GET(*t, i++));
	return (map);
}

static t_vector const	g_token_map = VECTOR(t_token_def,
	TOKEN_DEF(" ", TOKEN_SPACE),
	TOKEN_DEF("\t", TOKEN_SPACE),
	TOKEN_DEF("\n", TOKEN_ENDL),
	TOKEN_DEF("\"", TOKEN_QUOTE),
	TOKEN_DEF("%", TOKEN_MODULO),
	TOKEN_DEF("%:", TOKEN_LABEL),
	TOKEN_DEF(";", TOKEN_COMMENT),
	TOKEN_DEF("#", TOKEN_COMMENT),
	TOKEN_DEF(":", TOKEN_COLON),
	TOKEN_DEF(",", TOKEN_COMMA),
);

static bool			err_unexpected_token(t_asm_parser *p)
{
	ft_asprintf(p->err, "Unexpected token '%ts'", p->t.token);
	return (false);
}

/*
** ========================================================================== **
** Comment
*/

static t_vector const	g_comment_token_map = VECTOR(t_token_def,
	TOKEN_DEF("\\\n", TOKEN_COMMENT_ESCAPED),
	TOKEN_DEF("\n", TOKEN_COMMENT_ENDL),
);

static bool			parse_comment(t_asm_parser *p)
{
	static t_token_map const	*map = NULL;
	t_token_map const *const	old_map = p->t.token_map;

	if (map == NULL)
		map = ft_token_map_build(&g_comment_token_map);
	p->t.token_map = map;
	while (ft_tokenize(&p->t))
		if (((uint32_t)p->t.token_data) == TOKEN_COMMENT_ENDL)
		{
			p->line++;
			break ;
		}
	p->t.token_map = old_map;
	return (true);
}

/*
** ========================================================================== **
** string
*/

static t_vector const	g_string_token_map = VECTOR(t_token_def,
	TOKEN_DEF("\\\"", TOKEN_STRING_ESCAPED),
	TOKEN_DEF("\n", TOKEN_STRING_ENDL),
	TOKEN_DEF("\"", TOKEN_STRING_QUOTE),
);

static bool			parse_string(t_asm_parser *p, t_dstr *dst)
{
	static t_token_map const	*map = NULL;
	t_token_map const *const	old_map = p->t.token_map;

	if (map == NULL)
		map = ft_token_map_build(&g_string_token_map);
	p->t.token_map = map;
	while (ft_tokenize(&p->t))
		if (((uint32_t)p->t.token_data) == TOKEN_COMMENT_ENDL)
			p->line++;
		else if (((uint32_t)p->t.token_data) == TOKEN_QUOTE)
			break ;
		else
			ft_dstradd(dst, p->t.token);
	p->t.token_map = old_map;
	return (true);
}

/*
** ========================================================================== **
** pre string
*/

static bool			parse_pre_string(t_asm_parser *p, t_dstr *dst)
{
	while (ft_tokenize(&p->t))
	{
		if (((uint32_t)p->t.token_data) == TOKEN_QUOTE)
			return (parse_string(p, dst));
		if (((uint32_t)p->t.token_data) == TOKEN_ENDL)
			break ;
		if (((uint32_t)p->t.token_data) != TOKEN_SPACE)
			return (err_unexpected_token(p));
	}
	ft_asprintf(p->err, "Unexpected end of line");
	return (false);
}

/*
** ========================================================================== **
** label
*/

static bool			push_label(t_asm_parser *p, t_sub name)
{
	if ((ft_hmapget(p->dst.labels, name)).value != NULL)
		return (ft_asprintf(p->err, "Label '%ts' redefined", name), false);
	ft_hmapputp(p->dst.labels, name, &p->dst.instr.length);
	return (true);
}

/*
** ========================================================================== **
** instr arg
*/

static bool			parse_instr_arg_ind(t_asm_parser *p, t_instr_arg *dst)
{
	t_sub const			ind = SUB_FOR(p->t.token, 1);

	dst->e = INSTR_ARG_IND;
	if (ind.length == 0 || ft_subto_int(ind, &dst->u.ind) != ind.length)
		return (ft_asprintf(p->err, "Invalid identifier: '%ts'", p->t.token), false);
	return (true);
}

static bool			parse_instr_arg_reg(t_asm_parser *p, t_instr_arg *dst)
{
	t_sub const			reg = SUB_FOR(p->t.token, 1);

	dst->e = INSTR_ARG_REG;
	if (reg.length == 0 || ft_subto_uint(reg, &dst->u.reg) != reg.length)
		return (ft_asprintf(p->err, "Invalid identifier: '%ts'", p->t.token), false);
	if (dst->u.reg > REG_NUMBER || dst->u.reg < 1)
		return (ft_asprintf(p->err, "Invalid register r%u%n", dst->u.reg), false);
	return (true);
}

static bool			parse_instr_arg_dir(t_asm_parser *p, t_instr_arg *dst)
{
	if (!ft_tokenize(&p->t))
		return (ft_asprintf(p->err, "Unexpected end of file"), false);
	if (((uint32_t)p->t.token_data) != TOKEN_UNKNOWN)
		return (err_unexpected_token(p));
	dst->e = INSTR_ARG_DIR;
	if (ft_subto_int(p->t.token, &dst->u.ind) != p->t.token.length)
		return (ft_asprintf(p->err, "Invalid value: '%ts'", p->t.token), false);
	return (true);
}

static bool			parse_instr_arg_label(t_asm_parser *p, t_instr_arg *dst)
{
	if (!ft_tokenize(&p->t))
		return (ft_asprintf(p->err, "Unexpected end of file"), false);
	if (((uint32_t)p->t.token_data) != TOKEN_UNKNOWN)
		return (err_unexpected_token(p));
	dst->e = INSTR_ARG_LABEL;
	dst->u.label = ft_aprintf("%ts", p->t.token);
	return (true);
}

// TODO: new token map

static bool			parse_instr_arg(t_asm_parser *p, t_instr_arg *dst)
{
	while (true)
	{
		if (!ft_tokenize(&p->t))
			return (ft_asprintf(p->err, "Unexpected end of file"), false);
		else if (((uint32_t)p->t.token_data) != TOKEN_SPACE)
			break ;
	}
	if (((uint32_t)p->t.token_data) == TOKEN_UNKNOWN)
		return ((p->t.token.str[0] == 'r') ?
				parse_instr_arg_reg(p, dst) : parse_instr_arg_ind(p, dst));
	else if (((uint32_t)p->t.token_data) == TOKEN_MODULO)
		return (parse_instr_arg_dir(p, dst));
	else if (((uint32_t)p->t.token_data) == TOKEN_LABEL)
		return (parse_instr_arg_label(p, dst));
	return (err_unexpected_token(p));
}

/*
** ========================================================================== **
** instr arg list
** => instr arg
*/

static bool			parse_instr_arg_list(t_asm_parser *p, t_instr *dst)
{
	while (true)
	{
		if (!parse_instr_arg(p, &dst->args[dst->arg_count]))
			return (false);
		dst->arg_count++;
		while (ft_tokenize(&p->t))
		{
			if (((uint32_t)p->t.token_data) == TOKEN_SPACE)
				continue ;
			else if (((uint32_t)p->t.token_data) == TOKEN_ENDL)
				return ((++p->line), true);
			else if (((uint32_t)p->t.token_data) == TOKEN_COMMENT)
				return (parse_comment(p));
			else if (((uint32_t)p->t.token_data) == TOKEN_COMMA)
				break ;
			return (err_unexpected_token(p),
					ft_asprintf(p->err, ", expecting ','"), false);
		}
	}
}

/*
** ========================================================================== **
** instr
** => instr arg list
*/

#include "op.h"

static bool			get_opcode(t_sub name, uint32_t *dst)
{
	uint32_t			i;
	t_sub				opname;

	i = 1;
	while (i <= OPCODE_COUNT)
	{
		opname = ft_sub(g_op_tab[i].name, 0, -1);
		if (SUB_EQU(opname, name))
		{
			*dst = i;
			return (true);
		}
		i++;
	}
	return (false);
}

static bool			parse_instr(t_asm_parser *p, t_sub name)
{
	uint32_t			opcode;
	t_instr				*instr;

	if (!get_opcode(name, &opcode))
		return (ft_asprintf(p->err, "Unknown instruction '%ts'", name), false);
	instr = ft_vpush(&p->dst.instr, NULL, 1);
	*instr = (t_instr){opcode, {{0, {0}}}, 0};
	return (parse_instr_arg_list(p, instr));
}

/*
** ========================================================================== **
** label or instr
** => label
** => instr
*/

static bool			parse_label_or_instr(t_asm_parser *p)
{
	t_dstr				name;
	bool				r;

	name = ft_aprintf("%ts", p->t.token);
	if (!ft_tokenize(&p->t))
		r = (ft_asprintf(p->err, "Unexpected end of file"), false);
	else if (((uint32_t)p->t.token_data) == TOKEN_COLON)
		r = push_label(p, DSTR_SUB(name));
	else if (((uint32_t)p->t.token_data) == TOKEN_SPACE)
		r = parse_instr(p, DSTR_SUB(name));
	else
		r = err_unexpected_token(p);
	ft_dstrclear(&name);
	return (true);
}

/*
** ========================================================================== **
** init
** => pre string
** => label or instr
*/

static bool			start_parsing(t_asm_parser *p)
{
	bool				r;

	while (ft_tokenize(&p->t))
	{
		if (((uint32_t)p->t.token_data) == TOKEN_SPACE
			|| (((uint32_t)p->t.token_data) == TOKEN_ENDL && ++p->line))
			r = true;
		else if (((uint32_t)p->t.token_data) == TOKEN_COMMENT)
			r = parse_comment(p);
		else if (((uint32_t)p->t.token_data) != TOKEN_UNKNOWN)
			r = err_unexpected_token(p);
		else if (SUB_EQU(p->t.token, SUBC(NAME_CMD_STRING)))
			r = parse_pre_string(p, &p->dst.name);
		else if (SUB_EQU(p->t.token, SUBC(COMMENT_CMD_STRING)))
			r = parse_pre_string(p, &p->dst.comment);
		else
			r = parse_label_or_instr(p);
		if (!r)
			return (false);
	}
	return (true);
}

bool				parse_asm(t_in *in, t_asm *dst, t_dstr *err)
{
	static t_token_map const	*map = NULL;
	t_asm_parser	p;
	bool			r;

	if (map == NULL)
		map = ft_token_map_build(&g_token_map);
	p = (t_asm_parser){
		TOKENIZER(in, map),
		(t_asm){
			DSTR0(),
			DSTR0(),
			VECTOR(t_instr),
			ft_hmapnew(20, &ft_djb2)
		},
		err,
		1
	};
	if (!(r = start_parsing(&p)))
		ft_asprintf(err, " at line %u", p.line);
	*dst = p.dst;
	ft_tokenizer_reset(&p.t, true);
	return (r);
}
