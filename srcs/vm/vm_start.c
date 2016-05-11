/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:52:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 19:08:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void			vm_start(t_vm *vm)
{
	uint32_t		i;
	t_player const	*player;
	t_process		process;

	vm->clock = 0;
	vm->next_check = CYCLE_TO_DIE;
	vm->nbr_live = 0;
	vm->nbr_check = 0;
	vm->cycle_to_check = CYCLE_TO_DIE;
	i = 0;
	while (i < vm->player_count)
	{
		player = &vm->players[i];
		process = PROCESS_INIT(player->arena_offset, player->id, i);
		ft_vpush(&vm->process, &process, 1);
		i++;
	}
}
