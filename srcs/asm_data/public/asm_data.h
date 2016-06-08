/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:12:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/08 16:20:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_DATA_H
# define ASM_DATA_H

# include "ft/ft_hmap.h"
# include "ft/ft_vector.h"

# include "op.h"

typedef struct s_asm		t_asm;
typedef struct s_instr		t_instr;
typedef struct s_instr_arg	t_instr_arg;
typedef enum e_instr_arg_e	t_instr_arg_e;
typedef union u_instr_arg_u	t_instr_arg_u;

/*
** ========================================================================== **
** ASM data
*/

/*
** Argument variant
*/

enum			e_instr_arg_e
{
	INSTR_ARG_REG,
	INSTR_ARG_DIR,
	INSTR_ARG_IND,
	INSTR_ARG_LABEL
};

union			u_instr_arg_u
{
	uint32_t		reg;
	int32_t			dir;
	int32_t			ind;
	t_dstr			label;
};

struct			s_instr_arg
{
	t_instr_arg_e	e;
	t_instr_arg_u	u;
};

/*
** Instruction
** -
** op_code			=> instr opcode
** args				=> arg list
** arg_count		=> argument count
*/

struct			s_instr
{
	uint32_t		op_code;
	t_instr_arg		args[MAX_ARGS_NUMBER];
	uint32_t		arg_count;
};

/*
** Asm
** -
** name, comment	=> strings
** instr			=> instruction vector
** labels			=> labels map {label name: instr index}
*/

struct			s_asm
{
	t_dstr			name;
	t_dstr			comment;
	t_vector		instr;
	t_hmap			*labels;
};

#endif
