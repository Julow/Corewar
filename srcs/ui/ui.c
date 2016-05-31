/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:50:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/31 16:15:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"
#include "vm_exec.h"

static void		refresh_ui(t_ui *ui)
{
	refresh_arena(ui);
	refresh_panel(ui);
	refresh_log(ui);
	doupdate();
	refresh();
}

static void		loop(t_ui *ui)
{
	uint32_t		loop;

	while (!VM_GAMEOVER(*ui->vm) && !(ui->flags & UI_F_EXIT))
	{
		handle_key(ui, getch());
		loop = (ui->flags & UI_F_PAUSE) ? 0 : ui->loop_speed;
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
	init_panel(&ui);
	loop(&ui);
	destroy_ui(&ui);
}
