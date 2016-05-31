/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:25:37 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 15:27:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft/libft.h"
# include "vm.h"

typedef struct s_main		t_main;

/*
** ========================================================================== **
** Main
*/

# define ARGV_F_AFF		(1 << 0)
# define ARGV_F_DUMP	(1 << 1)
# define ARGV_F_NCURSE	(1 << 2)

struct			s_main
{
	uint32_t		flags;
	uint32_t		dump_cycles;
	t_vm			vm;
};

#endif
