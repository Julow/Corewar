/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 19:19:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/file_out.h"
#include "ft/ft_printf.h"

#include "asm_bytecode.h"
#include "asm_parser.h"
#include "p_asm.h"

#include <errno.h>
#include <string.h>

static bool		parse_file(t_sub file, t_asm *dst, t_dstr *err)
{
	t_file_in		*in;
	bool			ret;

	if ((in = ft_in_open(file)) == NULL)
	{
		ft_asprintf(err, "Not a valid file");
		return (false);
	}
	ret = parse_asm(V(in), dst, err);
	ft_in_close(in);
	return (ret);
}

static bool		gen_file(t_sub file, t_asm const *src, t_dstr *err)
{
	t_file_out		*out;
	bool			r;

	if ((out = ft_out_open(file)) == NULL)
	{
		ft_asprintf(err, "Cannot create '%ts': %s", file, strerror(errno));
		return (false);
	}
	r = bytecode_asm(V(out), src);
	ft_out_close(out);
	return (r);
}

bool			compile_file(t_params_file const *f, t_dstr *err)
{
	t_asm			dst;

	if (!parse_file(f->file, &dst, err))
		return (false);
	// print_asm(&dst);
	if (!gen_file(DSTR_SUB(f->dest), &dst, err))
		return (false);
	return (true);
}
