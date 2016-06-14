/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels_ref.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:57:56 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 18:31:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"

#include "p_asm_bytecode.h"
#include "utils.h"

static void		put_loc(t_dstr *bcode, uint32_t offset,
					int32_t loc, bool short_val)
{
	loc = short_val ? B16_REV(loc) : B32_REV(loc);
	ft_memcpy(bcode->str + offset, &loc, short_val ? 2 : 4);
}

void			labels_ref_solve(t_dstr *bcode, t_asm_bytecode const *b)
{
	t_label_ref const	*ref;
	uint32_t const		*loc;

	ref = VECTOR_IT(b->labels_ref);
	while (VECTOR_NEXT(b->labels_ref, ref))
	{
		loc = ft_hmapget(b->labels_loc, ref->name).value;
		HARD_ASSERT(loc != NULL);
		put_loc(bcode, ref->offset, *loc - ref->instr_begin, ref->short_value);
	}
}
