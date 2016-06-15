/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:15:45 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/15 15:54:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "ft/ft_dstr.h"
# include "ft/libft.h"

typedef struct s_player		t_player;

/*
** ========================================================================== **
** Player
*/

struct		s_player
{
	uint32_t	id;
	uint32_t	arena_offset;
	uint32_t	last_live;
	uint32_t	live_to_check;
	uint32_t	weight;
	uint32_t	process_count;
	t_dstr		name;
	t_dstr		comment;
};

# define PLAYER_INIT(ID,OFF)	((t_player){(ID),(OFF),0,0,0,0,DSTR0(),DSTR0()})

#endif
