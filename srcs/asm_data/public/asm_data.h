/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:12:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/21 16:51:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_DATA_H
# define ASM_DATA_H

# include "ft/ft_dstr.h"
# include "ft/ft_list.h"
# include "ft/ft_vector.h"
# include "ft/libft.h"
# include "ft/set.h"

# include "op.h"

typedef struct s_asm		t_asm;
typedef struct s_instr		t_instr;
typedef struct s_instr_arg	t_instr_arg;
typedef enum e_instr_arg_e	t_instr_arg_e;
typedef union u_instr_arg_u	t_instr_arg_u;
typedef struct s_label		t_label;

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
	t_op const		*op;
	t_instr_arg		args[MAX_ARGS_NUMBER];
	uint32_t		arg_count;
};

/*
** Label
** -
*/

struct			s_label
{
	t_set_h			set_h;
	t_sub			name;
	uint32_t		index;
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
	t_list			label_list;
	t_set			label_set;
};

/*
** Free an asm object
*/
void			asm_destroy(t_asm *s);

/*
** -
*/

int				asm_label_cmp(t_label const *label, t_sub const *key);

#endif
