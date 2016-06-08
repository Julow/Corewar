/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:55:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/08 19:03:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_bytecode.h"
#include "op.h"

static bool		bcode_str(t_out *out, t_dstr const *dstr, uint32_t len)
{
	ft_fprintf(out, "%ts%.*c", DSTR_SUB(dstr), len - name->length, '\0');
	return (true);
}

static bool		bcode_encode(t_out *out, t_instr_arg *arg)
{
	uint8_t			code;


	return (code)
}

static bool		bcode_instr(t_out *out, t_asm const *asm)
{
	uint32_t		i;

	if (g_op_tab[asm->instr.opc]->has_ocp)
		bcode_encode(out, asm->instr.args);
	i = 0;
	while (i < asm->instr.arg_count)
	{
		ft_fprintf(out, "%c", asm->instr.args[i]);
		i++;
	}
	return (true);
}

bool			bytecode_asm(t_out *out, t_asm const *asm)
{
	bcode_str(out, asm->name, PROG_NAME_LENGTH);
	bcode_comment(out, asm->comment, COMMENT_LENGTH);
}
