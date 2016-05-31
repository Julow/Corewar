/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:19:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 15:29:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGV_H
# define PARSE_ARGV_H

# include "ft/argv.h"
# include "ft/libft.h"

# include "main.h"
# include "vm_loader.h"

typedef struct s_parse_argv		t_parse_argv;

/*
** ========================================================================== **
** Parse argv
*/

/*
** Fill main with args data
** Return false on error true otherwise
*/
bool			parse_argv(t_main *main, int argc, char *const *argv);

/*
** -
*/

struct			s_parse_argv
{
	t_argv			args;
	uint32_t		flags;
	uint32_t		dump_cycles;
	t_vm_loader		vm_loader;
};

# define PARSE_ARGV_ERR(S,...)	ft_dprintf(2, "corewar: "S"%n", ##__VA_ARGS__)

#endif
