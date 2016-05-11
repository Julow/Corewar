/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:01:42 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 16:02:33 by jaguillo         ###   ########.fr       */
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
# define PFLAG_DEAD			(1 << 1)

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
	uint32_t		reg_pc;
	uint32_t		reg_pflags;
	uint32_t		reg[REG_NUMBER];
};

#endif
