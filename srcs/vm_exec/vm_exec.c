/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:27:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/15 15:21:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"
#include "vm_exec.h"

static void		wait_next(t_vm *vm, t_process *process)
{
	uint32_t const	op = VM_GET1(vm, process->reg_pc);

	process->wait = (op < 1 || op > OPCODE_COUNT) ?
		0 : g_op_tab[op].duration - 1;
}

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
			wait_next(vm, process);
		}
	return (vm->clock < vm->next_check || vm_check(vm));
}
