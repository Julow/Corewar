/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:11:32 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 12:38:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_st(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	vm->arena[process->reg_pc + GET_VALUE(vm, process, args, args_types, 1)] =
		GET_VALUE(vm, process, args, args_types, 0);
	return (true);
}
