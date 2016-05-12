/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:18:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 12:17:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t		vm_get(t_vm const *vm, uint32_t i)
{
	char *const		arena = vm->arena + i;
	uint32_t		value;

	((char*)&value)[0] = arena[0];
	((char*)&value)[1] = arena[1];
	((char*)&value)[2] = arena[2];
	((char*)&value)[3] = arena[3];
	return (value);
}

void			vm_set(t_vm *vm, uint32_t i, uint32_t value)
{
	char *const		arena = vm->arena + i;

	arena[0] = ((char*)&value)[0];
	arena[1] = ((char*)&value)[1];
	arena[2] = ((char*)&value)[2];
	arena[3] = ((char*)&value)[3];
}
