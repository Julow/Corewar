/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:24:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 14:32:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "op.h"
#include "p_asm_parser.h"

static t_vector const	g_instr_token_map = VECTOR(t_token_def,
	TOKEN_DEF(" ", TOKEN_INSTR_SPACE),
	TOKEN_DEF("\t", TOKEN_INSTR_SPACE),
	TOKEN_DEF("\n", TOKEN_INSTR_ENDL),
	TOKEN_DEF(",", TOKEN_INSTR_COMMA),
	TOKEN_DEF("#", TOKEN_INSTR_COMMENT),
	TOKEN_DEF(";", TOKEN_INSTR_COMMENT),
	TOKEN_DEF("%", TOKEN_INSTR_MODULO),
	TOKEN_DEF("%:", TOKEN_INSTR_LABEL)
);

static bool			parse_instr_arg_list(t_asm_parser *p, t_instr *dst)
{
	while (true)
	{
		if (dst->arg_count >= dst->op->arg_n)
		{
			ft_asprintf(p->err, "Too many argument");
			return (false);
		}
		if (!parse_instr_arg(p, &dst->args[dst->arg_count]))
			return (false);
		dst->arg_count++;
		while (ft_tokenize(&p->t))
		{
			if (((uint32_t)p->t.token_data) == TOKEN_INSTR_SPACE)
				continue ;
			else if (((uint32_t)p->t.token_data) == TOKEN_INSTR_ENDL)
				return (BOOL_OF(++p->line));
			else if (((uint32_t)p->t.token_data) == TOKEN_INSTR_COMMENT)
				return (parse_comment(p));
			else if (((uint32_t)p->t.token_data) == TOKEN_INSTR_COMMA)
				break ;
			err_unexpected_token(p);
			ft_asprintf(p->err, ", expecting ','");
			return (false);
		}
	}
}

static const t_op	*get_opcode(t_sub name)
{
	uint32_t			i;
	t_sub				opname;

	i = 1;
	while (i <= OPCODE_COUNT)
	{
		opname = ft_sub(g_op_tab[i].name, 0, -1);
		if (SUB_EQU(opname, name))
			return (&g_op_tab[i]);
		i++;
	}
	return (NULL);
}

bool				parse_instr(t_asm_parser *p, t_sub name)
{
	static t_token_map const	*map = NULL;
	t_token_map const *const	old_map = p->t.token_map;
	t_instr						*instr;
	bool						r;

	if (map == NULL)
		map = ft_token_map_build(&g_instr_token_map);
	instr = ft_vpush(&p->dst.instr, NULL, 1);
	*instr = (t_instr){NULL, {{0, {0}}}, 0};
	if ((instr->op = get_opcode(name)) == NULL)
	{
		ft_asprintf(p->err, "Unknown instruction '%ts'", name);
		return (false);
	}
	p->t.token_map = map;
	r = parse_instr_arg_list(p, instr) && check_instr(p, instr, p->err);
	p->t.token_map = old_map;
	if (!r)
	{
		ft_asprintf(p->err, " (instruction %s)", instr->op->name);
		return (false);
	}
	return (r);
}
