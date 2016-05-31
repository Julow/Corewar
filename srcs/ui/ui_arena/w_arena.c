/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_arena.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:33:47 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 16:59:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"
#include <stdlib.h>

// static void		print_arena(t_w_arena *w)
// {
// 	uint32_t			i;
// 	uint32_t			j;

// 	i = 0;
// 	while (i < 64)
// 	{
// 		j = 0;
// 		while(j < 64)
// 		{
// 			//get color in array
// 			mvprintw(i, j, "%02hhx  ", ((uint32_t *)(w->vm->arena))[i + j]);
// 			j++;
// 		}
// 		printw("\n  ");
// 		i++;
// 	}
// }

void			w_arena_init(t_w_arena *w)
{
	w->w = create_newwin(ARENA_POS, ARENA_SIZE);
	w->colors = NEW_N(uint8_t, MEM_SIZE);
}

void			w_arena_refresh(t_w_arena *w)
{
	wnoutrefresh(w->w);
}

void			w_arena_destroy(t_w_arena *w)
{
	delwin(w->w);
	free(w->colors);
}
