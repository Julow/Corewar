/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:09:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/21 14:42:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static uint32_t			player_id_exists(t_vm *vm, uint32_t player_id)
{
	uint32_t	i;

	i = 0;
	while (i < vm->player_count)
	{
		if (vm->players[i].id == player_id)
			break ;
		i++;
	}
	return (i);
}

bool					op_live(t_vm *vm, t_process *process,
							uint32_t const *args, uint8_t args_types)
{
	uint32_t		player_idx;
	t_player		*p;

	vm->nbr_live++;
	if ((player_idx = player_id_exists(vm, args[0])) < vm->player_count)
	{
		vm->last_alive_player = player_idx;
		process->last_player_idx = player_idx;
		p = &vm->players[player_idx];
		p->last_live = vm->clock;
		p->live_to_check++;
		LISTENER(vm, on_live, process, p);
	}
	process->reg_pflags |= PFLAG_ALIVE;
	return (true);
	(void)args_types;
}
