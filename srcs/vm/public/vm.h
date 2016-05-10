/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:32:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/10 15:07:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "ft/libft.h"
# include "ft/vector.h"

# include "players.h"
# include "process.h"

typedef struct s_vm		t_vm;

/*
** ========================================================================== **
** VM
*/

# define VM_F_GAMEOVER		(1 << 0)

# define VM_GAMEOVER(VM)	((VM).flags & VM_F_GAMEOVER)

/*
** vm object
** -
** clock			=> clock count since game start
** next_check		=> clock until next check
** nbr_live			=> live count since last check
** nbr_check		=> check count since last decrement of cycle_to_check
** cycle_to_check	=> clock delta between 2 checks
** flags			=> flags:
** 			VM_F_GAMEOVER		game is over
** process			=> processes
*/

struct			s_vm
{
	uint32_t		clock;
	uint32_t		next_check;
	uint32_t		nbr_live;
	uint32_t		nbr_check;
	uint32_t		cycle_to_check;
	uint32_t		flags;
	t_vector		process;
	t_player		players[MAX_PLAYER];
	uint32_t		player_count;
	void			*arena;
};

# define VM_INIT()			((t_vm){0, 0, 0, 0, 0, 0, VECTOR(t_process)})

#endif
