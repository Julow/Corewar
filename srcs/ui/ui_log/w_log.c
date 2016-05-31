/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_log.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:36:34 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 16:58:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

void			w_log_init(t_w_log *w)
{
	w->w = create_newwin(LOG_POS, LOG_SIZE);
}

void			w_log_refresh(t_w_log *w)
{
	uint32_t		i;

	i = 0;
	while (i < ARRAY_LEN(w->logs))
	{
		mvwprintw(w->w, i + 1, 1, "%-*s", ARRAY_LEN(w->logs[0]),
			w->logs[(i + w->log_start) % ARRAY_LEN(w->logs)]);
		i++;
	}
	wnoutrefresh(w->w);
}

void			w_log_log(t_w_log *w, t_sub msg)
{
	uint32_t const	msg_len = MIN(msg.length, ARRAY_LEN(w->logs[0]) - 1);

	ft_memcpy(w->logs[w->log_start], msg.str, msg_len);
	w->logs[w->log_start][msg_len] = '\0';
	w->log_start = (w->log_start + 1) % ARRAY_LEN(w->logs);
}

void			w_log_destroy(t_w_log *w)
{
	delwin(w->w);
}
