/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:39 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 12:37:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_sti(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t		val0;
	uint32_t		val1;
	uint32_t		val2;

	val0 = GET_VALUE(vm, process, args, args_types, 0);
	val1 = GET_VALUE(vm, process, args, args_types, 1);
	val2 = GET_VALUE(vm, process, args, args_types, 2);
	vm_set(vm, process->reg_pc + val2 + val1, val0, 4);
	return (true);
}
