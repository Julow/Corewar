/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:50:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/20 17:39:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

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

static void		loop_end(t_ui *ui)
{
	t_dstr					win_msg;
	t_player const *const	p = &ui->vm->players[ui->vm->last_alive_player];

	win_msg = ft_aprintf("Player #%d \"%ts\" win !",
			p->id, DSTR_SUB(p->name));
	w_log_log(&ui->w_log, DSTR_SUB(win_msg));
	ft_dstrclear(&win_msg);
	w_log_log(&ui->w_log, SUBC("Press any key to quit"));
	refresh_ui(ui);
	timeout(-1);
	getch();
}

static void		loop(t_ui *ui)
{
	uint32_t		loop;

	while (!(ui->flags & UI_F_EXIT))
	{
		handle_key(ui, getch());
		loop = (ui->flags & UI_PAUSE) ? 0 : ui->loop_speed;
		while (loop-- > 0)
		{
			vm_exec(ui->vm);
			if (VM_GAMEOVER(*ui->vm))
				return (loop_end(ui));
		}
		refresh_ui(ui);
	}
}

void			ui_loop(t_vm *vm)
{
	t_ui				ui;

	init_ui(&ui, vm);
	loop(&ui);
	destroy_ui(&ui);
}
