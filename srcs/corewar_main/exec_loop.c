/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 13:14:44 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 17:27:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "main.h"
#include "vm_exec.h"

static void		introduce(t_vm const *vm)
{
	uint32_t		i;
	t_player const	*p;

	ft_printf("Introducing contestants...%n");
	i = 0;
	while (i < vm->player_count)
	{
		p = &vm->players[i];
		ft_printf("* Player %d, weighing %u bytes, \"%ts\" yelling \"%ts\" !%n",
			p->id, p->weight, DSTR_SUB(p->name), DSTR_SUB(p->comment));
		i++;
	}
}

void			exec_loop(t_vm *vm, uint32_t max_clock)
{
	t_player const	*winner;

	introduce(vm);
	while (!VM_GAMEOVER(*vm))
	{
		if (vm->clock >= max_clock)
			return ;
		vm_exec(vm);
	}
	winner = &vm->players[vm->last_alive_player];
	ft_printf("Contestant %d, \"%ts\", has won !%n",
		winner->id, DSTR_SUB(winner->name));
}
