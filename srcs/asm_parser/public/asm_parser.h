/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:45:27 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/08 16:25:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PARSER_H
# define ASM_PARSER_H

# include "ft/ft_in.h"
# include "ft/libft.h"

# include "asm_data.h"

/*
** ========================================================================== **
** Corewar asm parser
*/

/*
** Parse an asm file
** Return true on success, false on error
** On error, 'err' is filled with the error string
*/
bool			parse_asm(t_in *in, t_asm *dst, t_dstr *err);

#endif
