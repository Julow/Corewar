/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 13:47:56 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 14:55:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr_loader.h"

#define NEXT_BYTE		bytecode[dst->length++]

static bool		load_opcode(t_instr *dst, uint8_t const *bytecode)
{
	uint8_t const	op_code = NEXT_BYTE;

	if (op_code < 1 || op_code > OPCODE_COUNT)
		return (false);
	dst->op = &g_op_tab[op_code];
	return (true);
}

static bool		load_ocp(t_instr *dst, uint8_t const *bytecode)
{
	uint32_t			i;
	uint32_t			type;

	if (dst->op->has_ocp)
	{
		dst->ocp = NEXT_BYTE;
		return (true);
	}
	i = 0;
	while (i < dst->op->arg_n)
	{
		if (dst->op->arg_types[i] == T_REG)
			type = REG_CODE;
		else if (dst->op->arg_types[i] == T_DIR)
			type = DIR_CODE;
		else if (dst->op->arg_types[i] == T_IND)
			type = IND_CODE;
		else
			ASSERT(false);
		dst->ocp |= type << (8 - (++i * 2));
	}
	return (true);
}

static bool		load_args(t_instr *dst, uint8_t const *bytecode)
{
	uint32_t		i;
	uint32_t		type;
	uint32_t		val;
	bool			ok;

	ok = true;
	i = 0;
	while (i < dst->op->arg_n)
	{
		type = ARG_TYPE(*dst, i);
		if (type == REG_CODE)
			val = NEXT_BYTE;
		else if (type == DIR_CODE && !dst->op->short_value)
			val = ((NEXT_BYTE << 24) | (NEXT_BYTE << 16)
					| (NEXT_BYTE << 8) | NEXT_BYTE);
		else if (type == 0)
			val = 0;
		else
			val = (int32_t)(int16_t)((NEXT_BYTE << 8) | NEXT_BYTE);
		if (!(dst->op->arg_types[i] & type))
			ok = false;
		dst->args[i++] = val;
	}
	return (ok);
}

bool			load_instr(t_instr *dst, void const *bytecode)
{
	*dst = (t_instr){NULL, {0}, 0, 0};
	return (load_opcode(dst, bytecode)
		&& load_ocp(dst, bytecode)
		&& load_args(dst, bytecode));
}
