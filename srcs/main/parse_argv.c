/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:19:10 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/10 16:46:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_argv.h"

bool			parse_argv(t_main *p, int argc, char const *const *argv)
{
	t_parse_argv	argv;
	char const		*opt;

	argv = (t_parse_argv){ARGS(argc, argv), 0, 0, VM_LOADER()};
	while ()
}
