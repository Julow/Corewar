/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:37:35 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 20:41:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

#define ZJUMP_OPCODE_LEN	3

bool		op_zjmp(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	int16_t const	ind = GET_VALUE(vm, process, args, args_types, 0);

	if (process->reg_pflags & PFLAG_CARRY)
		process->reg_pc = (process->reg_pc - ZJUMP_OPCODE_LEN + (ind % IDX_MOD))
							% MEM_SIZE;
	return (true);
}
