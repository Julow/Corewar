/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_asm_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:50:55 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/09 12:01:07 by jaguillo         ###   ########.fr       */
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
	TOKEN_COMMA,
	TOKEN_MODULO,
	TOKEN_LABEL,
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

struct			s_asm_parser
{
	t_tokenizer		t;
	t_asm			dst;
	t_dstr			*err;
	uint32_t		line;
};

#endif
