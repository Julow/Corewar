/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:26 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/17 17:53:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static uint32_t	get_sti_value(t_vm const *vm, t_process *const process,
						uint32_t arg, uint32_t arg_type)
{
	if (arg_type == REG_CODE)
		return ((arg < 1 || arg > REG_NUMBER) ? 0 : process->reg[arg - 1]);
	else if (arg_type == DIR_CODE)
		return (arg);
	else
		return (process->reg_pc + arg % IDX_MOD);
}

bool		op_ldi(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t const	v1 = GET_VALUE(vm, process, args, args_types, 0);
	uint32_t const	v2 = GET_VALUE(vm, process, args, args_types, 1);
	// uint32_t const	v1 = get_sti_value(vm, process, args[0], OCP_GET(args_types, 0));
	// uint32_t const	v2 = get_sti_value(vm, process, args[1], OCP_GET(args_types, 1));
	uint32_t const	value = vm_get(vm, v1 + v2, 4);

	SET_CARRY(process, value);
	if (args[2] >= 1 && args[2] <= REG_NUMBER)
		process->reg[args[2] - 1] = value;
	return (true);
}
