/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:53:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/07 13:00:09 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "parse_argv.h"

#include <stdlib.h>

bool			parse_opt_dump(t_parse_argv *argv)
{
	t_sub			value;

	argv->flags |= ARGV_F_DUMP;
	if (!ft_argv_arg(&argv->args, &value))
		PARSE_ARGV_ERR("-d: Require a value");
	else if (ft_subto_uint(value, &argv->dump_cycles) != value.length)
		PARSE_ARGV_ERR("-d: Invalid value: %ts", value);
	else
		return (true);
	return (false);
}

bool			parse_opt_n(t_parse_argv *argv)
{
	t_sub			value;
	int32_t			player_id;

	if (!ft_argv_arg(&argv->args, &value) || value.length == 0)
		PARSE_ARGV_ERR("-n: Require a value");
	else if (ft_subto_int(value, &player_id) != value.length)
		PARSE_ARGV_ERR("-n: Invalid value: %ts", value);
	else if (next_player_id(&argv->vm_loader, player_id) != player_id)
		PARSE_ARGV_ERR("-n: Player id already used: %d", player_id);
	else if (!ft_argv_arg(&argv->args, &value))
		PARSE_ARGV_ERR("Missing file name for player %d", player_id);
	else
		return (push_player(argv, player_id, value));
	return (false);
}

bool			parse_opt_a(t_parse_argv *argv)
{
	argv->flags |= ARGV_F_AFF;
	return (true);
}

bool			parse_opt_h(t_parse_argv *argv)
{
	ft_printf("Usage: ./corewar [-a] [-d nbr_cycles]"
		" [[-n player_id] champion ...]\n"
		"	-a	Prints output from \"aff\" (Default is to hide it)\n"
		"	-d nbr_cycles\n"
		"	--dump=nbr_cycles\n"
		"		Dumps memory after nbr_cycles cycles then exits\n"
		"	-n player_id\n"
		"		Set the id of the next champion%n");
	exit(0);
	return (true);
	(void)argv;
}
