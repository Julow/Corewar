/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:55:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/10 17:25:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_bytecode.h"
#include "op.h"

static bool		bcode_str(t_out *out, t_dstr const *dstr, uint32_t len)
{
	ft_fprintf(out, "%ts%.*c", DSTR_SUB(dstr), len - name->length, '\0');
	return (true);
}

static bool		bcode_encode(t_out *out, t_instr_arg *arg, uint32_t nb)
{
	uint8_t			code;

	code = 0;
	while (i++ < nb)
	{
		if (arg->e == INSTR_ARG_REG)
				code |= 0b01;
		else if (arg->e == INSTR_ARG_DIR)
			code |= 0b10;
		else if (arg->e == INSTR_ARG_IND)
			code |= 0b11;
		code <<= 2;
	}
	ft_fprintf(out, "%c", code);
	return (true)
}

static bool		instr_to_byte(t_out *out, t_instr_arg *arg, uint32_t len)
{
	uint32_t		byte;

	if (arg->e == INSTR_ARG_REG)
		byte = (uint32_t)((uint8_t)arg->u.reg);
	else if (arg->e == INSTR_ARG_IND)
		byte = (uint32_t)(int16_t)arg->u.ind;
	else
		byte = (uint32_t)(int16_t)arg->u.dir;
	while (len-- > 0)
	{
		ft_fprintf(out, "%c", byte & 0b01);
		byte <<= 2;
	}
}

static bool		bcode_instr(t_out *out, t_instr const *instr)
{
	uint32_t		i;

	if (g_op_tab[instr->opc]->has_ocp)
		bcode_encode(out, instr->args, instr->arg_count);
	i = 0;
	while (i < instr.arg_count)
	{
		if (instr->args[i]->e == INSTR_ARG_REG
			|| instr->args[i]->e == INSTR_ARG_DIR
			||(instr->args[i]->e == INSTR_ARG_IND
				&& g_op_tab[instr.opc]->short_value))
			instr_to_byte(out, instr->args[i], 2);
		else
			instr_to_byte(out, instr->args[i], 4);
		i++;
	}
	return (true);
}

bool			bytecode_asm(t_out *out, t_asm const *asm)
{
	uint32_t		i;

	bcode_str(out, asm->name, PROG_NAME_LENGTH);
	bcode_comment(out, asm->comment, COMMENT_LENGTH);
	i = 0;
	while (i < asm->instr.length)
	{
		bcode_instr(out, VECTOR_GET(asm->instr, i));
		i++;
	}
}
