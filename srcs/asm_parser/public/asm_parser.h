/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:45:27 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/07 13:06:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PARSER_H
# define ASM_PARSER_H

# include "ft/ft_hmap.h"
# include "ft/ft_in.h"
# include "ft/ft_vector.h"
# include "ft/libft.h"

# include "op.h"

typedef struct s_asm		t_asm;
typedef struct s_instr		t_instr;
typedef struct s_instr_arg	t_instr_arg;
typedef enum e_instr_arg_e	t_instr_arg_e;
typedef union e_instr_arg_u	t_instr_arg_u;

/*
** ========================================================================== **
** ASM struct
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

struct			s_instr
{
	uint32_t		op_code;
	t_instr_arg		args[MAX_ARGS_NUMBER];
	uint32_t		arg_count;
};

struct			s_asm
{
	t_dstr			name;
	t_dstr			comment;
	t_vector		instr;
	t_hmap			*labels;
};

/*
** ========================================================================== **
** Corewar asm parser
*/

/*
** Parse an asm file
** Return true on success, false on error
** On error, 'err' is filled with the error string
*/
bool			parse_asm(t_in *in, t_asm *dst, t_dstr *err);

#endif
