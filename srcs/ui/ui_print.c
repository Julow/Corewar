/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:52:41 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/05/30 18:46:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ui.h"

void				print_arena(t_ui *ui)
{
	uint32_t			i;
	uint32_t			j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while(j < 64)
		{
			//get color in array
			mvprintw(i, j, "%02hhx  ", ((uint32_t *)(ui->vm->arena))[i + j]);
			j++;
		}
		printw("\n  ");
		i++;
	}
}
