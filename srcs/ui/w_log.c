/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_log.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:36:34 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 16:08:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

void			init_log(t_ui *ui)
{
	ui->w_log = create_newwin(LOG_POS, LOG_SIZE);
}

void			refresh_log(t_ui *ui)
{
	uint32_t		i;

	i = 0;
	while (i < ARRAY_LEN(ui->logs))
	{
		mvwprintw(ui->w_log, i + 1, 1, "%-*s", ARRAY_LEN(ui->logs[0]),
			ui->logs[(i + ui->log_start) % ARRAY_LEN(ui->logs)]);
		i++;
	}
	wnoutrefresh(ui->w_log);
}

void			ui_log(t_ui *ui, t_sub msg)
{
	uint32_t const	msg_len = MIN(msg.length, ARRAY_LEN(ui->logs[0]) - 1);

	ft_memcpy(ui->logs[ui->log_start], msg.str, msg_len);
	ui->logs[ui->log_start][msg_len] = '\0';
	ui->log_start = (ui->log_start + 1) % ARRAY_LEN(ui->logs);
}
