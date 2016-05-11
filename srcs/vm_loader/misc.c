/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:19:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 16:57:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_loader.h"

int32_t			next_player_id(t_vm_loader const *loader, int32_t id)
{
	uint32_t		i;

	while (true)
	{
		i = 0;
		while (true)
		{
			if (i >= loader->player.length)
				return (id);
			if (VGETC(t_vm_loader_player, loader->player, i).id == id)
				break ;
			i++;
		}
		id++;
	}
}

void			vm_loader_destroy(t_vm_loader *loader)
{
	t_vm_loader_player	*player;

	player = VECTOR_IT(loader->player);
	while (VECTOR_NEXT(loader->player, player))
		ft_dstrclear(&player->file_name);
	ft_vclear(&loader->player);
}
