/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:25:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 09:45:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_asm_parser.h"

static t_vector const	g_string_token_map = VECTOR(t_token_def,
	TOKEN_DEF("\\\"", TOKEN_STRING_ESCAPED),
	TOKEN_DEF("\n", TOKEN_STRING_ENDL),
	TOKEN_DEF("\"", TOKEN_STRING_QUOTE)
);

static bool			string_content(t_asm_parser *p, t_dstr *dst)
{
	static t_token_map const	*map = NULL;
	t_token_map const *const	old_map = p->t.token_map;

	if (map == NULL)
		map = ft_token_map_build(&g_string_token_map);
	p->t.token_map = map;
	while (ft_tokenize(&p->t))
		if (((uint32_t)p->t.token_data) == TOKEN_COMMENT_ENDL)
			p->line++;
		else if (((uint32_t)p->t.token_data) == TOKEN_QUOTE)
			break ;
		else
			ft_dstradd(dst, p->t.token);
	p->t.token_map = old_map;
	return (true);
}

bool				parse_string(t_asm_parser *p, t_dstr *dst)
{
	while (ft_tokenize(&p->t))
	{
		if (((uint32_t)p->t.token_data) == TOKEN_QUOTE)
			return (string_content(p, dst));
		if (((uint32_t)p->t.token_data) == TOKEN_ENDL)
			break ;
		if (((uint32_t)p->t.token_data) != TOKEN_SPACE)
			return (err_unexpected_token(p));
	}
	ft_asprintf(p->err, "Unexpected end of line");
	return (false);
}
