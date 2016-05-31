/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 18:32:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 15:38:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"
#include "ui.h"

#include <stdlib.h>

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
	init_arena(ui);
	init_panel(ui);
	init_log(ui);
	ui->arena_colors = NEW_N(uint8_t, MEM_SIZE);
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
	delwin(ui->w_arena);
	delwin(ui->w_panel);
	delwin(ui->w_log);
	free(ui->arena_colors);
	endwin();
}
