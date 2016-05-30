/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:13:13 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/30 16:10:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_vm_exec.h"

bool		op_aff(t_vm *vm, t_process *process, uint32_t const *args,
						uint8_t args_types)
{
	LISTENER(vm, on_aff, process, GET_VALUE(vm, process, args, args_types, 0));
	return (true);
}
