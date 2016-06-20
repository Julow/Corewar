/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 19:18:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 19:54:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_LOADER_H
# define COR_LOADER_H

# include "ft/ft_dstr.h"
# include "ft/libft.h"

typedef struct s_cor		t_cor;

/*
** ========================================================================== **
** Load a .cor program
*/

struct			s_cor
{
	t_dstr			name;
	t_dstr			comment;
	uint32_t		prog_size;
	void			*bytecode;
};

/*
** Load a .cor file
** On error, append error string to 'err' and return false
*/
bool			load_cor(t_sub file, t_cor *dst, t_dstr *err);

/*
** Destroy a cor object
** the 'cor' ptr is not free
*/
void			cor_destroy(t_cor *cor);

#endif
