/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:10:53 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 11:27:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/path.h"

#include "parse_params.h"

#define ARGS_ERROR(M, ...)	(ft_printf("Error: " M "%n", ##__VA_ARGS__), false)

static t_dstr	get_output_file(t_sub source_file)
{
	t_sub			dirname;
	t_sub			fname;

	fname = ft_path_split(source_file, &dirname);
	ft_path_ext(fname, &fname);
	return (ft_aprintf("%ts%ts%ts.cor", dirname,
			(dirname.length > 0) ? SUBC("/") : SUB0(), fname));
}

static bool		parse_argv_opt_o(t_params *params, t_argv *argv)
{
	t_params_file	file;
	t_sub			dest;

	if (!ft_argv_arg(argv, &dest) || dest.length == 0)
		return (ARGS_ERROR("-o: expect an argument"));
	if (!ft_argv_arg(argv, &file.file) || file.file.length == 0)
		return (ARGS_ERROR("-o: missing source file"));
	file.dest = DSTR0();
	ft_dstradd(&file.dest, dest);
	ft_vpush(&params->files, &file, 1);
	return (true);
}

bool			parse_params(t_params *params, t_argv argv)
{
	t_sub			tmp;

	while (true)
	{
		while (ft_argv_opt(&argv, &tmp))
			if (SUB_EQU(tmp, SUBC("v")) || SUB_EQU(tmp, SUBC("verbose")))
				params->flags |= FLAG_VERBOSE;
			else if (SUB_EQU(tmp, SUBC("f")) || SUB_EQU(tmp, SUBC("force")))
				params->flags |= FLAG_FORCE;
			else if (SUB_EQU(tmp, SUBC("o")) || SUB_EQU(tmp, SUBC("output")))
			{
				if (!parse_argv_opt_o(params, &argv))
					return (false);
			}
			else
				return (ARGS_ERROR("Unkown option --%ts", tmp));
		if (!ft_argv_arg(&argv, &tmp))
			break ;
		if (tmp.length == 0)
			return (ARGS_ERROR("Invalid argument ''"));
		ft_vpush(&params->files,
			&(t_params_file){tmp, get_output_file(tmp)}, 1);
	}
	return (true);
}
