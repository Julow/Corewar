/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:13:00 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 19:38:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_lldi(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t const	v1 = GET_LVALUE(vm, process, args, args_types, 0);
	uint32_t const	v2 = GET_LVALUE(vm, process, args, args_types, 1);

	if (args[1] >= REG_NUMBER)
		return (true);
	process->reg[args[2]] = vm_get(vm, v1 + v2, 4);
	SET_CARRY(process, process->reg[args[2]]);
	return (true);
}
