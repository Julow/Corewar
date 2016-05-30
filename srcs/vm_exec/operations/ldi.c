/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:26 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/30 15:04:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static int32_t	get_sti_value(t_vm const *vm, t_process *const process,
						int32_t arg, uint32_t arg_type)
{
	if (arg_type == REG_CODE)
		return ((arg < 1 || arg > REG_NUMBER) ? 0 : process->reg[arg - 1]);
	return (arg);
	(void)vm;
}

bool		op_ldi(t_vm *vm, t_process *process,
						uint32_t const *args, uint8_t args_types)
{
	int32_t const	v1 = get_sti_value(vm, process, args[0], OCP_GET(args_types, 0));
	int32_t const	v2 = get_sti_value(vm, process, args[1], OCP_GET(args_types, 1));
	uint32_t const	value = vm_get(vm, process->reg_pc + (v1 + v2) % IDX_MOD, 4);

	SET_CARRY(process, value);
	if (args[2] >= 1 && args[2] <= REG_NUMBER)
		process->reg[args[2] - 1] = value;
	return (true);
}
