/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_vm_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:18:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 14:07:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_VM_EXEC_H
# define P_VM_EXEC_H

# include "process.h"
# include "vm_exec.h"

/*
** ========================================================================== **
*/

/*
** op
** -
** vm			=> current vm
** process		=> current process
** args			=> unpacked arguments
** ocp			=> arguments types
*/
typedef bool	(*t_op_f)(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);

/*
** Return the type of the Ith arg
** TODO: replace with ARG_TYPE
*/
# define OCP_GET(OCP, I)		(((OCP) >> (8 - (((I) + 1) * 2))) & 0b11)

# define OCP_VALUE(I,V)			((V) << (8 - (((I) + 1) * 2)))

# define GET_VALUE(V,P,A,T,I)	get_value(V, P, (A)[I], OCP_GET(T, I))
# define GET_LVALUE(V,P,A,T,I)	get_lvalue(V, P, (A)[I], OCP_GET(T, I))

# define LISTENER(VM,L,...)		(_LISTENER(((VM)->listeners), L, ##__VA_ARGS__))

/*
** Set/unset bits
** -
** VAL		=> Initial value
** F		=> Flags
** SET		=> Set/unset toggle
*/
# define SET_FLAGS(VAL, FLAG, SET)	((SET) ? (VAL) | (FLAG) : (VAL) & ~(FLAG))

# define SET_CARRY(P, V)		((P)->reg_pflags = _SET_CARRY(P, (V) == 0))

/*
** Exec the next instruction of the process at index process_index
*/
bool			exec_op(t_vm *vm, t_process *process);

/*
** Return the value of an argumemt depending on its type
*/
uint32_t		get_value(t_vm const *vm, t_process *const process,
						uint32_t arg, uint32_t arg_type);
uint32_t		get_lvalue(t_vm const *vm, t_process *const process,
						uint32_t arg, uint32_t arg_type);

/*
** op_fct proto
*/
bool			op_add(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_aff(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_and(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_fork(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_ld(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_ldi(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_lfork(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_live(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_lld(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_lldi(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_or(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_st(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_sti(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_sub(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_xor(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);
bool			op_zjmp(t_vm *vm, t_process *process,
					uint32_t const *args, uint8_t args_types);

/*
** -
*/
# define _LISTENER(V,L,...)		(V.L&&(V.L(V.callback_data,##__VA_ARGS__),0))
# define _SET_CARRY(P, V)		(SET_FLAGS((P)->reg_pflags, PFLAG_CARRY, V))

#endif
