/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bytecode.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:15:31 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/08 18:23:23 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_BYTECODE_H
# define ASM_BYTECODE_H

# include "ft/ft_dstr.h"
# include "ft/ft_out.h"

# include "asm_data.h"

/*
** ========================================================================== **
*/

bool			bytecode_asm(t_out *out, t_asm const *asm);

#endif
