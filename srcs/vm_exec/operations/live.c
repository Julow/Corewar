/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:09:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/30 16:35:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static t_player const	*player_id_exists(t_vm const *vm, uint32_t player_id)
{
	uint32_t	i;

	i = 0;
	while (i < vm->player_count)
	{
		if (vm->players[i].id == player_id)
			return (&vm->players[i]);
		i++;
	}
	return (NULL);
}

bool					op_live(t_vm *vm, t_process *process,
							uint32_t const *args, uint8_t args_types)
{
	t_player const	*player;

	vm->nbr_live++;
	if ((player = player_id_exists(vm, args[0])) != NULL)
		vm->last_alive_player = args[0];
	LISTENER(vm, on_live, process, player);
	process->reg_pflags |= PFLAG_ALIVE;
	return (true);
	(void)args_types;
}
