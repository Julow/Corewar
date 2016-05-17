/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:53 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/17 17:36:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_lld(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t const	value = GET_LVALUE(vm, process, args, args_types, 0);

	SET_CARRY(process, value);
	if (args[1] >= 1 && args[1] <= REG_NUMBER)
		process->reg[args[1] - 1] = value;
	return (true);
}
