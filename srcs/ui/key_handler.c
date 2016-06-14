/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:42:35 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 14:38:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_str_out.h"
#include "p_ui.h"

static void		log_key(t_ui *ui, int key)
{
	(void)ui;
	(void)key;
}

static void		toggle_pause(t_ui *ui)
{
	ui->flags ^= UI_PAUSE;
	w_log_log(&ui->w_log, (ui->flags & UI_PAUSE) ?
		SUBC("** PAUSE **") : SUBC("** RESUME **"));
}

void			handle_key(t_ui *ui, int key)
{
	if (key == KEY_SPACE)
		toggle_pause(ui);
	else if (key == KEY_ESC)
		ui->flags |= UI_F_EXIT;
	else if (key != -1)
		log_key(ui, key);
}
