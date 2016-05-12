/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:01:56 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 12:41:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"
#include "vm.h"

#include <stdlib.h>

static void		clean_players(t_vm *vm)
{
	uint32_t		i;

	i = 0;
	while (i < vm->player_count)
	{
		ft_dstrclear(&vm->players[i].name);
		ft_dstrclear(&vm->players[i].comment);
		i++;
	}
}

void			vm_destroy(t_vm *vm)
{
	clean_players(vm);
	while (vm->process.length > 0)
		ft_listremove(&vm->process, vm->process.first);
	free(vm->arena);
}
