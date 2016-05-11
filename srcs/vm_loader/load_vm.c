/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:21:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 15:05:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_loader.h"
#include <unistd.h>

static bool		load_champion(t_vm *vm, t_vm_loader_player const *p,
					uint32_t arena_offset, uint32_t player_index)
{
	t_player *const	player = vm->players + player_index;
	header_t		head;
	int				fd;

	if ((fd = open(p->file_name.str, O_RDONLY)) < 0)
		return (false); // Cannot open file
	if (read(fd, &head, sizeof(header_t)) != sizeof(header_t))
		return (false); // Invalid file
	if (head.magic != COREWAR_EXEC_MAGIC)
		return (false); // Not a corewar file
	if (head.prog_size > CHAMP_MAX_SIZE)
		return (false); // Program too heavy
	if (read(fd, vm->arena + arena_offset, head.prog_size) != head.prog_size)
		return (false); // Truncated file
	if (read(fd, &head, 1) > 0)
		return (false); // Prog size does not match
	*player = PLAYER_INIT(p->id);
	ft_dstradd(&player->name, ft_sub(header.prog_name, 0, -1));
	ft_dstradd(&player->comment, ft_sub(header.comment, 0, -1));
	return (true);
}

bool			load_vm(t_vm_loader const *loader, t_vm *vm)
{
	t_vm_loader_player const	*player;
	uint32_t					arena_offset;
	uint32_t					arena_delta;

	*vm = VM_INIT();
	if (loader->player.length > MAX_PLAYERS)
		return (false); // Too many players
	vm->arena = NEW_N(char, MEM_SIZE);
	arena_offset = 0;
	arena_delta = MEM_SIZE / loader->player.length;
	player = VECTOR_IT(loader->player);
	while (VECTOR_NEXT(loader->player, player))
	{
		if (!load_champion(vm, player, arena_offset))
		{
			vm_destroy(vm);
			return (false);
		}
		arena_offset += arena_delta;
	}
	return (true);
}
