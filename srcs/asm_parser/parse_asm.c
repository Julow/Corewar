/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:55:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 17:27:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_list.h"
#include "ft/ft_printf.h"
#include "ft/set.h"

#include "p_asm_parser.h"

static t_vector const	g_token_map = VECTOR(t_token_def,
	TOKEN_DEF(" ", TOKEN_SPACE),
	TOKEN_DEF("\t", TOKEN_SPACE),
	TOKEN_DEF("\n", TOKEN_ENDL),
	TOKEN_DEF("\"", TOKEN_QUOTE),
	TOKEN_DEF(";", TOKEN_COMMENT),
	TOKEN_DEF("#", TOKEN_COMMENT),
	TOKEN_DEF(":", TOKEN_COLON)
);

static bool			push_label(t_asm_parser *p, t_sub name)
{
	t_label				*label;

	if (ft_set_cget(&p->dst.label_set, &name) != NULL)
	{
		ft_asprintf(p->err, "Label '%ts' redefined", name);
		return (false);
	}
	label = ft_listadd(&p->dst.label_list, p->dst.label_list.last, name.length);
	*label = (t_label){
		SET_HEAD(),
		SUB(ENDOF(label), name.length),
		p->dst.instr.length
	};
	ft_memcpy(ENDOF(label), name.str, name.length);
	ft_set_insert(&p->dst.label_set, label, &name);
	return (true);
}

static bool			parse_label_or_instr(t_asm_parser *p)
{
	t_dstr				name;
	bool				r;

	name = ft_aprintf("%ts", p->t.token);
	if (!ft_tokenize(&p->t))
		r = err_unexpected_eof(p);
	else if (((uint32_t)p->t.token_data) == TOKEN_COLON)
		r = push_label(p, DSTR_SUB(name));
	else if (((uint32_t)p->t.token_data) == TOKEN_SPACE)
		r = parse_instr(p, DSTR_SUB(name));
	else
		r = err_unexpected_token(p);
	ft_dstrclear(&name);
	return (r);
}

static bool			parse_command(t_asm_parser *p, t_dstr *dest, uint32_t maxl)
{
	t_dstr				str_name;
	bool				r;

	str_name = ft_aprintf("%ts", p->t.token);
	if (dest->length > 0)
	{
		ft_asprintf(p->err, "Redefined command");
		r = false;
	}
	else if ((r = parse_string(p, dest)) && dest->length > maxl)
	{
		ft_asprintf(p->err, "String too long: %d", dest->length);
		r = false;
	}
	if (!r)
		ft_asprintf(p->err, " (command %ts)", DSTR_SUB(str_name));
	ft_dstrclear(&str_name);
	return (r);
}

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
			r = parse_command(p, &p->dst.name, PROG_NAME_LENGTH);
		else if (SUB_EQU(p->t.token, SUBC(COMMENT_CMD_STRING)))
			r = parse_command(p, &p->dst.comment, COMMENT_LENGTH);
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
	t_asm_parser				p;
	bool						r;

	if (map == NULL)
		map = ft_token_map_build(&g_token_map);
	p = (t_asm_parser){
		TOKENIZER(in, map),
		(t_asm){
			DSTR0(),
			DSTR0(),
			VECTOR(t_instr),
			LIST(t_label),
			SET(&asm_label_cmp, 0)
		},
		err,
		1
	};
	if (!(r = start_parsing(&p) && check_labels(&p, err)))
		ft_asprintf(err, " at line %u", p.line);
	*dst = p.dst;
	ft_tokenizer_reset(&p.t, true);
	return (r);
}
