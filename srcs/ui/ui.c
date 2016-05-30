/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:50:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/30 19:26:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

static void		init_panel(t_ui *ui)
{
}

static void		refresh_arena(t_ui *ui)
{
}

static void		refresh_panel(t_ui *ui)
{
	uint32_t		i;
	t_player const	*p;

	mvwprintw(ui->w_panel, 2, 5, "Cycles: %u", ui->vm->clock);
	i = 0;
	while (i < ui->vm->player_count)
	{
		p = &ui->vm->players[i];
		mvwprintw(ui->w_panel, 7 + 5*i, 5, "Player #%d - %s", p->id, p->name.str);
		i++;
	}
}

static void		refresh_log(t_ui *ui)
{
}

static void		loop(t_ui *ui)
{
	uint32_t		loop;

	while (!VM_GAMEOVER(*ui->vm))
	{
		getch();
		loop = ui->loop_speed;
		while (!VM_GAMEOVER(*ui->vm) && loop-- > 0)
			vm_exec(ui->vm);
		refresh_arena(ui);
		refresh_panel(ui);
		refresh_log(ui);
		wnoutrefresh(ui->w_arena);
		wnoutrefresh(ui->w_panel);
		wnoutrefresh(ui->w_log);
		doupdate();
		usleep(1000000/30);
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

// getmaxyx(stdscr,int row,int col);		/* get the number of rows and columns */
// getch(); 								class: Get a character
// getyx(win, y, x);
//     /* win: window pointer
//      *   y, x: y, x co-ordinates will be put into this variables 
//      */
