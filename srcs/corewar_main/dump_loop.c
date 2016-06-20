/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 15:18:21 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 19:27:42 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "main.h"

static void			dump_on_aff(t_vm *vm, t_process const *p, uint32_t val)
{
	t_player const *const	player = &vm->players[p->player_idx];

	ft_printf("The player %ts is so pimp he says : %d aka %c%n",
			DSTR_SUB(player->name), val, val % 256);
}


static void		dump_arena(uint8_t const *arena)
{
	uint32_t		i;
	uint32_t		to;

	i = 0;
	while (i < MEM_SIZE)
	{
		to = i + 32;
		while (true)
		{
			ft_printf("%.2hhx", arena[i]);
			if (i++ >= to)
			{
				ft_printf("%n");
				break ;
			}
			ft_printf(" ");
		}
	}
}

void			dump_loop(t_main *m)
{
	m->vm.listeners = (t_listeners){
		NULL,
		NULL,
		NULL,
		NULL,
		(m->flags & ARGV_F_AFF ? V(&dump_on_aff) : NULL),
		NULL,
		&m->vm
	};
	if (m->flags & ARGV_F_DUMP)
	{
		exec_loop(&m->vm, m->dump_cycles);
		ft_printf("Dump at clock %u:%n", m->vm.clock);
		dump_arena(m->vm.arena);
	}
	else
	{
		exec_loop(&m->vm, -1);
	}
}
