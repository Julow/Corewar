/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:12:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 12:37:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_xor(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{	
	process->reg[args[2]] = GET_VALUE(vm, process, args, args_types, 1)
							^ GET_VALUE(vm, process, args, args_types, 0);
	//modif carry
	return (true);
}
