/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:11:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/10 17:11:58 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_and(t_vm *vm, uint32_t process_index, uint32_t const *args,
						uint8_t args_types)
{
	t_process *const		process = VECTOR_GET(vm->process, process_index);

	process->reg[args[2]] = get_value(process, args, args_type, 0)
							& get_value(process, args, args_type, 1);
	//modif carry
	return (true);
}
