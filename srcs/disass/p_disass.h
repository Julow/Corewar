/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_disass.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 21:01:10 by juloo             #+#    #+#             */
/*   Updated: 2016/06/21 21:49:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_DISASS_H
# define P_DISASS_H

# include "ft/libft.h"
# include "cor_loader.h"

/*
** ========================================================================== **
** TODO: generate labels
*/

# define DISASS_F_RAW		(1 << 0)

/*
** Disass and print a cor program
*/
void			disass_cor(t_cor const *cor, uint32_t flags);

#endif
