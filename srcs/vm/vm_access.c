/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:18:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/16 18:39:12 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t		vm_get(t_vm const *vm, uint32_t i, uint32_t n)
{
	uint8_t *const	arena = vm->arena + (i % MEM_SIZE);

	if (n == 1)
		return (VM_GET1(vm, i));
	if (n == 2)
		return ((uint16_t)((arena[0] << 8) | arena[1]));
	return ((arena[0] << 24)
		| (arena[0] << 16)
		| (arena[0] << 8)
		| (arena[0] << 0));
}

void			vm_set(t_vm *vm, uint32_t i, uint32_t value, uint32_t n)
{
	uint8_t *const	arena = vm->arena + (i % MEM_SIZE);

	while (n-- > 0)
	{
		arena[n] = value & 0xFF;
		value >>= 8;
	}
}
