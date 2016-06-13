/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instr_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:26:10 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/13 15:23:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_asm_parser.h"

static bool			parse_instr_arg_ind(t_asm_parser *p, t_instr_arg *dst)
{
	t_sub const			ind = SUB_FOR(p->t.token, 1);

	dst->e = INSTR_ARG_IND;
	if (ind.length == 0 || ft_subto_int(ind, &dst->u.ind) != ind.length)
	{
		ft_asprintf(p->err, "Invalid identifier: '%ts'", p->t.token);
		return (false);
	}
	return (true);
}

static bool			parse_instr_arg_reg(t_asm_parser *p, t_instr_arg *dst)
{
	t_sub const			reg = SUB_FOR(p->t.token, 1);

	dst->e = INSTR_ARG_REG;
	if (reg.length == 0 || ft_subto_uint(reg, &dst->u.reg) != reg.length)
	{
		ft_asprintf(p->err, "Invalid identifier: '%ts'", p->t.token);
		return (false);
	}
	if (dst->u.reg > REG_NUMBER || dst->u.reg < 1)
	{
		ft_asprintf(p->err, "Invalid register r%u%n", dst->u.reg);
		return (false);
	}
	return (true);
}

static bool			parse_instr_arg_dir(t_asm_parser *p, t_instr_arg *dst)
{
	if (!ft_tokenize(&p->t))
		return (err_unexpected_eof(p));
	if (((uint32_t)p->t.token_data) != TOKEN_INSTR_UNKNOWN)
		return (err_unexpected_token(p));
	dst->e = INSTR_ARG_DIR;
	if (ft_subto_int(p->t.token, &dst->u.ind) != p->t.token.length)
	{
		ft_asprintf(p->err, "Invalid value: '%ts'", p->t.token);
		return (false);
	}
	return (true);
}

static bool			parse_instr_arg_label(t_asm_parser *p, t_instr_arg *dst)
{
	if (!ft_tokenize(&p->t))
		return (err_unexpected_eof(p));
	if (((uint32_t)p->t.token_data) != TOKEN_INSTR_UNKNOWN)
		return (err_unexpected_token(p));
	dst->e = INSTR_ARG_LABEL;
	dst->u.label = ft_aprintf("%ts", p->t.token);
	return (true);
}

bool				parse_instr_arg(t_asm_parser *p, t_instr_arg *dst)
{
	while (true)
	{
		if (!ft_tokenize(&p->t))
			return (err_unexpected_eof(p));
		else if (((uint32_t)p->t.token_data) != TOKEN_INSTR_SPACE)
			break ;
	}
	if (((uint32_t)p->t.token_data) == TOKEN_INSTR_UNKNOWN)
		return ((p->t.token.str[0] == 'r') ?
				parse_instr_arg_reg(p, dst) : parse_instr_arg_ind(p, dst));
	else if (((uint32_t)p->t.token_data) == TOKEN_INSTR_MODULO)
		return (parse_instr_arg_dir(p, dst));
	else if (((uint32_t)p->t.token_data) == TOKEN_INSTR_LABEL)
		return (parse_instr_arg_label(p, dst));
	return (err_unexpected_token(p));
}
