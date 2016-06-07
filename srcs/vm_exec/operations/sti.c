/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:39 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/07 12:01:11 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static int32_t	get_sti_value(t_vm const *vm, t_process *const process,
						int32_t arg, uint32_t arg_type)
{
	if (arg_type == REG_CODE)
		return ((arg < 1 || arg > REG_NUMBER) ? 0 : process->reg[arg - 1]);
	else
		return (arg);
	(void)vm;
}

bool			op_sti(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t		val0;
	int32_t			val1;
	int32_t			val2;
	int32_t			i;

	val0 = GET_VALUE(vm, process, args, args_types, 0);
	val1 = get_sti_value(vm, process, args[1], OCP_GET(args_types, 1));
	val2 = get_sti_value(vm, process, args[2], OCP_GET(args_types, 2));
	i = process->reg_pc + ((val2 + val1) % IDX_MOD);
	vm_set(vm, i, val0, 4);
	LISTENER(vm, on_write, process, VEC2U(i, 4));
	return (true);
}
