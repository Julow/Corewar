/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:19:10 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 17:43:56 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "parse_argv.h"

static t_argv_opt const	g_parse_argv_opts[] = {
	{SUBC("a"), &parse_opt_a},
	{SUBC("d"), &parse_opt_dump},
	{SUBC("dump"), &parse_opt_dump},
	{SUBC("n"), &parse_opt_n},
	{SUBC("h"), &parse_opt_h},
	{SUBC("help"), &parse_opt_h},
	{SUBC("ui"), &parse_opt_ui},
};

static bool		parse_argv_argv(t_parse_argv *argv)
{
	t_sub			opt;
	uint32_t		i;

	while (ft_argv_opt(&argv->args, &opt))
	{
		i = 0;
		while (true)
			if (i >= ARRAY_LEN(g_parse_argv_opts))
			{
				PARSE_ARGV_ERR("Unknown option: %ts%n"
					"Use --help option for help", opt);
				return (false);
			}
			else if (!SUB_EQU(opt, g_parse_argv_opts[i].opt))
				i++;
			else if (!g_parse_argv_opts[i].f(argv))
				return (false);
			else
				break ;
	}
	if (!ft_argv_arg(&argv->args, &opt))
		return (true);
	if (!push_player(argv, next_player_id(&argv->vm_loader, 0), opt))
		return (false);
	return (parse_argv_argv(argv));
}

static bool		load_main(t_parse_argv const *argv, t_main *p)
{
	p->flags = argv->flags;
	p->dump_cycles = argv->dump_cycles;
	p->ui = argv->ui_type;
	return (load_vm(&argv->vm_loader, &p->vm));
}

bool			parse_argv(t_main *p, int argc, char *const *argv)
{
	t_parse_argv	arg;
	bool			ok;

	if (argc == 1)
	{
		print_usage();
		return (false);
	}
	arg = (t_parse_argv){ARGV(argc, argv), 0, 0, UI_NORMAL, VM_LOADER()};
	ok = parse_argv_argv(&arg) && load_main(&arg, p);
	vm_loader_destroy(&arg.vm_loader);
	return (ok);
}
