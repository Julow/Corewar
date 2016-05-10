/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:40:42 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/10 18:40:43 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

uint32_t			get_value(t_vm const *vm, t_process *const process,
						uint32_t args, uint8_t arg_type)
{
	args_types = OCP_GET(args_types, index);
	if (args_types == REG_CODE)
		return (process->reg[args[index]]);
	else if (args_types == DIR_CODE)
		return (args[index]);
	else
		return (args[*process->reg_pc + index % IDX_MOD]);

}

uint32_t			get_lvalue(t_vm const *vm, t_process *const process,
						uint32_t args, uint8_t arg_type)
{
	args_types = OCP_GET(args_types, index);
	if (args_types == REG_CODE)
		return (process->reg[args[index]]);
	else if (args_types == DIR_CODE)
		return (args[index]);
	else
		return (args[*process->reg_pc + index]);
}