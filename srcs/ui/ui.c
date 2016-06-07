/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:50:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/07 11:51:34 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"
#include "vm_exec.h"

static void		refresh_ui(t_ui *ui)
{
	w_arena_refresh(&ui->w_arena);
	w_panel_refresh(&ui->w_panel);
	w_log_refresh(&ui->w_log);
	doupdate();
	refresh();
}

static void		loop(t_ui *ui)
{
	uint32_t		loop;

	while (!VM_GAMEOVER(*ui->vm) && !(ui->flags & UI_F_EXIT))
	{
		handle_key(ui, getch());
		loop = (ui->flags & UI_PAUSE) ? 0 : ui->loop_speed;
		while (!VM_GAMEOVER(*ui->vm) && loop-- > 0)
			vm_exec(ui->vm);
		refresh_ui(ui);
		// usleep(1000000/30);
	}
}

void			ui_loop(t_vm *vm)
{
	t_ui				ui;

	init_ui(&ui, vm);
	loop(&ui);
	destroy_ui(&ui);
}
