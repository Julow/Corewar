/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 13:26:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 13:45:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTR_LOADER_H
# define INSTR_LOADER_H

# include "ft/libft.h"
# include "instr.h"

/*
** ========================================================================== **
*/

/*
** Load a instruction from 'bytecode'
** 'bytecode' should be at least MAX_OP_SIZE wide
** -
** Return false on error but correctly load 'dst'
*/
bool			load_instr(t_instr *dst, void const *bytecode);

#endif
