/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:28:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/30 16:34:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "debug_ui.h"
#include "main.h"
#include "parse_argv.h"
#include "ui.h"
#include "vm.h"
#include "vm_loader.h"

int				main(int argc, char **argv)
{
	t_main			m;

	if (!parse_argv(&m, argc, argv))
		return (1);

	ft_printf("flags: %b\ndump cycles: %u%n", m.flags, m.dump_cycles);

	vm_start(&m.vm);

	debug_loop(&m.vm);

	return (0);
}
