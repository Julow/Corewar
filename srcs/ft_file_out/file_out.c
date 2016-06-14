/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:13:12 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 14:39:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_out.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void		file_out_flush(t_file_out *out)
{
	if (out->out.buff_i > 0)
		write(out->fd, out->out.buff, out->out.buff_i);
	out->out.buff_i = 0;
}

// TODO: move
t_file_out		*ft_out_open(t_sub file)
{
	char			file_name[file.length + 1];
	int				fd;
	t_file_out		*out;

	ft_memcpy(file_name, file.str, file.length);
	file_name[file.length] = '\0';
	if ((fd = open(file_name,
			O_WRONLY | O_CREAT | O_EXCL | O_EXLOCK, 0644)) < 0)
		return (NULL);
	if ((out = ft_out_fdopen(fd)) == NULL)
		return (NULL);
	out->opened = true;
	return (out);
}

t_file_out		*ft_out_fdopen(int fd)
{
	t_file_out		*out;

	out = MALLOC(sizeof(t_file_out) + FILE_OUT_BUFF_SIZE);
	*out = (t_file_out){
		OUT(ENDOF(out), FILE_OUT_BUFF_SIZE, &file_out_flush),
		fd,
		false
	};
	return (out);
}

void			ft_out_close(t_file_out *out)
{
	if (out->opened)
		close(out->fd);
	free(out);
}
