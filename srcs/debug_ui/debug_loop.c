/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:16:12 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 19:12:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/get_next_line.h"

#include "debug_ui.h"
#include "p_debug_ui.h"
#include "vm_exec.h"

static uint32_t	getch_com(t_vm *vm)
{
	uint32_t		tmp;
	t_sub			line;

	tmp = 0;
	if (get_next_line(0, &line) <= 0)
	{
		ft_printf("%n");
		tmp = -1;
	}
	else if (SUB_EQU(line, SUBC("p")))
		dump_arena(vm, -1);
	else if (SUB_EQU(SUB(line.str, 2), SUBC("p ")))
		dump_arena_focus(vm, &line);
	else if (SUB_EQU(line, SUBC("pc")))
		dump_process(vm, false);
	else if (SUB_EQU(line, SUBC("pcr")))
		dump_process(vm, true);
	else if (line.length == 0)
		tmp = 1;
	else if (ft_subto_uint(line, &tmp) == 0)
		ft_dprintf(2, "Unknown command '%s'\nHelp:\n\tp\tDump arena\n"
			"\tp <n>\tDump arena with the <n>th byte highlighted\n"
			"\tpc\tDump processes\n\tpcr\tDump processes with their registers\n"
			"\t<t>\tRun <t> ticks\n", line);
	return (tmp);
}

void			debug_loop(t_vm *vm, uint32_t dump_cycles)
{
	uint32_t		tmp;
	t_player const	*p;

	dump_players(vm);
	if (dump_cycles != (uint32_t)-1)
	{
		while (!VM_GAMEOVER(*vm) && vm->clock < dump_cycles)
			vm_exec(vm);
		dump_arena(vm, -1);
	}
	while (!VM_GAMEOVER(*vm))
	{
		ft_printf("CLOCK %u: %!", vm->clock);
		tmp = getch_com(vm);
		while (tmp-- > 0 && !VM_GAMEOVER(*vm))
			vm_exec(vm);
	}
	ft_printf("CLOCK %u: END%n", vm->clock);
	dump_arena(vm, -1);
	p = &vm->players[vm->last_alive_player];
	ft_printf("Contestant %d, \"%ts\", has won !%n", p->id, DSTR_SUB(p->name));
}
