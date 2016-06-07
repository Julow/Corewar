/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_debug_ui.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 17:29:27 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/06/07 17:54:08 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_DEBUG_UI_H
# define P_DEBUG_UI_H

/*
** debug_dump func
*/
void			dump_arena_n(t_vm const *vm, uint32_t index, uint32_t len);
void			dump_process(t_vm const *vm, bool show_registers);
void			dump_arena(t_vm const *vm, uint32_t mark);
void			dump_players(t_vm *vm);
void			dump_arena_focus(t_vm *vm, t_sub *line);

#endif
