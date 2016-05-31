/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:19:10 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 17:03:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "parse_argv.h"

static bool		push_player(t_parse_argv *argv, int32_t id, t_sub file_name)
{
	t_vm_loader_player	player;

	ft_printf("PUSH PLAYER %ts:%u%n", file_name, id);
	player = (t_vm_loader_player){id, DSTR0()};
	ft_dstradd(&player.file_name, file_name);
	ft_vpush(&argv->vm_loader.player, &player, 1);
	return (true);
}

static bool		parse_opt_dump(t_parse_argv *argv)
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

static bool		parse_opt_n(t_parse_argv *argv)
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

static bool		load_main(t_parse_argv const *argv, t_main *p)
{
	p->flags = argv->flags;
	p->dump_cycles = argv->dump_cycles;
	return (load_vm(&argv->vm_loader, &p->vm));
}

static void		print_usage(void)
{
	ft_printf("Usage: ./corewar [-a] [-d nbr_cycles] [[-n player_id] champion ...]\n"
		"	-a	Prints output from \"aff\" (Default is to hide it)\n"
		"	-d nbr_cycles\n"
		"	--dump=nbr_cycles\n"
		"		Dumps memory after nbr_cycles cycles then exits\n"
		"	-n player_id\n"
		"		Set the id of the next champion%n");
}

static bool		parse_argv_argv(t_parse_argv *argv)
{
	t_sub			opt;

	while (ft_argv_opt(&argv->args, &opt))
		if (SUB_EQU(opt, SUBC("a")))
			argv->flags |= ARGV_F_AFF;
		else if (SUB_EQU(opt, SUBC("dump")) || SUB_EQU(opt, SUBC("d")))
		{
			if (!parse_opt_dump(argv))
				return (false);
		}
		else if (SUB_EQU(opt, SUBC("n")))
		{
			if (!parse_opt_n(argv))
				return (false);
		}
		else if (SUB_EQU(opt, SUBC("help")) || SUB_EQU(opt, SUBC("h")))
			print_usage();
		else
		{
			PARSE_ARGV_ERR("Unknown option: %ts", opt);
			print_usage();
			return (false);
		}
	if (!ft_argv_arg(&argv->args, &opt))
		return (true);
	if (!push_player(argv, next_player_id(&argv->vm_loader, 0), opt))
		return (false);
	return (parse_argv_argv(argv));
}

bool			parse_argv(t_main *p, int argc, char *const *argv)
{
	t_parse_argv	arg;
	bool			ok;

	arg = (t_parse_argv){ARGV(argc, argv), 0, 0, VM_LOADER()};
	ok = parse_argv_argv(&arg) && load_main(&arg, p);
	vm_loader_destroy(&arg.vm_loader);
	return (ok);
}
