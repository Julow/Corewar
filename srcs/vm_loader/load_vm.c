/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:21:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 17:11:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "utils.h"
#include "vm_loader.h"

#include <fcntl.h>
#include <unistd.h>

#define LOAD_ERROR(E,F,...)	ft_dprintf(2,"corewar: %ts: "E"%n",F,##__VA_ARGS__)

static bool		load_champion(t_vm *vm, t_vm_loader_player const *p,
					uint32_t arena_offset, t_player *dst)
{
	header_t		head;
	int				fd;

	if ((fd = open(p->file_name.str, O_RDONLY)) < 0)
		LOAD_ERROR("Cannot open file", DSTR_SUB(p->file_name.str));
	else if (read(fd, &head, sizeof(header_t)) != sizeof(header_t))
		LOAD_ERROR("Invalid file", DSTR_SUB(p->file_name.str));
	else if (B32_REV(head.magic) != COREWAR_EXEC_MAGIC)
		LOAD_ERROR("Not a corewar file", DSTR_SUB(p->file_name.str));
	else if (B32_REV(head.prog_size) > CHAMP_MAX_SIZE)
		LOAD_ERROR("Program too heavy", DSTR_SUB(p->file_name.str));
	else if (read(fd, vm->arena + arena_offset, B32_REV(head.prog_size)) != B32_REV(head.prog_size))
		LOAD_ERROR("Truncated file", DSTR_SUB(p->file_name.str));
	else if (read(fd, &head, 1) > 0)
		LOAD_ERROR("Prog size does not match", DSTR_SUB(p->file_name.str));
	else
	{
		*dst = PLAYER_INIT(p->id);
		ft_dstradd(&dst->name, ft_sub(head.prog_name, 0, -1));
		ft_dstradd(&dst->comment, ft_sub(head.comment, 0, -1));
		return (true);
	}
	return (false);
}

bool			load_vm(t_vm_loader const *loader, t_vm *vm)
{
	uint32_t			arena_delta;
	uint32_t			i;

	*vm = VM_INIT();
	if (loader->player.length == 0 || loader->player.length > MAX_PLAYERS)
		return (false); // Too many players
	arena_delta = MEM_SIZE / loader->player.length;
	vm->arena = NEW_N(char, MEM_SIZE);
	i = 0;
	while (i < loader->player.length)
		if (!load_champion(vm, VECTOR_GET(loader->player, i),
				arena_delta * i, &vm->players[i]))
		{
			vm_destroy(vm);
			return (false);
		}
		else
			i++;
	vm->player_count = loader->player.length;
	return (true);
}