/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/21 16:52:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file.h"
#include "ft/file_in.h"
#include "ft/file_out.h"
#include "ft/ft_printf.h"

#include "asm_bytecode.h"
#include "asm_parser.h"
#include "p_asm.h"

#include <errno.h>
#include <fcntl.h>
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

static bool		gen_file(t_sub file, t_asm const *src,
					uint32_t open_flags, t_dstr *err)
{
	t_file_out		*out;
	bool			r;
	int				fd;

	if ((fd = ft_open(file, O_WRONLY | O_CREAT | open_flags)) < 0)
	{
		ft_asprintf(err, "Cannot create '%ts': %s", file, strerror(errno));
		return (false);
	}
	out = ft_out_fdopen(fd);
	r = bytecode_asm(V(out), src);
	ft_out_close(out);
	return (r);
}

bool			compile_file(t_params_file const *f,
					t_dstr *err, uint32_t flags)
{
	t_asm			dst;
	bool			r;

	if (!parse_file(f->file, &dst, err))
		return (false);
	if (flags & FLAG_VERBOSE)
		print_asm(&dst);
	r = gen_file(DSTR_SUB(f->dest), &dst,
			((flags & FLAG_FORCE) ? O_TRUNC : O_EXCL), err);
	asm_destroy(&dst);
	return (true);
}
