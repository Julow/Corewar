/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:26:10 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 18:32:06 by jaguillo         ###   ########.fr       */
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
		ft_printf("%%%s%d%s", INT_COLOR, arg->u.dir, C_RESET);
	else if (arg->e == INSTR_ARG_IND)
		ft_printf("%s%d%s", INT_COLOR, arg->u.ind, C_RESET);
	else if (arg->e == INSTR_ARG_LABEL)
		ft_printf("%s%%:%ts%s", LABEL_COLOR, DSTR_SUB(arg->u.label), C_RESET);
	(void)s;
}

static void		print_instr(t_asm const *s, t_instr const *instr)
{
	uint32_t		i;

	ft_printf("\t%s%-5s%s ", INSTR_COLOR, instr->op->name, C_RESET);
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

	ft_printf(".name %s\"%ts\"%s\n"
			".comment %s\"%ts\"%s\n%n",
		STRING_COLOR, DSTR_SUB(s->name), C_RESET,
		STRING_COLOR, DSTR_SUB(s->comment), C_RESET);
	i = 0;
	label = s->label_list.first;
	while (i < s->instr.length)
	{
		while (label != NULL && label->index <= i)
		{
			ft_printf("%s%ts:%s%n", LABEL_COLOR, label->name, C_RESET);
			label = LIST_NEXT(label);
		}
		print_instr(s, VECTOR_GET(s->instr, i));
		i++;
	}
}
