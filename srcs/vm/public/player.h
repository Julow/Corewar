/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:15:45 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 12:17:11 by jaguillo         ###   ########.fr       */
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
	t_dstr		name;
	t_dstr		comment;
};

# define PLAYER_INIT(ID,OFF)	((t_player){(ID), (OFF), DSTR0(), DSTR0()})

#endif
