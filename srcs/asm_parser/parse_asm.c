/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:55:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/07 19:21:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_asm_parser.h"

#define TOKEN_DEF(S,DATA)	((t_token_def){SUBC(S), V(DATA)})

static t_token_map const	*get_token_map(void)
{
	static t_token_map const	map = TOKEN_MAP();
	static bool					map_init = false;

	if (!map_init)
	{
		ft_token_map(&map, &TOKEN_DEF(" ", TOKEN_SPACE));
		ft_token_map(&map, &TOKEN_DEF("\t", TOKEN_SPACE));
		ft_token_map(&map, &TOKEN_DEF("\n", TOKEN_ENDL));
		ft_token_map(&map, &TOKEN_DEF("\"", TOKEN_QUOTE));
		ft_token_map(&map, &TOKEN_DEF("%", TOKEN_MODULO));
		ft_token_map(&map, &TOKEN_DEF("%:", TOKEN_LABEL));
		ft_token_map(&map, &TOKEN_DEF(";", TOKEN_COMMENT));
		ft_token_map(&map, &TOKEN_DEF("#", TOKEN_COMMENT));
		ft_token_map(&map, &TOKEN_DEF(":", TOKEN_COLON));
		map_init = true;
	}
	return (&map);
}

static bool			err_unexpected_token(t_asm_parser *p)
{
	ft_asprintf(p->err, "Unexpected token '%ts'", p->t.token);
	return (false);
}

/*
** ========================================================================== **
** Comment
*/

static t_token_map const	*get_comment_token_map(void)
{
	static t_token_map const	map = TOKEN_MAP();
	static bool					map_init = false;

	if (!map_init)
	{
		ft_token_map(&map, &TOKEN_DEF("\\\n", TOKEN_COMMENT_ESCAPED));
		ft_token_map(&map, &TOKEN_DEF("\n", TOKEN_COMMENT_ENDL));
		map_init = true;
	}
	return (&map);
}

static bool			parse_comment(t_asm_parser *p)
{
	t_token_map const *const	old_map = p->t.token_map;

	p->t.token_map = get_comment_token_map();
	while (ft_tokenize(&p->t))
		if (p->t.token_data == TOKEN_COMMENT_ENDL)
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

static t_token_map const	*get_string_token_map(void)
{
	static t_token_map const	map = TOKEN_MAP();
	static bool					map_init = false;

	if (!map_init)
	{
		ft_token_map(&map, &TOKEN_DEF("\\\"", TOKEN_STRING_ESCAPED));
		ft_token_map(&map, &TOKEN_DEF("\n", TOKEN_STRING_ENDL));
		ft_token_map(&map, &TOKEN_DEF("\"", TOKEN_STRING_QUOTE));
		map_init = true;
	}
	return (&map);
}

static bool			parse_string(t_asm_parser *p, t_dstr *dst)
{
	t_token_map const *const	old_map = p->t.token_map;

	p->t.token_map = get_comment_token_map();
	while (ft_tokenize(&p->t))
		if (p->t.token_data == TOKEN_COMMENT_ENDL)
			p->line++;
		else if (p->t.token_data == TOKEN_QUOTE)
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
		if (p->t.token_data == TOKEN_QUOTE)
			return (parse_string(p, dst));
		else if (p->t.token_data == TOKEN_ENDL)
			break ;
		else if (p->t.token_data != TOKEN_SPACE)
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
	if ((ft_hmapget(p->dst.labels)).value != NULL)
		return (ft_asprintf(p->err, "Label '%ts' redefined", name), false);
	ft_hmapputp(p->dst.labels, name, V(p->dst.instr.length));
	return (true);
}

/*
** ========================================================================== **
** instr arg
*/

static bool			parse_instr_arg_reg_ind(t_asm_parser *p, t_instr_arg *dst)
{
	return (true);
}

static bool			parse_instr_arg_dir(t_asm_parser *p, t_instr_arg *dst)
{
	return (true);
}

static bool			parse_instr_arg_label(t_asm_parser *p, t_instr_arg *dst)
{
	if (!ft_tokenize(&p->t))
		r = (ft_asprintf(p->err, "Unexpected end of file"), false);
	else if (p->t.token_data != TOKEN_UNKNOWN)
		; // TODO: finish
	return (true);
}

// TODO: new token map

static bool			parse_instr_arg(t_asm_parser *p, t_instr_arg *dst)
{
	if (!ft_tokenize(&p->t))
		r = (ft_asprintf(p->err, "Unexpected end of file"), false);
	else if (p->t.token_data == TOKEN_UNKNOWN)
		r = parse_instr_arg_reg_ind(p, dst);
	else if (p->t.token_data == TOKEN_MODULO)
		r = parse_instr_arg_dir(p, dst);
	else if (p->t.token_data == TOKEN_LABEL)
		r = parse_instr_arg_label(p, dst);
	else
		r = err_unexpected_token(p);
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
		r = parse_instr_arg(p, &instr->args[instr->arg_count]);
		instr->arg_count++;
		while (ft_tokenize(&p->t))
		{
			if (p->t.token_data == TOKEN_SPACE)
				continue ;
			else if (p->t.token_data == TOKEN_ENDL)
				return ((++p->line), true);
			else if (p->t.token_data == TOKEN_COMMENT)
				return (parse_comment(p));
			else if (p->t.token_data == TOKEN_COMMA)
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
	bool				r;
	uint32_t			opcode;
	t_instr				*instr;

	if (!get_opcode(name, &opcode))
		return (ft_asprintf(p->err, "Unknown instruction '%ts'", name), false);
	instr = ft_vpush(&p->dst.instr, NULL, 1);
	*instr = (t_instr){opcode, {0}, 0};
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
	else if (p->t.token_data == TOKEN_COLON)
		r = push_label(p, DSTR_SUB(name));
	else if (p->t.token_data == TOKEN_SPACE)
		r = parse_instr(p, DSTR_SUB(name));
	else
		r = err_unexpected_token(p);
	ft_dstrclear(&name);
	return (false);
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
		if (p->t.token_data == TOKEN_SPACE
			|| (p->t.token_data == TOKEN_ENDL && ++p->line))
			r = true;
		else if (p->t.token_data == TOKEN_COMMENT)
			r = parse_comment(p);
		else if (p->t.token_data != TOKEN_UNKNOWN)
			r = err_unexpected_token(p);
		else if (SUB_EQU(p->t.token, SUBC(NAME_CMD_STRING)))
			r = parse_pre_string(p, &p->dst.name);
		else if (SUB_EQU(p->t.token, SUBC(NAME_CMD_STRING)))
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
	t_asm_parser	p;
	bool			r;

	p = (t_asm_parser){
		TOKENIZER(in, get_token_map()),
		(t_asm){
			DSTR0(),
			DSTR0(),
			VECTOR(t_instr),
			ft_hmapnew(20, &ft_djb2)
		},
		err
	};
	if (!(r = start_parsing(&p)))
		ft_asprintf(p->err, " at line %u", p.line);
	*dst = p.dst;
	ft_tokenizer_reset(&p->t, true);
	return (r);
}
