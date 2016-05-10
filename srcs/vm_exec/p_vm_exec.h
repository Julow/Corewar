/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_vm_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:18:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/10 16:17:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "vm_exec.h"

/*
** ========================================================================== **
*/

/*
** op
** -
** vm			=> current vm
** process		=> current process index
** args			=> unpacked arguments
** ocp			=> arguments types
*/
typedef bool	(*t_op_f)(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);

/*
** Return the type of the Ith arg
*/
# define OCP_GET(OCP, I)		(((OCP) << (8 - (((I) + 1) * 2))) & 0b11)
# define GET_VALUE(V,P,A,T,I)	get_value(V, P, (A)[I], OCP_GET(T, I))
# define GET_LVALUE(V,P,A,T,I)	get_lvalue(V, P, (A)[I], OCP_GET(T, I))

/*
** Exec the next instruction of the process at index process_index
*/
bool			exec_op(t_vm *vm, uint32_t process_index);

/*
** op_fct proto
*/
bool			op_add(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_aff(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_and(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_fork(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_ld(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_ldi(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_lfork(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_live(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_lld(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_lldi(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_or(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_st(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_sti(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_sub(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_xor(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
bool			op_zjump(t_vm *vm, uint32_t process,
					uint32_t const *args, uint8_t args_types);
#endif
