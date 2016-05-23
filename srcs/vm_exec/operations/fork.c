/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:48 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/23 19:03:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static uint32_t	player_process_count(t_vm const *vm, uint32_t player_idx)
{
	t_process const	*process;
	uint32_t		count;

	count = 0;
	process = LIST_IT(&vm->process);
	while ((process = LIST_NEXT(process)))
		if (process->player_idx == player_idx)
			count++;
	return (count);
}

static void		process_fork(t_vm *vm, t_process const *process, uint32_t pc)
{
	t_process		*new_p;

	if (player_process_count(vm, process->player_idx) >= MAX_PLAYER_PROCESS)
		return ;
	new_p = ft_listadd(&vm->process, process, 0);
	*new_p = PROCESS_INIT(pc, process->player_idx);
	ft_memcpy(new_p->reg, process->reg, sizeof(uint32_t[REG_NUMBER]));
	SET_CARRY(new_p, !(process->reg_pflags & PFLAG_CARRY));
	vm_wait_next(vm, new_p);
}

bool			op_fork(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	process_fork(vm, process,
		(process->reg_pc + (((int32_t)args[0]) % IDX_MOD)) % MEM_SIZE);
	return (true);
}

bool			op_lfork(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	process_fork(vm, process, (process->reg_pc + args[0]) % MEM_SIZE);
	return (true);
}
