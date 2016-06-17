/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:28:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 15:18:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "debug_ui.h"
#include "main.h"
#include "parse_argv.h"
#include "ui.h"
#include "vm.h"

int				main(int argc, char **argv)
{
	t_main			m;

	if (!parse_argv(&m, argc, argv))
		return (1);
	vm_start(&m.vm);
	if (m.ui == UI_NCURSES)
		ui_loop(&m.vm);
	else if (m.ui == UI_DEBUG)
		debug_loop(&m.vm);
	else
		dump_loop(&m);
	return (0);
}
