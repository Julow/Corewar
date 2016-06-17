/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_arena.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:29:54 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 13:58:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_ARENA_H
# define UI_ARENA_H

# include "ft/ft_vector.h"
# include "ft/libft.h"

# include "ui.h"
# include "ui_utils.h"

# include <ncurses.h>

typedef struct s_w_arena		t_w_arena;
typedef struct s_player_color	t_player_color;
typedef struct s_process_loc	t_process_loc;

/*
** ========================================================================== **
*/

# define ARENA_POS		(VEC2U(0, 0))
# define ARENA_SIZE		(VEC2U(195, 66))

# define ARENA_WIDTH	64

/*
** owners	=>
** 		0		=> no one
** 		1-4		=> player
*/

struct			s_w_arena
{
	t_vm			*vm;
	WINDOW			*w;
	uint8_t			*owners;
	t_vector		process_loc;
};

struct			s_process_loc
{
	uint32_t		pc;
};

struct			s_player_color
{
	uint32_t		pair_id;
	bool			bold;
};

# define W_A(VM)	((t_w_arena){(VM), NULL, NULL, VECTOR(t_process_loc)})

/*
** -
*/

void			w_arena_init(t_w_arena *w);
void			w_arena_refresh(t_w_arena *w);
void			w_arena_destroy(t_w_arena *w);

void			w_arena_update(t_w_arena *w, t_vec2u range);

void			w_arena_update_processes(t_w_arena *w);

void			w_arena_set_owner(t_w_arena *w, t_vec2u range, uint8_t owner);

#endif
