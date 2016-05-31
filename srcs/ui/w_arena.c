/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_arena.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:33:47 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 15:41:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

static void		print_arena(t_ui *ui)
{
	uint32_t			i;
	uint32_t			j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while(j < 64)
		{
			//get color in array
			mvprintw(i, j, "%02hhx  ", ((uint32_t *)(ui->vm->arena))[i + j]);
			j++;
		}
		printw("\n  ");
		i++;
	}
}

void			init_arena(t_ui *ui)
{
	ui->w_arena = create_newwin(ARENA_POS, ARENA_SIZE);
}

void			refresh_arena(t_ui *ui)
{
	wnoutrefresh(ui->w_arena);
}
