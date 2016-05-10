/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:15:45 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/10 14:26:22 by jaguillo         ###   ########.fr       */
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
	uint32_t	player_id;
	uint32_t	last_live;
	t_dstr		name;
	t_dstr		comment;
};

#endif
