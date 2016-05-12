/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:11:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 19:37:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_and(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	process->reg[args[2]] = GET_VALUE(vm, process, args, args_types, 1)
							& GET_VALUE(vm, process, args, args_types, 0);
	SET_CARRY(process, process->reg[args[2]]);
	return (true);
}
