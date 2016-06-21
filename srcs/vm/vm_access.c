/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:18:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/21 12:44:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define POSITIVE_MOD(A, MD)	(((A) < 0) ? (A) % (MD) + (MD) : (A) % (MD))

uint32_t		vm_get(t_vm const *vm, int32_t i, uint32_t n)
{
	uint8_t *const	arena = vm->arena;
	uint32_t		value;

	value = 0;
	i = POSITIVE_MOD(i, MEM_SIZE);
	n += i;
	while (i < n)
	{
		value <<= 8;
		value |= arena[i % MEM_SIZE];
		i++;
	}
	return (value);
}

void			vm_set(t_vm *vm, int32_t i, uint32_t value, uint32_t n)
{
	uint8_t *const	arena = vm->arena;

	i = POSITIVE_MOD(i, MEM_SIZE);
	while (n-- > 0)
	{
		arena[(n + i) % MEM_SIZE] = (uint8_t)(value & 0xFF);
		value >>= 8;
	}
}
