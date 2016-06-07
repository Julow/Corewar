/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:42:35 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/07 11:51:42 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_str_out.h"
#include "p_ui.h"

static void		log_key(t_ui *ui, int key)
{
	t_str_out		out;

	out = STR_OUT();
	ft_fprintf(&out, "key: %d", key);
	w_log_log(&ui->w_log, ft_str_out_sub(&out));
	ft_str_out_clear(&out);
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
