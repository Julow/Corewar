/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:28:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/16 18:22:28 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "main.h"
#include "parse_argv.h"
#include "vm.h"
#include "vm_exec.h"

// #include "vm_exec.h"
#include "ft/getkey.h"
#include "vm_loader.h"

static void		dump_arena(t_vm const *vm)
{
	char const *const	arena = vm->arena;
	uint32_t			i;
	uint32_t			j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = 0;
		while (j < 64)
		{
			ft_printf("%.2hhx ", arena[j + i]);
			j++;
		}
		ft_printf("%n");
		i += j;
	}
}

int				main(int argc, char **argv)
{
	t_main			m;

	if (!parse_argv(&m, argc, argv))
		return (1);

	vm_start(&m.vm);

	ft_printf("flags: %b\n"
		"dump cycles: %u%n",
		m.flags, m.dump_cycles);

	{
		uint32_t		i;

		i = 0;
		while (i < m.vm.player_count)
		{
			ft_printf("player #%u; name: %ts, comment: %ts, offset: %u%n",
				m.vm.players[i].id, DSTR_SUB(m.vm.players[i].name),
				DSTR_SUB(m.vm.players[i].comment), m.vm.players[i].arena_offset);
			i++;
		}
	}

	{
		t_process const	*process;

		process = LIST_IT(&m.vm.process);
		while ((process = LIST_NEXT(process)))
			ft_printf("process; pidx: %u, pc: %u%n",
				process->player_idx, process->reg_pc);
	}

	while (!VM_GAMEOVER(m.vm))
	{

		ft_printf("\n\n\tCLOCK: %u\n", m.vm.clock);
		dump_arena(&m.vm);
		ft_getkey(0);

		// ft_printf("CLOCK %u%n", m.vm.clock);
		vm_exec(&m.vm);
		// if (m.vm.clock > 1000)
			// break ;
	}
	dump_arena(&m.vm);
	if (VM_GAMEOVER(m.vm))
		ft_printf("GAME OVER, last alive player: %u%n", m.vm.last_alive_player);

	// while (!(vm.flags & VM_F_GAMEOVER))
	// {
	// 	vm_exec(&vm);
	// 	if (ui != NULL)
	// 		ui_update(ui);
	// 	if (vm.clock >= corewar.dump_clock)
	// 		...
	// }

	return (0);
}
