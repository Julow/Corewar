/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:19:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/07 12:58:42 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGV_H
# define PARSE_ARGV_H

# include "ft/argv.h"
# include "ft/libft.h"

# include "main.h"
# include "vm_loader.h"

typedef struct s_parse_argv		t_parse_argv;
typedef struct s_argv_opt		t_argv_opt;

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

/*
** ========================================================================== **
** Tools
*/

struct			s_argv_opt
{
	t_sub			opt;
	bool			(*f)(t_parse_argv*);
};

bool			push_player(t_parse_argv *argv, int32_t id, t_sub file_name);

bool			parse_opt_dump(t_parse_argv *argv);
bool			parse_opt_n(t_parse_argv *argv);
bool			parse_opt_a(t_parse_argv *argv);
bool			parse_opt_h(t_parse_argv *argv);

#endif
