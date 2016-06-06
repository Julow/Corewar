/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:55:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/06 13:05:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_asm_parser.h"

bool				parse_asm(t_in *in, t_asm *dst, t_dstr *err)
{
	t_asm_parser	p;

	p = (t_asm_parser){
		in,
		(t_asm){
			DSTR0(),
			DSTR0(),
			VECTOR(t_instr),
			ft_hmapnew(20, &ft_djb2)
		}
	};
	// ...

	*dst = p.dst;
	return (true);
}
