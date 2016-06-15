/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 13:14:44 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/15 15:21:27 by jaguillo         ###   ########.fr       */
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
			i + 1, p->weight, DSTR_SUB(p->name), DSTR_SUB(p->comment));
		i++;
	}
}

void			dump_loop(t_vm *vm)
{
	introduce(vm);
	while (!VM_GAMEOVER(*vm))
		vm_exec(vm);
	ft_printf("Contestant %d, \"%ts\", has won !%n",
		vm->last_alive_player + 1,
		DSTR_SUB(vm->players[vm->last_alive_player].name));
}
