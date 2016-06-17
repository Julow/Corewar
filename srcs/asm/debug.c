/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:26:10 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 11:44:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_printf.h"

#include "asm_data.h"

#define STRING_COLOR	C_LYELLOW
#define LABEL_COLOR		C_WHITE
#define INSTR_COLOR		C_LGREEN
#define INT_COLOR		C_YELLOW

static void		print_instr_arg(t_asm const *s, t_instr_arg const *arg)
{
	if (arg->e == INSTR_ARG_REG)
		ft_printf("r%u", arg->u.reg);
	else if (arg->e == INSTR_ARG_DIR)
		ft_printf("%%" INT_COLOR "%d" C_RESET, arg->u.dir);
	else if (arg->e == INSTR_ARG_IND)
		ft_printf(INT_COLOR "%d" C_RESET, arg->u.ind);
	else if (arg->e == INSTR_ARG_LABEL)
		ft_printf(LABEL_COLOR "%%:%ts" C_RESET, DSTR_SUB(arg->u.label));
	(void)s;
}

static void		print_instr(t_asm const *s, t_instr const *instr)
{
	uint32_t		i;

	ft_printf("\t" INSTR_COLOR "%-5s" C_RESET " ", instr->op->name);
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
	t_label const	*label;

	ft_printf(".name " STRING_COLOR "\"%ts\"" C_RESET "\n"
			".comment " STRING_COLOR "\"%ts\"" C_RESET "\n%n",
		DSTR_SUB(s->name), DSTR_SUB(s->comment));
	i = 0;
	label = s->label_list.first;
	while (i < s->instr.length)
	{
		while (label != NULL && label->index <= i)
		{
			ft_printf(LABEL_COLOR "%ts:%n" C_RESET, label->name);
			label = LIST_NEXT(label);
		}
		print_instr(s, VECTOR_GET(s->instr, i));
		i++;
	}
}
