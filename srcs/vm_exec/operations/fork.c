/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:48 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/15 15:56:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static void		process_fork(t_vm *vm, t_process *process, uint32_t pc)
{
	t_process		*new_p;

	if (vm->players[process->player_idx].process_count >= MAX_PLAYER_PROCESS)
		return ;
	new_p = ft_listadd(&vm->process, process, 0);
	*new_p = PROCESS_INIT(pc, process->player_idx);
	ft_memcpy(new_p->reg, process->reg, sizeof(uint32_t[REG_NUMBER]));
	SET_CARRY(new_p, !(process->reg_pflags & PFLAG_CARRY));
	vm_wait_next(vm, new_p);
	vm->players[process->player_idx].process_count++;
	LISTENER(vm, on_fork, process, new_p);
}

bool			op_fork(t_vm *vm, t_process *process,
						uint32_t const *args, uint8_t args_types)
{
	process_fork(vm, process,
		(process->reg_pc + (((int32_t)args[0]) % IDX_MOD)) % MEM_SIZE);
	return (true);
	(void)args_types;
}

bool			op_lfork(t_vm *vm, t_process *process,
						uint32_t const *args, uint8_t args_types)
{
	process_fork(vm, process, (process->reg_pc + args[0]) % MEM_SIZE);
	return (true);
	(void)args_types;
}
