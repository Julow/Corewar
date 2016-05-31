/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:18:11 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 18:51:26 by jaguillo         ###   ########.fr       */
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

void			w_arena_update(t_w_arena *w, t_vec2u range)
{
	uint32_t		i;
	uint8_t			owner;

	i = range.x;
	while (i < range.y)
	{
		owner = w->owners[i];
		wattron(w->w, COLOR_PAIR(g_player_colors[owner].pair_id));
		if (g_player_colors[owner].bold != 0)
			wattron(w->w, A_BOLD);
		else
			wattroff(w->w, A_BOLD);
		mvwprintw(w->w, i / ARENA_WIDTH + 1, (i % ARENA_WIDTH) * 3 + 2,
			"%02hhx ", VM_GET1(w->vm, i));
		wattroff(w->w, COLOR_PAIR(g_player_colors[owner].pair_id));
		i++;
	}
}

void			w_arena_set_owner(t_w_arena *w, t_vec2u range, uint8_t owner)
{
	ft_memset(w->owners + range.x, owner, range.y - range.x);
}
