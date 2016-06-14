/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 16:01:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 09:53:36 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_asm_parser.h"

static uint32_t	get_arg_type(t_instr_arg const *arg)
{
	if (arg->e == INSTR_ARG_REG)
		return (T_REG);
	else if (arg->e == INSTR_ARG_DIR)
		return (T_DIR);
	else if (arg->e == INSTR_ARG_IND)
		return (T_IND);
	else if (arg->e == INSTR_ARG_LABEL)
		return (T_DIR);
	else
	{
		ASSERT(false);
		return (0);
	}
}

bool			check_instr(t_asm_parser const *p,
					t_instr const *instr, t_dstr *err)
{
	uint32_t		i;

	if (instr->arg_count != instr->op->arg_n)
	{
		ft_asprintf(err, "Not enougth argument");
		return (false);
	}
	i = 0;
	while (i < instr->arg_count)
	{
		if (!(get_arg_type(&instr->args[i]) & instr->op->arg_types[i]))
		{
			ft_asprintf(err, "Invalid type for argument %d", i);
			return (false);
		}
		i++;
	}
	return (true);
	(void)p;
}
