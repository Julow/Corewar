/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:56:55 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 17:29:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_asm_bytecode.h"

void			bcode_raw(t_asm_bytecode *b, uint32_t data, uint32_t len)
{
	b->offset += len;
	while (len-- > 0)
		DSTR_APPEND(&b->bcode, (data >> (len * 8)) & 0xFF);
}
