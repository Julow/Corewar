/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:27:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 20:04:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"
#include "vm_exec.h"

static bool		vm_check_alive(t_vm *vm)
{
	t_process		*process;

	process = LIST_IT(&vm->process);
	while ((process = LIST_NEXT(process)))
		if (!(process->reg_pflags & PFLAG_ALIVE))
			process = ft_listremove(&vm->process, process);
	return (vm->process.length > 0);
}

static bool		vm_check(t_vm *vm)
{
	if (!vm_check_alive(vm))
	{
		vm->flags |= VM_F_GAMEOVER;
		return (false);
	}
	vm->nbr_check++;
	if (vm->nbr_live >= NBR_LIVE || vm->nbr_check >= MAX_CHECKS)
	{
		vm->cycle_to_check -= CYCLE_DELTA;
		vm->nbr_check = 0;
	}
	vm->next_check = vm->clock + vm->cycle_to_check;
	vm->nbr_live = 0;
	return (true);
}

bool			vm_exec(t_vm *vm)
{
	t_process		*process;

	process = LIST_IT(&vm->process);
	vm->clock++;
	while ((process = LIST_NEXT(process)))
		if (process->wait > 0)
			process->wait--;
		else if (!exec_op(vm, process))
			return (false);
		else
		{
			//Todo : wait
		}
	return (vm->clock != vm->next_check || vm_check(vm));
}
