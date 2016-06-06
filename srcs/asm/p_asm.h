/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_asm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:14 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/06 15:41:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_ASM_H
# define P_ASM_H

# include "ft/ft_dstr.h"
# include "ft/libft.h"

# include "parse_params.h"

/*
** ========================================================================== **
*/

bool			compile_file(t_params_file const *f, t_dstr *err);

#endif
