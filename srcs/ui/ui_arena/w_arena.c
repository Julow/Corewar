/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_arena.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:33:47 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 14:37:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"
#include "ui_arena.h"

#include <stdlib.h>

static void		init_owners(t_w_arena *w)
{
	uint32_t		i;
	t_vec2u			range;

	i = w->vm->player_count;
	range.y = MEM_SIZE;
	while (i-- > 0)
	{
		range.x = w->vm->players[i].arena_offset;
		while (range.y > range.x && VM_GET1(w->vm, range.y - 1) == 0)
			range.y--;
		w_arena_set_owner(w, range, i + 1);
		range.y = range.x;
	}
}

void			w_arena_init(t_w_arena *w)
{
	w->w = create_newwin(ARENA_POS, ARENA_SIZE);
	w->owners = NEW_N(uint8_t, MEM_SIZE);
	ft_memset(w->owners, 0, MEM_SIZE);
	init_owners(w);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	w_arena_update(w, VEC2U(0, MEM_SIZE));
}

void			w_arena_refresh(t_w_arena *w)
{
	wnoutrefresh(w->w);
}

void			w_arena_destroy(t_w_arena *w)
{
	delwin(w->w);
	free(w->owners);
}
