/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:11:32 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/17 19:53:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_st(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t		val1;

	val1 = GET_VALUE(vm, process, args, args_types, 0);
	if (OCP_GET(args_types, 1) == IND_CODE)
		vm_set(vm, process->reg_pc + (((int32_t)args[1]) % IDX_MOD), val1, 4);
	else if (OCP_GET(args_types, 1) == REG_CODE)
	{
		if (args[1] >= 1 && args[1] <= REG_NUMBER)
			process->reg[args[1] - 1] = args[val1];
	}
	else
		return (ASSERT(false));
	return (true);
}
