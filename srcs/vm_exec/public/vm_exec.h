/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:11:48 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/30 16:09:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_EXEC_H
# define VM_EXEC_H

# include "ft/libft.h"
# include "vm.h"

/*
** ========================================================================== **
** VM Exec
*/

/*
** Exec a clock
*/
bool			vm_exec(t_vm *vm);

/*
** Check vm state: dead process, game over
*/
bool			vm_check(t_vm *vm);

#endif
