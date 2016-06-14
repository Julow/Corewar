/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:37:38 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/14 18:41:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "parse_argv.h"

bool			push_player(t_parse_argv *argv, int32_t id, t_sub file_name)
{
	t_vm_loader_play	player;

	player = (t_vm_loader_play){id, ft_aprintf("%ts", file_name)};
	ft_vpush(&argv->vm_loader.player, &player, 1);
	return (true);
}
