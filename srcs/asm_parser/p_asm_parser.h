/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_asm_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:50:55 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/13 19:05:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_ASM_PARSER_H
# define P_ASM_PARSER_H

# include "ft/tokenizer.h"
# include "asm_parser.h"

typedef struct s_asm_parser		t_asm_parser;

/*
** ========================================================================== **
*/

enum			e_asm_tokens
{
	TOKEN_UNKNOWN = 0,
	TOKEN_SPACE,
	TOKEN_ENDL,
	TOKEN_QUOTE,
	TOKEN_COMMENT,
	TOKEN_COLON
};

enum			e_asm_token_comment
{
	TOKEN_COMMENT_UNKNOWN = 0,
	TOKEN_COMMENT_ESCAPED,
	TOKEN_COMMENT_ENDL
};

enum			e_asm_token_string
{
	TOKEN_STRING_UNKNOWN = 0,
	TOKEN_STRING_ESCAPED,
	TOKEN_STRING_ENDL,
	TOKEN_STRING_QUOTE
};

enum			e_asm_token_instr
{
	TOKEN_INSTR_UNKNOWN = 0,
	TOKEN_INSTR_MODULO,
	TOKEN_INSTR_LABEL,
	TOKEN_INSTR_SPACE,
	TOKEN_INSTR_ENDL,
	TOKEN_INSTR_COMMA,
	TOKEN_INSTR_COMMENT,
};

struct			s_asm_parser
{
	t_tokenizer		t;
	t_asm			dst;
	t_dstr			*err;
	uint32_t		line;
};

/*
** Parse
*/

bool			parse_string(t_asm_parser *p, t_dstr *dst);
bool			parse_comment(t_asm_parser *p);

bool			parse_instr_arg(t_asm_parser *p, t_instr_arg *dst);

bool			parse_instr(t_asm_parser *p, t_sub name);

bool			err_unexpected_token(t_asm_parser *p);
bool			err_unexpected_eof(t_asm_parser *p);

/*
** Check
*/

bool			check_instr(t_asm_parser const *p,
					t_instr const *instr, t_dstr *err);
bool			check_labels(t_asm_parser const *p, t_dstr *err);

/*
** ========================================================================== **
** Utils
** TODO: move
*/

# define TOKEN_DEF(S,DATA)	((t_token_def){SUBC(S), V(DATA)})

t_token_map		*ft_token_map_build(t_vector const *t);

#endif
