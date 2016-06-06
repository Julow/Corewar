/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/06 17:16:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_file_in.h"

#include "asm_parser.h"
#include "p_asm.h"

static bool		parse_file(t_sub file, t_asm *dst, t_dstr *err)
{
	t_file_in		*in;
	bool			ret;

	if ((in = ft_in_open(file.str // LOL PAS BIEN
			)) == NULL)
		return (ft_asprintf(err, "Not a valid file"), false);
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

bool			compile_file(t_params_file const *f, t_dstr *err)
{
	t_asm			dst;

	if (!parse_file(f->file, &dst, err))
		return (false);
	if (!gen_file(f->file, &dst, err))
		return (false);
	return (true);
}
