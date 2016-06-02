/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:07:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/02 14:55:03 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"
#include "vm_exec.h"

static bool		vm_check_alive(t_vm *vm)
{
	t_process		*process;

	process = LIST_IT(&vm->process);
	while ((process = LIST_NEXT(process)))
		if (!(process->reg_pflags & PFLAG_ALIVE))
		{
			LISTENER(vm, on_die, process);
			process = ft_listremove(&vm->process, process);
		}
		else
			process->reg_pflags &= ~PFLAG_ALIVE;
	return (vm->process.length > 0);
}

static void		vm_check_player(t_vm *vm)
{
	uint32_t		i;

	i = 0;
	while (i < vm->player_count)
	{
		vm->players[i].live_to_check = 0;
		i++;
	}
}

bool			vm_check(t_vm *vm)
{
	if (!vm_check_alive(vm))
	{
		vm->flags |= VM_F_GAMEOVER;
		return (false);
	}
	vm_check_player(vm);
	vm->nbr_check++;
	if (vm->nbr_live >= NBR_LIVE || vm->nbr_check >= MAX_CHECKS)
	{
		vm->cycle_to_check = (vm->cycle_to_check > CYCLE_DELTA) ?
			 vm->cycle_to_check - CYCLE_DELTA : 0;
		vm->nbr_check = 0;
	}
	vm->next_check = vm->clock + vm->cycle_to_check;
	vm->nbr_live = 0;
	return (true);
}
