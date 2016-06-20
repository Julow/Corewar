/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 13:27:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 15:06:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTR_H
# define INSTR_H

# include "ft/libft.h"
# include "op.h"

typedef struct s_instr		t_instr;

/*
** ========================================================================== **
** Instruction
** -
** TODO: fix name collision with asm_parser::t_instr
*/

/*
** op			=> ptr to corewar_config op
** args			=> array of params
** ocp			=> params types
** length		=> size in byte of the instruction
*/

struct			s_instr
{
	t_op const		*op;
	uint32_t		args[MAX_ARGS_NUMBER];
	uint8_t			ocp;
	uint16_t		length;
};

/*
** Return the type (REG_CODE | DIR_CODE | IND_CODE) of the argument I
*/
# define ARG_TYPE(INSTR, I)		(((INSTR).ocp >> (8 - (((I) + 1) * 2))) & 0b11)

#endif
