/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/07 12:00:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_xor(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t		val;

	val = GET_VALUE(vm, process, args, args_types, 0)
			^ GET_VALUE(vm, process, args, args_types, 1);
	SET_CARRY(process, val);
	if (args[2] >= 1 && args[2] <= REG_NUMBER)
		process->reg[args[2] - 1] = val;
	return (true);
}
