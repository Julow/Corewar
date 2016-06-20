/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:37:38 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/20 17:43:41 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "parse_argv.h"

bool			push_player(t_parse_argv *argv, int32_t id, t_sub file_name)
{
	t_vm_loader_play	player;

	player = (t_vm_loader_play){id, ft_aprintf("%ts", file_name)};
	ft_vpush(&argv->vm_loader.player, &player, 1);
	return (true);
}

void			print_usage(void)
{
	ft_printf("Usage: ./corewar [-a] [-d nbr_cycles]"
			" [[-n player_id] champion ...]\n"
			"	-a	Prints output from \"aff\" (Default is to hide it)\n"
			"	-d nbr_cycles\n"
			"	--dump=nbr_cycles\n"
			"		Dumps memory after nbr_cycles cycles then exits\n"
			"	--ui=ncurses\n"
			"		Interactive mode\n"
			"	--ui=debug\n"
			"		Debug mode\n"
			"	--ui\n"
			"		Default ui is ncurses\n"
			"	-n player_id\n"
			"		Set the id of the next champion%n");
}
