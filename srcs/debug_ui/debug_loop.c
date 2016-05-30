/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:16:12 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/30 16:25:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_printf.h"
#include "ft/get_next_line.h"

#include "debug_ui.h"
#include "vm_exec.h"

static void		dump_arena_n(t_vm const *vm, uint32_t index, uint32_t len)
{
	char const		*from;
	char const		*to;
	bool			shaded;

	shaded = false;
	from = vm->arena + index;
	to = from + len;
	while (from < to)
	{
		if ((*from == 0) != shaded)
			ft_printf((shaded = !shaded) ? C_GRAY : C_RESET);
		ft_printf("%.2hhx ", *from);
		from++;
	}
	if (shaded)
		ft_printf(C_RESET);
}

#define BYTE_PER_LINE		64

static void		dump_arena(t_vm const *vm, uint32_t mark)
{
	char const *const	arena = vm->arena;
	uint32_t			i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (mark >= i && mark < (i + BYTE_PER_LINE))
		{
			dump_arena_n(vm, i, mark - i);
			ft_printf(C_CYAN "%.2hhx " C_RESET, arena[mark]);
			dump_arena_n(vm, mark + 1, BYTE_PER_LINE - (mark - i) - 1);
		}
		else
			dump_arena_n(vm, i, BYTE_PER_LINE);
		ft_printf("\n");
		i += BYTE_PER_LINE;
	}
	ft_printf("%!");
}

// Move to module debug

static void		dump_process(t_vm const *vm, bool show_registers)
{
	t_process const	*process;
	uint32_t		i;

	process = LIST_IT(&vm->process);
	while ((process = LIST_NEXT(process)))
	{
		ft_printf("%#.8x: player: %u; wait: %u; pc: %u; pflags: %.02b\n",
			process, process->player_idx, process->wait, process->reg_pc, process->reg_pflags);
		i = 0;
		if (show_registers)
			while (i < REG_NUMBER)
			{
				ft_printf("    r%-2u -> r%-2u   %#.8x %#.8x %#.8x %#.8x\n", i + 1, i + 4,
					process->reg[i + 0], process->reg[i + 1], process->reg[i + 2], process->reg[i + 3]);
				i += 4;
			}
	}
	ft_printf("Process count: %u%n", vm->process.length);
}

void			debug_loop(t_vm *vm)
{
	{
		uint32_t		i;

		i = 0;
		while (i < vm->player_count)
		{
			ft_printf("player #%u; name: %ts, comment: %ts, offset: %u%n",
				vm->players[i].id, DSTR_SUB(vm->players[i].name),
				DSTR_SUB(vm->players[i].comment), vm->players[i].arena_offset);
			i++;
		}
	}

	{
		t_process const	*process;

		process = LIST_IT(&vm->process);
		while ((process = LIST_NEXT(process)))
			ft_printf("process; pidx: %u, pc: %u%n",
				process->player_idx, process->reg_pc);
	}

	while (!VM_GAMEOVER(*vm))
	{
		t_sub			line;
		uint32_t		tmp;

		tmp = 0;
		ft_printf("CLOCK %u: %!", vm->clock);
		if (get_next_line(0, &line) <= 0)
			tmp = -1;
		else if (SUB_EQU(line, SUBC("p")))
			dump_arena(vm, -1);
		else if (SUB_EQU(SUB(line.str, 2), SUBC("p ")))
		{
			uint32_t	mark;

			if (ft_subto_uint(SUB_FOR(line, 2), &mark) > 0)
				dump_arena(vm, mark);
		}
		else if (SUB_EQU(line, SUBC("pc")))
			dump_process(vm, false);
		else if (SUB_EQU(line, SUBC("pcr")))
			dump_process(vm, true);
		else if (line.length == 0)
			tmp = 1;
		else if (ft_subto_uint(line, &tmp) == 0)
			ASSERT(false, "Unknown command");

		while (tmp-- > 0 && !VM_GAMEOVER(*vm))
			vm_exec(vm);
	}

	dump_arena(vm, -1);
	ft_printf("CLOCK %u: GAME OVER, last alive player: %u%n", vm->clock, vm->last_alive_player);
}
