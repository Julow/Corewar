/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:27:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/30 16:07:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"
#include "vm_exec.h"

bool			vm_exec(t_vm *vm)
{
	t_process		*process;

	process = LIST_IT(&vm->process);
	vm->clock++;
	while ((process = LIST_NEXT(process)))
		if (process->wait > 0)
			process->wait--;
		else
		{
			exec_op(vm, process);
			vm_wait_next(vm, process);
		}
	return (vm->clock < vm->next_check || vm_check(vm));
}
