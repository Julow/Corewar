/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 18:32:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 16:59:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"
#include "ui.h"

WINDOW			*create_newwin(t_vec2u pos, t_vec2u size)
{
	WINDOW			*w;

	w = newwin(size.y, size.x, pos.y, pos.x);
	box(w, 0 , 0);
	return (w);
}

void			init_ui(t_ui *ui, t_vm *vm)
{
	initscr();
	curs_set(0);
	timeout(FRAMERATE);
	noecho();
	cbreak();
	*ui = UI_INIT(vm);
	w_arena_init(&ui->w_arena);
	w_panel_init(&ui->w_panel);
	w_log_init(&ui->w_log);
	ui->vm->listeners = (t_listeners){
		NULL, //&ui_on_exec,
		NULL, //&ui_on_fork,
		NULL, //&ui_on_write,
		NULL, //&ui_on_die,
		NULL, //&ui_on_aff,
		NULL, //&ui_on_live,
		ui
	};
}

void			destroy_ui(t_ui *ui)
{
	w_arena_destroy(&ui->w_arena);
	w_panel_destroy(&ui->w_panel);
	w_log_destroy(&ui->w_log);
	endwin();
}
