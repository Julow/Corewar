/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:26:10 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 14:27:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "asm_data.h"

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
	(void)s;
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

void			print_asm(t_asm const *s)
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
