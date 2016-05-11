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
						uint32_t argi, uint32_t opc)
{
	if (opc == REG_CODE)
		return (process->reg[args[index]]);
	else if (opc == DIR_CODE)
		return (args[index]);
	else
	{
		if (process->l)
			return (vm->arena[process->reg_pc + index]);
		else
			return (vm->arena[process->reg_pc + index % IDX_MOD]);
	}
}