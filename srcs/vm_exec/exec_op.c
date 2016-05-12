/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:23:12 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/12 20:44:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static t_op_f const		g_op_functions[] = 
{
	[0x1]	= &op_live,
	[0x2]	= &op_ld,
	[0x3]	= &op_st,
	[0x4]	= &op_add,
	[0x5]	= &op_sub,
	[0x6]	= &op_and,
	[0x7]	= &op_or,
	[0x8]	= &op_xor,
	[0x9]	= &op_zjmp,
	[0xa]	= &op_ldi,
	[0xb]	= &op_sti,
	[0xc]	= &op_fork,
	[0xd]	= &op_lld,
	[0xe]	= &op_lldi,
	[0xf]	= &op_lfork,
	[0x10]	= &op_aff
};

static uint8_t		get_ocp(t_vm *vm, t_op const *op, t_process *process)
{
	uint8_t				ocp;
	uint32_t			i;

	if (op->has_ocp)
	{
		ocp = VM_GET1(vm, process->reg_pc);
		PC_INC(process, 1);
		return (ocp);
	}
	ocp = 0;
	i = 0;
	while (i < op->arg_n)
	{
		if (op->arg_types[i] == T_REG)
			ocp |= OCP_VALUE(i, REG_CODE);
		else if (op->arg_types[i] == T_DIR)
			ocp |= OCP_VALUE(i, DIR_CODE);
		else if (op->arg_types[i] == T_IND)
			ocp |= OCP_VALUE(i, IND_CODE);
		else
			ASSERT(false);
		i++;
	}
	return (ocp);
}

bool				exec_op(t_vm *vm, t_process *process)
{
	t_op const			*op;
	uint32_t			args[MAX_ARGS_NUMBER];
	uint8_t				ocp;
	uint32_t			i;
	uint32_t			value_size;

	i = VM_GET1(vm, process->reg_pc);
	PC_INC(process, 1);
	if (i < 1 || i > OPCODE_COUNT)
		return (true);
	op = &g_op_tab[i];
	ocp = get_ocp(vm, op, process);
	i = 0;
	while (i < op->arg_n)
	{
		if (OCP_GET(ocp, i) == REG_CODE && op->arg_types[i] & T_REG)
			value_size = 1;
		else if (OCP_GET(ocp, i) == DIR_CODE && op->arg_types[i] & T_DIR)
			value_size = op->short_value ? 2 : 4;
		else if (OCP_GET(ocp, i) == IND_CODE && op->arg_types[i] & T_IND)
			value_size = 2;
		else
			return (ASSERT(false));
		args[i] = vm_get(vm, process->reg_pc, value_size);
		PC_INC(process, value_size);
		i++;
	}
	ft_printf("P #%u EXEC %s, PC => %u%n", process->player_idx, op->name, process->reg_pc);
	return (g_op_functions[op->op_code](vm, process, args, ocp));
}
