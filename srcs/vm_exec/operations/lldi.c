/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:13:00 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/17 17:32:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_lldi(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t const	v1 = GET_LVALUE(vm, process, args, args_types, 0);
	uint32_t const	v2 = GET_LVALUE(vm, process, args, args_types, 1);
	uint32_t const	val = vm_get(vm, v1 + v2, 4);

	SET_CARRY(process, val);
	if (args[2] >= 1 && args[2] <= REG_NUMBER)
		process->reg[args[2] - 1] = val;
	return (true);
}
