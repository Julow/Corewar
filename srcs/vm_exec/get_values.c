/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:40:42 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 16:49:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

uint32_t			get_value(t_vm const *vm, t_process *const process,
						uint32_t arg, uint32_t arg_type)
{
	if (arg_type == REG_CODE)
		return (process->reg[arg]);
	else if (arg_type == DIR_CODE)
		return (arg);
	else
		return (vm_get(vm, process->reg_pc + arg % IDX_MOD, 4));
}

uint32_t			get_lvalue(t_vm const *vm, t_process *const process,
						uint32_t arg, uint32_t arg_type)
{
	if (arg_type == IND_CODE)
		return (vm_get(vm, process->reg_pc + arg, 4));
	else
		return (get_value(vm, process, arg, arg_type));
}
