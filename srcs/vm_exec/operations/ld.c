/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:11:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 19:35:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_ld(t_vm *vm, t_process *process, uint32_t const *args,
					uint8_t args_types)
{
	uint32_t const	value = GET_VALUE(vm, process, args, args_types, 0);

	if (args[1] >= REG_NUMBER)
		return (true);
	process->reg[args[1]] = value;
	SET_CARRY(process, value);
	return (true);
}
