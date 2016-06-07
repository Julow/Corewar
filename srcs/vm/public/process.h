/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:01:42 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/07 16:36:22 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "ft/libft.h"
# include "op.h"

typedef struct s_process		t_process;

/*
** ========================================================================== **
** Process
*/

# define PFLAG_CARRY		(1 << 0)
# define PFLAG_ALIVE		(1 << 1)

# if REG_SIZE != 4
#  error "Invalid register size"
# endif

/*
** process object
** -
** player_idx	=> player index
** reg_pc		=> program counter register
** reg_pflags	=> flags register, flags:
** 		PFLAG_CARRY		carry flag (used by some instruction)
** 		PFLAG_DEAD		process is dead
** reg			=> general-purpose register
** wait_cycle	=> cycle to wait before next instruction
*/

struct			s_process
{
	uint32_t		player_idx;
	uint32_t		wait;
	uint32_t		reg_pc;
	int32_t			reg_pflags;
	int32_t			reg[REG_NUMBER];
};

/*
** Init a process object
** -
** PC			=> initial pc
** PIDX			=> player index
*/
# define PROCESS_INIT(PC,PIDX)		((t_process){(PIDX), 0, (PC), 0, {0}})

#endif
