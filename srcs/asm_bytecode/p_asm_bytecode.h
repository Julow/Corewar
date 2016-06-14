/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_asm_bytecode.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:09:44 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 18:09:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_ASM_BYTECODE_H
# define P_ASM_BYTECODE_H

# include "ft/ft_hmap.h"

# include "asm_bytecode.h"
# include "asm_data.h"

typedef struct s_asm_bytecode	t_asm_bytecode;
typedef struct s_label_ref		t_label_ref;

/*
** ========================================================================== **
*/

struct			s_label_ref
{
	uint32_t		offset;
	uint32_t		instr_begin;
	t_sub			name;
	bool			short_value;
};

struct			s_asm_bytecode
{
	t_dstr			bcode;
	uint32_t		offset;
	t_vector		labels_ref;
	t_label			*next_label;
	t_hmap			*labels_loc;
};

void			bcode_raw(t_asm_bytecode *b, uint32_t data, uint32_t len);

void			bcode_gen(t_asm_bytecode *b, t_asm const *src);
void			bcode_args(t_asm_bytecode *b,
					t_instr const *instr, uint32_t instr_begin);

void			labels_ref_solve(t_dstr *bcode, t_asm_bytecode const *b);

void			asm_header(t_out *out,
					t_asm_bytecode const *b, t_asm const *src);

#endif
