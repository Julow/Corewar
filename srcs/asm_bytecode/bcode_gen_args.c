/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcode_gen_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:53:33 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 18:27:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_asm_bytecode.h"

static void		bcode_arg_dir(t_asm_bytecode *b,
					t_instr const *instr, uint32_t dir)
{
	if (instr->op->short_value)
		bcode_raw(b, (uint32_t)(int16_t)dir, 2);
	else
		bcode_raw(b, (uint32_t)(int32_t)dir, 4);
}

static void		bcode_arg_label(t_asm_bytecode *b, t_instr const *instr,
					t_dstr const *name, uint32_t instr_begin)
{
	t_label_ref *const	ref = ft_vpush(&b->labels_ref, NULL, 1);

	*ref = (t_label_ref){b->offset, instr_begin, DSTR_SUB(*name), instr->op->short_value};
	bcode_arg_dir(b, instr, 0);
}

void			bcode_args(t_asm_bytecode *b,
					t_instr const *instr, uint32_t instr_begin)
{
	uint32_t		i;

	i = 0;
	while (i < instr->arg_count)
	{
		if (instr->args[i].e == INSTR_ARG_REG)
			bcode_raw(b, (uint32_t)(uint8_t)instr->args[i].u.reg, 1);
		else if (instr->args[i].e == INSTR_ARG_DIR)
			bcode_arg_dir(b, instr, instr->args[i].u.dir);
		else if (instr->args[i].e == INSTR_ARG_IND)
			bcode_raw(b, (uint32_t)(int16_t)instr->args[i].u.ind, 2);
		else if (instr->args[i].e == INSTR_ARG_LABEL)
			bcode_arg_label(b, instr, &instr->args[i].u.label, instr_begin);
		else
			ASSERT(false);
		i++;
	}
}
