/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:21:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 20:00:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "cor_loader.h"
#include "vm_loader.h"

static bool		load_champion(t_vm *vm, t_vm_loader_play const *p,
					uint32_t arena_offset, t_player *dst)
{
	t_cor			cor;
	t_dstr			err;

	err = DSTR0();
	if (!load_cor(DSTR_SUB(p->file_name), &cor, &err))
	{
		ft_dprintf(2, "corewar: %ts: %ts%n",
			DSTR_SUB(p->file_name), DSTR_SUB(err));
		ft_dstrclear(&err);
		return (false);
	}
	*dst = PLAYER_INIT(p->id, arena_offset);
	ft_asprintf(&dst->name, "%ts", DSTR_SUB(cor.name));
	ft_asprintf(&dst->comment, "%ts", DSTR_SUB(cor.comment));
	dst->weight = cor.prog_size;
	ft_memcpy(vm->arena + arena_offset, cor.bytecode, cor.prog_size);
	ft_dstrclear(&err);
	cor_destroy(&cor);
	return (true);
}

bool			load_vm(t_vm_loader const *loader, t_vm *vm)
{
	uint32_t			arena_delta;
	uint32_t			i;

	*vm = VM_INIT();
	if (loader->player.length == 0 || loader->player.length > MAX_PLAYERS)
	{
		ft_dprintf(2, "corewar: You must have from one to four players%n");
		return (false);
	}
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
