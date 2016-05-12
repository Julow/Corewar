/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:18:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 17:45:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t		vm_get(t_vm const *vm, uint32_t i, uint32_t n)
{
	char *const		arena = vm->arena + (i % MEM_SIZE);
	uint32_t		value;

	value = 0;
	i = 0;
	while (i < n)
		value = (value << 8) | arena[i++];
	return (value);
}

void			vm_set(t_vm *vm, uint32_t i, uint32_t value, uint32_t n)
{
	char *const		arena = vm->arena + (i % MEM_SIZE);

	i = 0;
	while (i < n)
	{
		arena[i++] = value & 0xFF;
		value >>= 8;
	}
}
