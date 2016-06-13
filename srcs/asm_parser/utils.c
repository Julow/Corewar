/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:23:20 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/13 13:31:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_asm_parser.h"

t_token_map			*ft_token_map_build(t_vector const *t)
{
	t_token_map *const			map = NEW(t_token_map);
	uint32_t					i;

	*map = TOKEN_MAP();
	i = 0;
	while (i < t->length)
		ft_token_map(map, VECTOR_GET(*t, i++));
	return (map);
}

bool				err_unexpected_token(t_asm_parser *p)
{
	ft_asprintf(p->err, "Unexpected token '%ts'", p->t.token);
	return (false);
}

bool				err_unexpected_eof(t_asm_parser *p)
{
	ft_asprintf(p->err, "Unexpected end of line", p->t.token);
	return (false);
}
