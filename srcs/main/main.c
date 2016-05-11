/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:28:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 16:26:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "parse_argv.h"
#include "vm.h"

// #include "vm_exec.h"
#include "vm_loader.h"

int				main(int argc, char **argv)
{
	t_main			m;

	if (!parse_argv(&m, argc, argv))
		return (1);

	ft_printf("flags: %b\n"
		"dump cycles: %u%n",
		m.flags, m.dump_cycles);

	{
		uint32_t		i;

		i = 0;
		while (i < m.vm.player_count)
		{
			ft_printf("player #%u; name: %ts, comment: %ts%n",
				m.vm.players[i].player_id, DSTR_SUB(m.vm.players[i].name),
				DSTR_SUB(m.vm.players[i].comment));
			i++;
		}
	}
	ft_printf("%ts%n", SUB(m.vm.arena, MEM_SIZE));

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
