/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:37:35 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/30 14:06:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

#define ZJMP_OP_LENGTH		3

bool		op_zjmp(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	if (process->reg_pflags & PFLAG_CARRY)
	{
		process->reg_pc = (process->reg_pc + (((int32_t)args[0]) % IDX_MOD)
				- ZJMP_OP_LENGTH + MEM_SIZE) % MEM_SIZE;
	}
	return (true);
	(void)vm;
	(void)args_types;
}
