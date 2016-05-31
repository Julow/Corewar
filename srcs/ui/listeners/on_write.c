/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:19:46 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 18:59:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

static void		arena_update(t_ui *ui, t_process const *p, t_vec2u range)
{
	w_arena_set_owner(&ui->w_arena, range, p->player_idx + 1);
	w_arena_update(&ui->w_arena, range);
}

void			ui_on_write(t_ui *ui, t_process const *p, t_vec2u range)
{
	range.x = (((int32_t)range.x) + MEM_SIZE) % MEM_SIZE;
	range.y += range.x;
	if (range.y > MEM_SIZE)
	{
		arena_update(ui, p, VEC2U(range.x, MEM_SIZE));
		range = VEC2U(0, range.y % MEM_SIZE);
	}
	arena_update(ui, p, range);
}
