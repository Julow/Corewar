/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:45:27 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/06 13:00:44 by jaguillo         ###   ########.fr       */
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
typedef enum e_instr_arg	t_instr_arg;

/*
** ========================================================================== **
** Corewar asm parser
*/

enum			e_instr_arg
{
	INSTR_ARG_REG,
	INSTR_ARG_DIR,
	INSTR_ARG_IND,
	INSTR_ARG_LABEL
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
** Parse an asm file
** Return true on success, false on error
** On error, 'err' is filled with the error string
*/
bool			parse_asm(t_in *in, t_asm *dst, t_dstr *err);

#endif
