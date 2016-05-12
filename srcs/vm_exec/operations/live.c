/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:09:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 18:08:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static bool	player_id_exists(t_vm const *vm, uint32_t player_id)
{
	uint32_t	i;

	i = 0;
	while (i < vm->player_count)
		if (vm->players[i].id == player_id)
			return (true);
	return (false);
}

bool		op_live(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	uint32_t const	player_id = GET_VALUE(vm, process, args, args_types, 0);

	vm->nbr_live++;
	if (player_id_exists(vm, player_id))
		vm->last_alive_player = player_id;
	process->reg_pflags |= PFLAG_ALIVE;
	return (true);
}
