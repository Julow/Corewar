/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ui.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:55:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/30 19:14:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_UI_H
# define P_UI_H

# include "ui.h"
# include <ncurses.h>

typedef struct s_ui		t_ui;

/*
** ========================================================================== **
*/

# define ARENA_POS		(VEC2U(0, 0))
# define ARENA_SIZE		(VEC2U(195, 66))

# define PANEL_POS		(VEC2U(195, 0))
# define PANEL_SIZE		(VEC2U(42, 75))

# define LOG_POS		(VEC2U(0, 66))
# define LOG_SIZE		(VEC2U(195, 9))

# define EXEC_PER_FRAME	10
# define FRAMERATE		(1000 / 30)

struct 			s_ui
{
	t_vm			*vm;
	WINDOW			*w_arena;
	WINDOW			*w_panel;
	WINDOW			*w_log;
	uint8_t			*arena_colors;
	uint32_t		flags;
	uint32_t		loop_speed;
};

/*
** Init
*/
# define UI_INIT(VM)	((t_ui){(VM), NULL, NULL, NULL, NULL, 0, EXEC_PER_FRAME})

void			init_ui(t_ui *ui, t_vm *vm);
void			destroy_ui(t_ui *ui);

/*
** -
*/
void			print_arena(t_ui *ui);

/*
** listeners
*/
void			ui_on_exec(void*, t_process const*, uint32_t op);
void			ui_on_fork(void*, t_process const*, t_process const *c);
void			ui_on_read(void*, t_process const*, uint32_t i, uint32_t s);
void			ui_on_write(void*, t_process const*, uint32_t i, uint32_t s);
void			ui_on_die(void*, t_process const*);
void			ui_on_aff(void*, t_process const*, uint32_t aff);
void			ui_on_live(void*, t_process const*);

#endif
