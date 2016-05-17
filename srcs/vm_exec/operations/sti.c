/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:39 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/17 15:27:30 by jaguillo         ###   ########.fr       */
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

bool		op_sti(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t		val0;
	uint32_t		val1;
	uint32_t		val2;

	val0 = GET_VALUE(vm, process, args, args_types, 0);
	val1 = get_sti_value(vm, process, args[1], OCP_GET(args_types, 1));
	val2 = get_sti_value(vm, process, args[2], OCP_GET(args_types, 2));
	// val1 = GET_VALUE(vm, process, args, args_types, 1);
	// val2 = GET_VALUE(vm, process, args, args_types, 2);
	vm_set(vm, val2 + val1, val0, 4);
	return (true);
}
