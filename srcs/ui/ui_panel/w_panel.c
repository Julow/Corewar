/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_panel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:35:39 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 16:58:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

void			w_panel_init(t_w_panel *w)
{
	w->w = create_newwin(PANEL_POS, PANEL_SIZE);
}

void			w_panel_refresh(t_w_panel *w)
{
	uint32_t		i;
	t_player const	*p;

	mvwprintw(w->w, 2, 5, "Cycles: %u", w->vm->clock);
	i = 0;
	while (i < w->vm->player_count)
	{
		p = &w->vm->players[i];
		mvwprintw(w->w, 7 + 5*i, 5, "Player #%d - %s", p->id, p->name.str);
		i++;
	}
	wnoutrefresh(w->w);
}

void			w_panel_destroy(t_w_panel *w)
{
	delwin(w->w);
}
