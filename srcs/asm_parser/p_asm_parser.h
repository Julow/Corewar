/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_asm_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:50:55 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/06 12:59:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_ASM_PARSER_H
# define P_ASM_PARSER_H

# include "asm_parser.h"

typedef struct s_asm_parser		t_asm_parser;

/*
** ========================================================================== **
*/

struct			s_asm_parser
{
	t_in			*in;
	t_asm			dst;
};

#endif
