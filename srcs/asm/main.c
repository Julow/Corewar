/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:04:46 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/06 15:13:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/argv.h"
#include "ft/ft_file_in.h"
#include "ft/ft_printf.h"

#include "asm_parser.h"
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

static bool		parse_file(t_sub file, t_asm *dst, t_dstr *err)
{
	t_file_in		*in;
	bool			ret;

	if ((in = ft_in_open(file.str // LOL PAS BIEN
		)) == NULL)
		return (ft_dstradd(err, SUBC("Not a valid file")), false);
	ret = parse_asm(V(in), dst, err);
	ft_in_close(in);
	return (ret);
}

static bool		gen_file(t_sub file, t_asm *dst, t_dstr *err)
{
	return (true);
	(void)file;
	(void)dst;
}

static bool		compile_file(t_params_file const *f, t_dstr *err)
{
	t_asm			dst;

	if (!parse_file(f->file, &dst, err))
		return (false);
	if (!gen_file(f->file, &dst, err))
		return (false);
	ft_printf("COMPILE %ts TO %ts.%n", f->file, DSTR_SUB(f->dest));
	return (true);
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
	ft_dstrclear(&err);
	return (true);
}

int				main(int ac, char **av)
{
	t_params		params;

	params = (t_params){0, VECTOR(t_params_file)};
	if (!parse_params(&params, ARGV(ac, av)) || params.files.length == 0)
		return (print_usage(), 1);
	if (!compile(&params))
		return (1);
	return (0);
}
