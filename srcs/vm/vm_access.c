/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:18:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/17 17:23:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t		vm_get(t_vm const *vm, uint32_t i, uint32_t n)
{
	uint8_t *const	arena = vm->arena + (i % MEM_SIZE);

	if (n == 1)
		return (VM_GET1(vm, i));
	if (n == 2)
		return ((int32_t)(int16_t)((arena[0] << 8) | arena[1]));
	return ((arena[0] << 24)
		| (arena[1] << 16)
		| (arena[2] << 8)
		| (arena[3] << 0));
}

void			vm_set(t_vm *vm, uint32_t i, uint32_t value, uint32_t n)
{
	uint8_t *const	arena = vm->arena + (i % MEM_SIZE);

	while (n-- > 0)
	{
		arena[n] = (uint8_t)(value & 0xFF);
		value >>= 8;
	}
}
