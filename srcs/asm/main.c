/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:04:46 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/02 19:17:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/argv.h"
#include "ft/ft_printf.h"

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

int				main(int ac, char **av)
{
	t_params		params;

	params = (t_params){0, VECTOR(t_params_file)};
	if (!parse_params(&params, ARGV(ac, av)))
		return (print_usage(), 1);

	{
		uint32_t			i;
		t_params_file const	*f;

		ft_printf("flags=%.1b%n", params.flags);
		i = 0;
		while (i < params.files.length)
		{
			f = VECTOR_GET(params.files, i);
			ft_printf("COMPILE %ts TO %ts.%n", f->file, DSTR_SUB(f->dest));
			i++;
		}
	}

	return (0);
}
