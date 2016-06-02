/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 17:20:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/02 18:17:31 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/ft_str_out.h"

#include "p_ui.h"

void			ui_on_aff(t_ui *ui, t_process const *p, uint32_t val)
{
	t_str_out				msg;
	t_player const *const	player = &ui->vm->players[p->player_idx];

	msg = STR_OUT();
	ft_fprintf(&msg, "The player %ts is so pimp he says : %d aka %c",
			DSTR_SUB(player->name), val, val % 256);
	w_log_log(&ui->w_log, ft_str_out_sub(&msg));
	ft_str_out_clear(&msg);
}
