/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:50:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/21 16:30:08 by jaguillo         ###   ########.fr       */
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

	win_msg = ft_aprintf("Player #%d \"%ts\" wins !",
			p->id, DSTR_SUB(p->name));
	w_log_log(&ui->w_log, DSTR_SUB(win_msg));
	ft_dstrclear(&win_msg);
	w_log_log(&ui->w_log, SUBC("Press any key to quit"));
	refresh_ui(ui);
	timeout(-1);
	getch();
}

static void		dump(t_ui *ui)
{
	t_dstr			msg;

	msg = ft_aprintf("Dump at %u", ui->vm->clock);
	w_log_log(&ui->w_log, DSTR_SUB(msg));
	ft_dstrclear(&msg);
	ui->flags |= UI_PAUSE;
}

static void		loop(t_ui *ui, uint32_t dump_cycles)
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
			if (ui->vm->clock == dump_cycles)
			{
				dump(ui);
				break ;
			}
		}
		refresh_ui(ui);
	}
}

void			ui_loop(t_vm *vm, uint32_t dump_cycles)
{
	t_ui				ui;

	init_ui(&ui, vm);
	loop(&ui, dump_cycles);
	destroy_ui(&ui);
}
