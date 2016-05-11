/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:19:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 14:24:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_loader.h"

int32_t			next_player_id(t_vm_loader const *loader, int32_t id);
{
	uint32_t		i;

	while (true)
	{
		i = 0;
		while (true)
			if (VGETC(t_vm_loader_player, vm->player, i)->id == id)
				break ;
			else if (++i >= vm->player.length)
				return (id);
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
