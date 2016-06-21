/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:18:11 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/21 14:59:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_arena.h"

static t_player_color const	g_player_colors[] = {
	{1, false},
	{2, true},
	{3, true},
	{4, true},
	{5, true},
};

static void		update_byte(t_w_arena *w, uint32_t i,
					uint8_t owner, bool reverse)
{
	wattron(w->w, COLOR_PAIR(g_player_colors[owner].pair_id));
	if (g_player_colors[owner].bold != 0 && !reverse)
		wattron(w->w, A_BOLD);
	else
		wattroff(w->w, A_BOLD);
	if (reverse)
		wattron(w->w, A_REVERSE);
	mvwprintw(w->w, i / ARENA_WIDTH + 1, (i % ARENA_WIDTH) * 3 + 2,
		"%02hhx", VM_GET1(w->vm, i));
	if (reverse)
		wattroff(w->w, A_REVERSE);
	wattroff(w->w, COLOR_PAIR(g_player_colors[owner].pair_id));
}

void			w_arena_update(t_w_arena *w, t_vec2u range)
{
	uint32_t		i;

	i = range.x;
	while (i < range.y)
	{
		update_byte(w, i, w->owners[i], false);
		i++;
	}
}

void			w_arena_update_processes(t_w_arena *w)
{
	t_process_loc	*loc;
	uint32_t		i;
	t_process const	*process;
	t_bits			loc_map[BITARRAY(MEM_SIZE)];

	ft_bzero(loc_map, sizeof(loc_map));
	loc = VECTOR_IT(w->process_loc);
	while (VECTOR_NEXT(w->process_loc, loc))
		update_byte(w, loc->pc, w->owners[loc->pc], false);
	process = LIST_IT(&w->vm->process);
	w->process_loc.length = 0;
	loc = ft_vpush(&w->process_loc, NULL, w->vm->process.length);
	i = 0;
	while ((process = LIST_NEXT(process)))
	{
		if (BITARRAY_GET(loc_map, i))
			continue ;
		loc[i] = (t_process_loc){process->reg_pc};
		update_byte(w, loc[i].pc, process->last_player_idx + 1, true);
		BITARRAY_SET(loc_map, i);
		i++;
	}
	w->process_loc.length = i;
}

void			w_arena_set_owner(t_w_arena *w, t_vec2u range, uint8_t owner)
{
	ft_memset(w->owners + range.x, owner, range.y - range.x);
}
