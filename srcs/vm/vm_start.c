/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:52:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/30 14:48:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void			vm_wait_next(t_vm *vm, t_process *process)
{
	uint32_t const	op = VM_GET1(vm, process->reg_pc);

	process->wait = (op < 1 || op > OPCODE_COUNT) ? 0 : g_op_tab[op].duration - 1;
}

void			vm_start(t_vm *vm)
{
	uint32_t		i;
	t_process		*process;

	vm->clock = 0;
	vm->next_check = CYCLE_TO_DIE;
	vm->nbr_live = 0;
	vm->nbr_check = 0;
	vm->cycle_to_check = CYCLE_TO_DIE;
	i = 0;
	while (i < vm->player_count)
	{
		process = ft_listadd(&vm->process, vm->process.last, 0);
		*process = PROCESS_INIT(vm->players[i].arena_offset, i);
		process->reg[0] = vm->players[i].id;
		vm_wait_next(vm, process);
		i++;
	}
	vm->last_alive_player = vm->players[vm->player_count - 1].id;
}
