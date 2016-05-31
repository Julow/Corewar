/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ui.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:55:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 18:21:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_UI_H
# define P_UI_H

# include "ui.h"
# include "ui_arena.h"
# include "ui_log.h"
# include "ui_panel.h"

typedef struct s_ui		t_ui;

/*
** ========================================================================== **
*/

# define EXEC_PER_FRAME	10
# define FRAMERATE		(1000 / 30)

struct 			s_ui
{
	t_vm			*vm;
	t_w_arena		w_arena;
	t_w_panel		w_panel;
	t_w_log			w_log;
	uint32_t		flags;
	uint32_t		loop_speed;
};

# define UI_F_PAUSE		(1 << 0)
# define UI_F_EXIT		(1 << 1)

# define KEY_SPACE		32
# define KEY_ESC		27

/*
** Init
*/

# define UI_INIT(VM)	((t_ui){(VM), W_ARENA(VM), W_PANEL(VM), W_LOG(VM), UI_F_PAUSE, EXEC_PER_FRAME})

void			init_ui(t_ui *ui, t_vm *vm);
void			destroy_ui(t_ui *ui);

/*
** -
*/
void			handle_key(t_ui *ui, int key);

/*
** listeners
*/
void			ui_on_exec(t_ui *ui, t_process const *p, uint32_t op);
void			ui_on_fork(t_ui *ui, t_process const *p, t_process const *c);
void			ui_on_write(t_ui *ui, t_process const *p, t_vec2u range);
void			ui_on_die(t_ui *ui, t_process const *p);
void			ui_on_aff(t_ui *ui, t_process const *p, uint32_t aff);
void			ui_on_live(t_ui *ui, t_process const *p);

#endif
