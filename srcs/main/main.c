/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:28:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 20:34:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "main.h"
#include "parse_argv.h"
#include "vm.h"
#include "vm_exec.h"

// #include "vm_exec.h"
#include "vm_loader.h"

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

	ft_printf("%ts%n", SUB(m.vm.arena, MEM_SIZE));

	while (!VM_GAMEOVER(m.vm))
	{
		ft_printf("CLOCK %u%n", m.vm.clock);
		vm_exec(&m.vm);
		if (m.vm.clock > 50)
			break ;
	}
	if (VM_GAMEOVER(m.vm))
		ft_printf("GAME OVER%n");

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
