/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 21:00:52 by juloo             #+#    #+#             */
/*   Updated: 2016/06/21 21:49:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/argv.h"
#include "ft/ft_printf.h"

#include "p_disass.h"

static void		print_usage(void)
{
	ft_printf("Usage: disass [opt] files ...\n"
		"\t-r\tDisable colors and formatting%n");
}

static bool		parse_options(uint32_t *flags, t_argv *argv)
{
	t_sub			opt;

	while (ft_argv_opt(argv, &opt))
		if (SUB_EQU(opt, SUBC("r")))
			*flags |= DISASS_F_RAW;
		else
		{
			ft_dprintf(2, "Unknown option '%ts'%n", opt);
			print_usage();
			return (false);
		}
	return (true);
}

static void		disass_files(uint32_t flags, t_argv *argv)
{
	t_sub			file;
	t_cor			cor;
	t_dstr			err;

	err = DSTR0();
	while (ft_argv_arg(argv, &file))
	{
		if (!load_cor(file, &cor, &err))
		{
			ft_dprintf(2, "Error: %ts: %ts%n", file, DSTR_SUB(err));
		}
		else
		{
			disass_cor(&cor, flags);
			cor_destroy(&cor);
		}
		ft_dstrclear(&err);
	}
}

int				main(int argc, char **argv)
{
	uint32_t		flags;
	t_argv			args;

	if (argc <= 1)
	{
		print_usage();
		return (1);
	}
	args = ARGV(argc, argv);
	if (!parse_options(&flags, &args))
		return (1);
	disass_files(flags, &args);
	return (0);
}
