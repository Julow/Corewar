/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_panel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:26:11 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/07 11:48:34 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_PANEL_H
# define UI_PANEL_H

# include "ft/libft.h"
# include "ui_utils.h"

# include <ncurses.h>

typedef struct s_w_panel	t_w_panel;

/*
** ========================================================================== **
*/

# define PANEL_POS		(VEC2U(195, 0))
# define PANEL_SIZE		(VEC2U(42, 75))

struct			s_w_panel
{
	t_vm			*vm;
	WINDOW			*w;
};

# define W_P(VM)	((t_w_panel){(VM), NULL})

/*
** -
*/

void			w_panel_init(t_w_panel *w);
void			w_panel_refresh(t_w_panel *w);
void			w_panel_destroy(t_w_panel *w);

#endif
