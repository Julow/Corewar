/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_panel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:35:39 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 15:37:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

void			init_panel(t_ui *ui)
{
	ui->w_panel = create_newwin(PANEL_POS, PANEL_SIZE);
}

void			refresh_panel(t_ui *ui)
{
	uint32_t		i;
	t_player const	*p;

	mvwprintw(ui->w_panel, 2, 5, "Cycles: %u", ui->vm->clock);
	i = 0;
	while (i < ui->vm->player_count)
	{
		p = &ui->vm->players[i];
		mvwprintw(ui->w_panel, 7 + 5*i, 5, "Player #%d - %s", p->id, p->name.str);
		i++;
	}
	wnoutrefresh(ui->w_panel);
}
