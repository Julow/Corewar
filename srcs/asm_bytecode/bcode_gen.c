/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcode_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:52:50 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 18:24:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "p_asm_bytecode.h"

static void		bcode_encode(t_asm_bytecode *b,
					t_instr_arg const *args, uint32_t nb)
{
	uint8_t			code;
	uint32_t		i;

	code = 0;
	i = 0;
	while (i < nb)
	{
		if (args[i].e == INSTR_ARG_REG)
			code |= REG_CODE << ((MAX_ARGS_NUMBER - i - 1) * 2);
		else if (args[i].e == INSTR_ARG_DIR || args[i].e == INSTR_ARG_LABEL)
			code |= DIR_CODE << ((MAX_ARGS_NUMBER - i - 1) * 2);
		else if (args[i].e == INSTR_ARG_IND)
			code |= IND_CODE << ((MAX_ARGS_NUMBER - i - 1) * 2);
		else
			ASSERT(false);
		i++;
	}
	DSTR_APPEND(&b->bcode, code);
	b->offset++;
}

static void		label_locate(t_asm_bytecode *b, uint32_t i)
{
	while (b->next_label != NULL && b->next_label->index <= i)
	{
		HARD_ASSERT(b->next_label->index == i);
		ft_hmapput(b->labels_loc, b->next_label->name, &b->offset, sizeof(uint32_t));
		b->next_label = LIST_NEXT(b->next_label);
	}
}

void			bcode_gen(t_asm_bytecode *b, t_asm const *src)
{
	uint32_t		i;
	t_instr const	*instr;
	uint32_t		instr_begin;

	i = 0;
	while (i < src->instr.length)
	{
		instr = VECTOR_GET(src->instr, i);
		label_locate(b, i);
		instr_begin = b->offset;
		bcode_raw(b, instr->op->op_code, 1);
		if (instr->op->has_ocp)
			bcode_encode(b, instr->args, instr->arg_count);
		bcode_args(b, instr, instr_begin);
		i++;
	}
	label_locate(b, i);
	ASSERT(b->next_label == NULL);
}
