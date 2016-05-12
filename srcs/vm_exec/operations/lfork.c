/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:13:07 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 12:38:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

bool		op_lfork(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	t_process		*new_p;
	uint32_t		value;

	value = GET_LVALUE(vm, process, args, args_types, 0);
	new_p = ft_listadd(&vm->process, 0, 0);
	*new_p = PROCESS_INIT(value, vm->players[process->player_idx].id,
		process->player_idx);
	return (true);
}
