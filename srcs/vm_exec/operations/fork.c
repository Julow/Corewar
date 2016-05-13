/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:48 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/13 12:39:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

#define FORK_OPCODE_LEN		3

bool		op_fork(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	t_process		*new_p;

	new_p = ft_listadd(&vm->process, NULL, 0);
	*new_p = PROCESS_INIT((process->reg_pc - FORK_OPCODE_LEN
							+ ((int32_t)args[0] % IDX_MOD)) % MEM_SIZE,
				process->player_idx);
	ft_memcpy(new_p->reg, process->reg, sizeof(uint32_t[REG_NUMBER]));
	SET_CARRY(new_p, process->reg_pflags & PFLAG_CARRY);
	return (true);
}
