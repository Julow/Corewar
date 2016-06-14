/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 09:58:47 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_file_in.h"
#include "ft/ft_printf.h"

#include "asm_parser.h"
#include "p_asm.h"

/*
** ========================================================================== **
** DEBUG
*/

static void		print_instr_arg(t_asm const *s, t_instr_arg const *arg)
{
	if (arg->e == INSTR_ARG_REG)
		ft_printf("r%u", arg->u.reg);
	else if (arg->e == INSTR_ARG_DIR)
		ft_printf("%%%d", arg->u.dir);
	else if (arg->e == INSTR_ARG_IND)
		ft_printf("%d", arg->u.ind);
	else if (arg->e == INSTR_ARG_LABEL)
		ft_printf("%%:%ts", DSTR_SUB(arg->u.label));
}

static void		print_instr(t_asm const *s, t_instr const *instr)
{
	uint32_t		i;

	ft_printf("%s ", instr->op->name);
	i = 0;
	while (i < instr->arg_count)
	{
		if (i > 0)
			ft_printf(", ");
		print_instr_arg(s, &instr->args[i]);
		i++;
	}
	ft_printf("%n");
}

static void		print_asm(t_asm const *s)
{
	uint32_t		i;

	ft_printf(".name \"%ts\"\n"
			".comment \"%ts\"\n%n",
		DSTR_SUB(s->name), DSTR_SUB(s->comment));
	i = 0;
	while (i < s->instr.length)
	{
		print_instr(s, VECTOR_GET(s->instr, i));
		i++;
	}
}

/*
** ========================================================================== **
*/

static bool		parse_file(t_sub file, t_asm *dst, t_dstr *err)
{
	t_file_in		*in;
	bool			ret;

	if ((in = ft_in_open(file.str // LOL PAS BIEN
			)) == NULL)
	{
		ft_asprintf(err, "Not a valid file");
		return (false);
	}
	ret = parse_asm(V(in), dst, err);
	ft_in_close(in);
	return (ret);
}

static bool		gen_file(t_sub file, t_asm *dst, t_dstr *err)
{
	return (true);
	(void)file;
	(void)dst;
	(void)err;
}

bool			compile_file(t_params_file const *f, t_dstr *err)
{
	t_asm			dst;

	if (!parse_file(f->file, &dst, err))
		return (false);
	print_asm(&dst);
	if (!gen_file(f->file, &dst, err))
		return (false);
	return (true);
}
