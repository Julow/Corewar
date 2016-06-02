/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:12:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/02 19:17:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_PARAMS_H
# define PARSE_PARAMS_H

# include "ft/argv.h"
# include "ft/ft_dstr.h"
# include "ft/ft_vector.h"

typedef struct s_params_file	t_params_file;
typedef struct s_params			t_params;

/*
** ========================================================================== **
*/

#define FLAG_VERBOSE	(1 << 0)

struct		s_params_file
{
	t_sub		file;
	t_dstr		dest;
};

struct		s_params
{
	uint32_t	flags;
	t_vector	files;
};

bool			parse_params(t_params *args, t_argv argv);

#endif
