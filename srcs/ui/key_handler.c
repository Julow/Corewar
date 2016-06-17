/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:42:35 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 12:18:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
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

static void		inc_speed(t_ui *ui, int32_t inc)
{
	t_dstr			msg;

	ui->loop_speed = MIN(
			MAX((int32_t)ui->loop_speed + inc, LOOP_SPEED_MIN),
			LOOP_SPEED_MAX);
	msg = ft_aprintf("Speed: %u", ui->loop_speed);
	w_log_log(&ui->w_log, DSTR_SUB(msg));
	ft_dstrclear(&msg);
}

void			handle_key(t_ui *ui, int key)
{
	if (key == KEY_SPACE)
		toggle_pause(ui);
	else if (key == KEY_ESC)
		ui->flags |= UI_F_EXIT;
	else if (key == KEY_PLUS)
		inc_speed(ui, LOOP_SPEED_INC);
	else if (key == KEY_MINUS)
		inc_speed(ui, -LOOP_SPEED_INC);
	else if (key != -1)
		log_key(ui, key);
}
