/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 17:25:59 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/07 18:11:05 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_printf.h"
#include "ft/get_next_line.h"

#include "debug_ui.h"
#include "p_debug_ui.h"
#include "vm_exec.h"

#define BYTE_PER_LINE		64

void		dump_arena_n(t_vm const *vm, uint32_t index, uint32_t len)
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

void		dump_arena(t_vm const *vm, uint32_t mark)
{
	char const *const	arena = vm->arena;
	uint32_t			i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (mark >= i && mark < (i + BYTE_PER_LINE))
		{
			dump_arena_n(vm, i, mark - i);
			ft_printf("%s%.2hhx%s ", C_CYAN, C_RESET, arena[mark]);
			dump_arena_n(vm, mark + 1, BYTE_PER_LINE - (mark - i) - 1);
		}
		else
			dump_arena_n(vm, i, BYTE_PER_LINE);
		ft_printf("\n");
		i += BYTE_PER_LINE;
	}
	ft_printf("%!");
}

void		dump_process(t_vm const *vm, bool show_registers)
{
	t_process const	*process;
	uint32_t		i;

	process = LIST_IT(&vm->process);
	while ((process = LIST_NEXT(process)))
	{
		ft_printf("%#.8x: player: %u; wait: %u; pc: %u; pflags: %.02b\n",
			process, process->player_idx, process->wait,
			process->reg_pc, process->reg_pflags);
		i = 0;
		if (show_registers)
			while (i < REG_NUMBER)
			{
				ft_printf("    r%-2u -> r%-2u   "
					"%#.8x %#.8x %#.8x %#.8x\n", i + 1, i + 4,
					process->reg[i + 0], process->reg[i + 1],
					process->reg[i + 2], process->reg[i + 3]);
				i += 4;
			}
	}
	ft_printf("Process count: %u%n", vm->process.length);
}

void		dump_players(t_vm *vm)
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

void		dump_arena_focus(t_vm *vm, t_sub *line)
{
	uint32_t		mark;

	if (ft_subto_uint(SUB_FOR(*line, 2), &mark) > 0)
		dump_arena(vm, mark);
	//SEGFAULT HERE
}
