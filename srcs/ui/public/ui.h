/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:00:28 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/17 16:44:56 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "op.h"
# include "vm.h"

# include <ncurses.h>

/*
** Define size and place of the win
*/
# define ARENA_W		70
# define ARENA_H		100
# define PANEL_W		30
# define PANEL_H		100
# define ARENA_S_X		0
# define ARENA_S_Y		0
# define PANEL_S_X		70
# define PANEL_S_Y		0

typedef struct s_ui		t_ui;

struct 			s_ui
{
	t_vm			*vm;
	uint8_t			*b_colors;
	WINDOW			*w_arena;
	WINDOW			*w_panel;
	uint32_t		flags;
	uint32_t		ui_clock;
};

void					ui_loop(t_vm const *vm);
void					print_arena(t_ui *ui);
WINDOW 					*create_newwin(int height, int width,
								int starty, int startx);

#endif
