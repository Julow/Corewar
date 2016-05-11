/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:28:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 15:28:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "parse_argv.h"
#include "vm.h"
#include "vm_exec.h"
#include "vm_loader.h"

int				main(int argc, char **argv)
{
	t_main			m;

	if (!parse_argv(&m, argc, argv))
		return (1);

	// while (!(vm.flags & VM_F_GAMEOVER))
	// {
	// 	vm_exec(&vm);
	// 	if (ui != NULL)
	// 		ui_update(ui);
	// 	if (vm.clock >= corewar.dump_clock)
	// 		...
	// }

	return (0);
}
