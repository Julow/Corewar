/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:32:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/23 12:03:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "ft/ft_list.h"
# include "ft/libft.h"

# include "op.h"
# include "player.h"
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
	uint32_t		last_alive_player;
	uint32_t		flags;
	t_player		players[MAX_PLAYERS];
	uint32_t		player_count;
	t_list			process;
	void			*arena;
};

# define VM_INIT()			((t_vm){0,0,0,0,0,0,0,{},0,LIST(t_process),NULL})

# define VM_GET1(VM,I)		(((char const*)(VM)->arena)[I])

/*
** Start the game
** (Unexpected behavior if called twice)
*/
void			vm_start(t_vm *vm);

/*
** Set the process wait time for it's next instruction
*/
void			vm_wait_next(t_vm *vm, t_process *process);

/*
** Read n bytes from arena + i
** n can be 1, 2 or 4
*/
uint32_t		vm_get(t_vm const *vm, int32_t i, uint32_t n);

/*
** Write n bytes from arena + i
** 0 < n <= 4
*/
void			vm_set(t_vm *vm, int32_t i, uint32_t value, uint32_t n);

/*
** Destroy vm
*/
void			vm_destroy(t_vm *vm);

#endif
