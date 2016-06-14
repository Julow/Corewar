/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:54:29 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 18:42:10 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_LOADER_H
# define VM_LOADER_H

# include "ft/ft_dstr.h"
# include "ft/ft_vector.h"
# include "ft/libft.h"

# include "vm.h"

typedef struct s_vm_loader			t_vm_loader;
typedef struct s_vm_loader_play		t_vm_loader_play;

/*
** ========================================================================== **
** VM Loader
*/

/*
** represent a player to load
** TODO: move to private
*/
struct			s_vm_loader_play
{
	int32_t			id;
	t_dstr			file_name;
};

/*
** vm_loader object
** -
** player		=> vector of t_vm_loader_play to load
** -
** VM_LOADER() init a vm_loader object
*/
struct			s_vm_loader
{
	t_vector		player;
};

# define VM_LOADER()	((t_vm_loader){VECTOR(t_vm_loader_play)})

/*
** Load vm from a vm_loader object
*/
bool			load_vm(t_vm_loader const *loader, t_vm *vm);

/*
** Return the next available player id
*/
int32_t			next_player_id(t_vm_loader const *loader, int32_t id);

/*
** Destroy vm_loader
*/
void			vm_loader_destroy(t_vm_loader *loader);

#endif
