/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 19:47:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 19:47:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor_loader.h"
#include <stdlib.h>

void			cor_destroy(t_cor *cor)
{
	ft_dstrclear(&cor->name);
	ft_dstrclear(&cor->comment);
	free(cor->bytecode);
}
