/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:54:29 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/10 16:36:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_LOADER_H
# define VM_LOADER_H

# include "ft/ft_vector.h"
# include "ft/libft.h"

# include "vm.h"

typedef struct s_vm_loader			t_vm_loader;
typedef struct s_vm_loader_player	t_vm_loader_player;

/*
** ========================================================================== **
** VM Loader
*/

/*
** represent a player to load
*/
struct			s_vm_loader_player
{
	uint32_t		id;
	char const		*program;
};

/*
** vm_loader object
** -
** player		=> vector of t_vm_loader_player to load
** -
** VM_LOADER() init a vm_loader object
*/
struct			s_vm_loader
{
	t_vector		player;
};

# define VM_LOADER()	((t_vm_loader){VECTOR(t_vm_loader_player)})

/*
** Load vm from a vm_loader object
*/
bool			load_vm(t_vm_loader const *loader, t_vm *vm);

/*
** Destroy vm_loader
*/
void			vm_loader_destroy(t_vm_loader *loader);

#endif
