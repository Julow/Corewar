/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:08:11 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 14:23:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_data.h"

int				asm_label_cmp(t_label const *label, t_sub const *key)
{
	if (label->name.length != key->length)
		return (label->name.length - key->length);
	return (ft_memcmp(label->name.str, key->str, key->length));
}
