/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_panel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:35:39 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/07 11:56:09 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

void			w_panel_init(t_w_panel *w)
{
	w->w = create_newwin(PANEL_POS, PANEL_SIZE);
}

static void		w_panel_info(t_w_panel *w)
{
	mvwprintw(w->w, 2, 5, "Cycles: %u", w->vm->clock);
	mvwprintw(w->w, 4, 5, "Processes: %u", w->vm->process.length);
	mvwprintw(w->w, 35, 5, "CYCLE_TO_LIVE :%13d", w->vm->cycle_to_check);
	mvwprintw(w->w, 37, 5, "CYCLE_DELTA :%15d", CYCLE_DELTA);
	mvwprintw(w->w, 39, 5, "NBR_LIVE :%18d", NBR_LIVE);
	mvwprintw(w->w, 41, 5, "MAX_CHECK :%17d", MAX_CHECKS);
}

static void		w_panel_players(t_w_panel *w)
{
	uint32_t		i;
	t_player const	*p;

	i = 0;
	while (i < w->vm->player_count)
	{
		p = &w->vm->players[i];
		mvwprintw(w->w, 7 + 5 * i, 5, "Player #%d - %s", p->id, p->name.str);
		mvwprintw(w->w, 8 + 5 * i, 6, "Last live :%20d", p->last_live);
		mvwprintw(w->w, 9 + 5 * i, 6, "Live in period :%15d", p->live_to_check);
		i++;
	}
}

/*
** last live is the cycle when live
*/

void			w_panel_refresh(t_w_panel *w)
{
	w_panel_info(w);
	w_panel_players(w);
	wnoutrefresh(w->w);
}

void			w_panel_destroy(t_w_panel *w)
{
	delwin(w->w);
}
