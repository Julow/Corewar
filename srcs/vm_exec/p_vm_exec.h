/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_vm_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:18:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/10 16:17:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "vm_exec.h"

/*
** ========================================================================== **
*/

/*
** op
** -
** vm			=> current vm
** process		=> current process index
** args			=> unpacked arguments
** ocp			=> arguments types
*/
typedef void	(*t_op_f)(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);

/*
** Return the type of the Ith arg
*/
# define OCP_GET(OCP, I)	((OCP << (8 - ((I + 1) * 2))) & 0b11)

/*
** Exec the next instruction of the process at index process_index
*/
bool			exec_op(t_vm *vm, uint32_t process_index);

#endif
