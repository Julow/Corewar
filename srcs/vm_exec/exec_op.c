/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:23:12 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/10 17:23:13 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_vm_exec.h"

static t_op_f const		g_optab[] = 
{
	[1] = &op_live,
	[2] = &op_ld,
	[3] = &op_st,
	[4] = &op_add,
	[5] = &op_sub,
	[6] = &op_and,
	[7] = &op_or,
	[8] = &op_xor,
	[9] = &op_zjmp,
	[10] = &op_ldi,
	[11] = &op_sti,
	[12] = &op_fork,
	[13] = &op_lld,
	[14] = &op_lldi,
	[15] = &op_lfork,
	[16] = &op_aff
};

bool					exec_op(t_vm *vm, uint32_t process_index)
{
	t_process *const		process = VECTOR_GET(vm->process, process_index);
	uint8_t					arg_type;
	uint32_t				args[MAX_ARGS_NUMBER];


	arg_type = 
	args = 	
}