/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:54:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 18:10:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_asm_bytecode.h"
#include "utils.h"

void			asm_header(t_out *out,
					t_asm_bytecode const *b, t_asm const *src)
{
	t_header		header;

	ft_bzero(&header, sizeof(t_header));
	header.magic = B32_REV(COREWAR_EXEC_MAGIC);
	HARD_ASSERT(PROG_NAME_LENGTH >= src->name.length);
	ft_memcpy(header.prog_name, src->name.str, src->name.length);
	header.prog_size = B32_REV(b->offset);
	HARD_ASSERT(COMMENT_LENGTH >= src->comment.length);
	ft_memcpy(header.comment, src->comment.str, src->comment.length);
	ft_putsub(out, SUB((char*)&header, sizeof(t_header)));
}
