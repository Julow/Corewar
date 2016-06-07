/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:25:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/07 11:53:07 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_LOG_H
# define UI_LOG_H

# include "ft/libft.h"
# include "ui_utils.h"

# include <ncurses.h>

typedef struct s_w_log	t_w_log;

/*
** ========================================================================== **
*/

# define LOG_POS		(VEC2U(0, 66))
# define LOG_SIZE		(VEC2U(195, 9))

struct			s_w_log
{
	t_vm			*vm;
	WINDOW			*w;
	char			logs[LOG_SIZE.y - 2][LOG_SIZE.x - 2];
	uint32_t		log_start;
};

# define W_L(VM)	((t_w_log){(VM), NULL, {}, 0})

/*
** -
*/

void			w_log_init(t_w_log *w);
void			w_log_refresh(t_w_log *w);
void			w_log_destroy(t_w_log *w);

void			w_log_log(t_w_log *w, t_sub msg);

#endif
