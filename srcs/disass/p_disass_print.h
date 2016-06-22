/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_disass_print.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 21:42:34 by juloo             #+#    #+#             */
/*   Updated: 2016/06/22 10:22:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_DISASS_PRINT_H
# define P_DISASS_PRINT_H

# include "ft/ft_colors.h"
# include "p_disass.h"

/*
** ========================================================================== **
*/

# define PRINT_INVALID_OP	C_RED "# Invalid op: %.2hhx" C_RESET
# define PRINTR_INVALID_OP	"# Invalid op: %.2hhx"

# define PRINT_INSTR_NAME	C_LGREEN "%-5s" C_RESET
# define PRINTR_INSTR_NAME	"%s "

# define PRINT_ARG_REG		"r%u"
# define PRINT_ARG_DIR		"%%" C_YELLOW "%d" C_RESET
# define PRINT_ARG_IND		C_YELLOW "%d" C_RESET

# define PRINTR_ARG_REG		"r%u"
# define PRINTR_ARG_DIR		"%%%d"
# define PRINTR_ARG_IND		"%d"

# define PRINT_STRING		".%ts " C_LYELLOW "\"%ts\"" C_RESET "%n"
# define PRINTR_STRING		".%ts \"%ts\"%n"

/*
** -
*/
# define PRINT(F,S)		(((F) & DISASS_F_RAW) ? PRINTR_##S : PRINT_##S)

#endif
