/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 18:32:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 18:19:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"
#include "ui.h"

WINDOW			*create_newwin(t_vec2u pos, t_vec2u size)
{
	WINDOW			*w;

	w = newwin(size.y, size.x, pos.y, pos.x);
	box(w, 0, 0);
	return (w);
}

void			init_ui(t_ui *ui, t_vm *vm)
{
	initscr();
	curs_set(0);
	timeout(FRAMERATE);
	noecho();
	keypad(stdscr, TRUE);
	cbreak();
	start_color();
	use_default_colors();
	*ui = UI_INIT(vm);
	w_arena_init(&ui->w_arena);
	w_panel_init(&ui->w_panel);
	w_log_init(&ui->w_log);
	ui->vm->listeners = (t_listeners){
		NULL,
		NULL,
		V(&ui_on_write),
		NULL,
		V(&ui_on_aff),
		NULL,
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
