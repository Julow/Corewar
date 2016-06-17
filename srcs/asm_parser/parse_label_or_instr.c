/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label_or_instr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 15:37:59 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 17:35:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_asm_parser.h"

typedef struct { t_bits bits[BITARRAY((uint8_t)-1)]; }	t_char_map;

#define _STATIC_INIT_D(T)			static T this; static bool _init = false;
#define _STATIC_INIT_I(T, INIT)		if (!_init) { _init = true; { INIT; } }
#define _STATIC_INIT_S(T, INIT)		_STATIC_INIT_D(T) _STATIC_INIT_I(T, INIT)

#define STATIC_INIT(T, INIT)	({ _STATIC_INIT_S(T, INIT) (T const*)&this; })

static t_char_map	char_map(t_sub str)
{
	t_char_map			map;
	uint32_t			i;

	map = (t_char_map){{0}};
	i = 0;
	while (i < str.length)
	{
		BITARRAY_SET(map.bits, str.str[i]);
		i++;
	}
	return (map);
}

static bool			check_label_name(t_sub name)
{
	t_char_map const *const	allowed_chars = STATIC(t_char_map,
								this = char_map(SUBC(LABEL_CHARS)));
	uint32_t				i;

	i = 0;
	while (i < name.length)
	{
		if (!BITARRAY_GET(allowed_chars->bits, name.str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool			push_label(t_asm_parser *p, t_sub name)
{
	t_label				*label;

	if (!check_label_name(name))
	{
		ft_asprintf(p->err, "Label name '%ts' contains illegal characters",
			name);
		return (false);
	}
	if (ft_set_cget(&p->dst.label_set, &name) != NULL)
	{
		ft_asprintf(p->err, "Label '%ts' redefined", name);
		return (false);
	}
	label = ft_listadd(&p->dst.label_list, p->dst.label_list.last, name.length);
	*label = (t_label){
		SET_HEAD(),
		SUB(ENDOF(label), name.length),
		p->dst.instr.length
	};
	ft_memcpy(ENDOF(label), name.str, name.length);
	ft_set_insert(&p->dst.label_set, label, &name);
	return (true);
}

bool				parse_label_or_instr(t_asm_parser *p)
{
	t_dstr				name;
	bool				r;

	name = ft_aprintf("%ts", p->t.token);
	if (!ft_tokenize(&p->t))
		r = err_unexpected_eof(p);
	else if (((uint32_t)p->t.token_data) == TOKEN_COLON)
		r = push_label(p, DSTR_SUB(name));
	else if (((uint32_t)p->t.token_data) == TOKEN_SPACE)
		r = parse_instr(p, DSTR_SUB(name));
	else
		r = err_unexpected_token(p);
	ft_dstrclear(&name);
	return (r);
}
