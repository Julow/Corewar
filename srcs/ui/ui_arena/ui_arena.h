/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_arena.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:29:54 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/31 16:58:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_ARENA_H
# define UI_ARENA_H

# include "ft/libft.h"
# include "ui_utils.h"

# include <ncurses.h>

typedef struct s_w_arena	t_w_arena;

/*
** ========================================================================== **
*/

# define ARENA_POS		(VEC2U(0, 0))
# define ARENA_SIZE		(VEC2U(195, 66))

struct			s_w_arena
{
	t_vm			*vm;
	WINDOW			*w;
	uint8_t			*colors;
};

# define W_ARENA(VM)	((t_w_arena){(VM), NULL, NULL})

/*
** -
*/

void			w_arena_init(t_w_arena *w);
void			w_arena_refresh(t_w_arena *w);
void			w_arena_destroy(t_w_arena *w);

#endif
