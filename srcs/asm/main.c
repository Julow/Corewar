/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:04:46 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 14:28:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/argv.h"
#include "ft/ft_printf.h"

#include "p_asm.h"
#include "parse_params.h"

static void		print_usage(void)
{
	ft_printf("Usage: ./asm [-v] [[-o dest] source_file ...]\n"
		"	-v\n"
		"	--verbose\n"
		"		Verbose\n"
		"	-o dest\n"
		"	--output dest\n"
		"		Output file for the next source_file%n");
}

static bool		compile(t_params const *p)
{
	t_dstr				err;
	t_params_file const	*f;

	err = DSTR0();
	f = VECTOR_IT(p->files);
	while (VECTOR_NEXT(p->files, f))
		if (!compile_file(f, &err))
		{
			ft_dprintf(2, "%ts: %ts%n", f->file, DSTR_SUB(err));
			err.length = 0;
		}
		else
			ft_printf("COMPILE %ts TO %ts.%n", f->file, DSTR_SUB(f->dest));
	ft_dstrclear(&err);
	return (true);
}

int				main(int ac, char **av)
{
	t_params		params;

	params = (t_params){0, VECTOR(t_params_file)};
	if (!parse_params(&params, ARGV(ac, av)) || params.files.length == 0)
	{
		print_usage();
		return (1);
	}
	if (!compile(&params))
		return (1);
	return (0);
}
