/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:24:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/13 13:31:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "op.h"
#include "p_asm_parser.h"

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

bool				parse_instr(t_asm_parser *p, t_sub name)
{
	uint32_t			opcode;
	t_instr				*instr;

	if (!get_opcode(name, &opcode))
		return (ft_asprintf(p->err, "Unknown instruction '%ts'", name), false);
	instr = ft_vpush(&p->dst.instr, NULL, 1);
	*instr = (t_instr){opcode, {{0, {0}}}, 0};
	return (parse_instr_arg_list(p, instr));
}
