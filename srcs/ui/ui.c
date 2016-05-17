/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:50:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/17 16:57:17 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

WINDOW 					*create_newwin(int height, int width,
								int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	wrefresh(local_win);
	return local_win;
}

static void				ui_init(t_vm const *vm, t_ui *ui)
{
	initscr();
	ui->w_arena = create_newwin(ARENA_H, ARENA_W, ARENA_S_X, ARENA_S_Y);
	ui->w_panel = create_newwin(PANEL_H, PANEL_W, PANEL_S_X, PANEL_S_Y);
    refresh();
}

static void				panel_init(t_ui *ui)
{

}

void				ui_loop(t_vm const *vm)
{
	t_ui				ui;

	ui_init(vm, &ui);
	panel_init(&ui);
	print_arena(&ui);

}

// getmaxyx(stdscr,int row,int col);		/* get the number of rows and columns */
// getch(); 								class: Get a character
// getyx(win, y, x);
//     /* win: window pointer
//      *   y, x: y, x co-ordinates will be put into this variables 
//      */
