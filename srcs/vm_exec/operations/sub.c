/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:11:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/10 17:11:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_sub(t_vm *vm, uint32_t process_index, uint32_t const *args,
						uint8_t args_types)
{
	t_process *const		process = VECTOR_GET(vm->process, process_index);
	
	process->reg[args[2]] = GET_VALUE(vm, process, args, args_types, 1)
							- GET_VALUE(vm, process, args, args_types, 0);
	//modif carry
	return (true);
}
