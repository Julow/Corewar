/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:25:37 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/10 16:26:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft/libft.h"
# include "vm.h"

/*
** ========================================================================== **
** Main
*/

# define ARGV_F_DUMP	(1 << 0)
# define ARGV_F_NCURSE	(1 << 1)

struct			s_main
{
	uint32_t		flags;
	uint32_t		dump_cycles;
	t_vm			*vm;
};

#endif
