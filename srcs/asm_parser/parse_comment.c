/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:22:25 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/13 13:22:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_asm_parser.h"

static t_vector const	g_comment_token_map = VECTOR(t_token_def,
	TOKEN_DEF("\\\n", TOKEN_COMMENT_ESCAPED),
	TOKEN_DEF("\n", TOKEN_COMMENT_ENDL),
);

bool				parse_comment(t_asm_parser *p)
{
	static t_token_map const	*map = NULL;
	t_token_map const *const	old_map = p->t.token_map;

	if (map == NULL)
		map = ft_token_map_build(&g_comment_token_map);
	p->t.token_map = map;
	while (ft_tokenize(&p->t))
		if (((uint32_t)p->t.token_data) == TOKEN_COMMENT_ENDL)
		{
			p->line++;
			break ;
		}
	p->t.token_map = old_map;
	return (true);
}
