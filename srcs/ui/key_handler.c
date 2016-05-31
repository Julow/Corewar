/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:42:35 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 16:14:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_str_out.h"
#include "p_ui.h"

static void		log_key(t_ui *ui, int key)
{
	t_str_out		out;

	out = STR_OUT();
	ft_fprintf(&out, "key: %d", key);
	ui_log(ui, ft_str_out_sub(&out));
	ft_str_out_clear(&out);
}

static void		toggle_pause(t_ui *ui)
{
	ui->flags ^= UI_F_PAUSE;
	ui_log(ui, (ui->flags & UI_F_PAUSE) ? SUBC("** PAUSE **") : SUBC("** RESUME **"));
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
