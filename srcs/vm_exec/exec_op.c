/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:23:12 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/20 15:08:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"
#include "instr_loader.h"
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

bool				exec_op(t_vm *vm, t_process *process)
{
	t_instr				instr;
	uint32_t const		old_pc = process->reg_pc;
	bool				r;

	// TODO: safe load_instr
	r = load_instr(&instr, vm->arena + process->reg_pc)
		&& g_op_functions[instr.op->op_code](vm, process, instr.args, instr.ocp);
	LISTENER(vm, on_exec, process, &instr);
	if (process->reg_pc == old_pc)
		process->reg_pc += instr.length;
	return (r);
}
