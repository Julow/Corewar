/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 21:17:42 by juloo             #+#    #+#             */
/*   Updated: 2016/06/22 12:02:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "instr.h"
#include "instr_loader.h"
#include "p_disass.h"
#include "p_disass_print.h"

static void		print_instr_arg(uint32_t value, uint32_t type, uint32_t flags)
{
	if (type == REG_CODE)
		ft_printf(PRINT(flags, ARG_REG), value);
	else if (type == DIR_CODE)
		ft_printf(PRINT(flags, ARG_DIR), value);
	else if (type == IND_CODE)
		ft_printf(PRINT(flags, ARG_IND), value);
	else
		ASSERT(false);
}

static void		print_instr(t_instr const *instr, uint32_t flags)
{
	uint32_t		i;

	if (instr->op == NULL)
	{
		ft_printf(PRINT(flags, INVALID_OP), instr->op_code);
		return ;
	}
	ft_printf(PRINT(flags, INSTR_NAME), instr->op->name);
	i = 0;
	while (i < instr->op->arg_n)
	{
		if (i > 0)
			ft_printf(", ");
		print_instr_arg(instr->args[i], ARG_TYPE(*instr, i), flags);
		i++;
	}
}

void			disass_cor(t_cor const *cor, uint32_t flags)
{
	uint32_t		i;
	t_instr			instr;
	bool			r;

	ft_printf(PRINT(flags, STRING), SUBC("name"), DSTR_SUB(cor->name));
	ft_printf(PRINT(flags, STRING), SUBC("comment"), DSTR_SUB(cor->comment));
	ft_printf("%n");
	i = 0;
	while (i < cor->prog_size)
	{
		r = load_instr(&instr, cor->bytecode + i);
		print_instr(&instr, flags);
		if (!r)
			ft_printf(PRINT(flags, ERROR), SUBC("invalid instruction"));
		ft_printf("%n");
		i += instr.length;
	}
}
