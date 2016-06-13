/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:54:23 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/13 19:04:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_asm_parser.h"

bool			check_labels(t_asm_parser const *p, t_dstr *err)
{
	t_instr const	*instr;
	t_sub			label;
	uint32_t		i;

	instr = VECTOR_IT(p->dst.instr);
	while (VECTOR_NEXT(p->dst.instr, instr))
	{
		i = 0;
		while (i < instr->arg_count)
		{
			if (instr->args[i].e == INSTR_ARG_LABEL)
			{
				label = DSTR_SUB(instr->args[i].u.label);
				if (ft_hmapget(p->dst.labels, label).key == NULL)
				{
					ft_asprintf(err, "Missing label %ts", label);
					return (false);
				}
			}
			i++;
		}
	}
	return (true);
}
