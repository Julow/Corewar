/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:25:37 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/15 13:48:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft/libft.h"
# include "vm.h"

typedef struct s_main		t_main;
typedef enum e_ui_type		t_ui_type;

/*
** ========================================================================== **
** Main
*/

# define ARGV_F_AFF		(1 << 0)
# define ARGV_F_DUMP	(1 << 1)

enum			e_ui_type
{
	UI_NORMAL,
	UI_DEBUG,
	UI_NCURSES
};

struct			s_main
{
	t_ui_type		ui;
	uint32_t		flags;
	uint32_t		dump_cycles;
	t_vm			vm;
};

void			dump_loop(t_vm *vm);

#endif
