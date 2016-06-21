/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:55:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/21 17:09:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "asm_bytecode.h"
#include "op.h"
#include "p_asm_bytecode.h"

static void		bcode_destroy(t_asm_bytecode *b)
{
	ft_dstrclear(&b->bcode);
	ft_vclear(&b->labels_ref);
	ft_hmapdestroy(b->labels_loc, NULL);
}

bool			bytecode_asm(t_out *out, t_asm const *src)
{
	t_asm_bytecode	b;

	b = (t_asm_bytecode){
		DSTR0(),
		0,
		VECTOR(t_label_ref),
		src->label_list.first,
		ft_hmapnew(20, &ft_djb2)
	};
	bcode_gen(&b, src);
	labels_ref_solve(&b.bcode, &b);
	asm_header(out, &b, src);
	ft_putsub(out, DSTR_SUB(b.bcode));
	ft_flush(out);
	bcode_destroy(&b);
	return (true);
}
