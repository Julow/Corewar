/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:52:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/21 17:09:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_data.h"

static void		destroy_instrs(t_vector *v)
{
	t_instr			*instr;
	uint32_t		i;

	instr = VECTOR_IT(*v);
	while ((VECTOR_NEXT(*v, instr)))
	{
		i = 0;
		while (i < instr->arg_count)
		{
			if (instr->args[i].e == INSTR_ARG_LABEL)
				ft_dstrclear(&instr->args[i].u.label);
			i++;
		}
	}
	ft_vclear(v);
}

static void		destroy_labels(t_asm *s)
{
	t_label			*label;

	label = LIST_IT(&s->label_list);
	while ((label = LIST_NEXT(label)))
	{
		ft_set_remove(&s->label_set, label);
		label = ft_listremove(&s->label_list, label);
	}
}

void			asm_destroy(t_asm *s)
{
	ft_dstrclear(&s->name);
	ft_dstrclear(&s->comment);
	destroy_instrs(&s->instr);
	destroy_labels(s);
}
