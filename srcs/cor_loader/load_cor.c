/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 19:25:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/20 19:59:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file.h"
#include "ft/ft_printf.h"

#include "cor_loader.h"
#include "op.h"
#include "utils.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define LOAD_ERR(DST, STR, ...)		ft_asprintf(DST, STR, ##__VA_ARGS__), false

static bool		load_header(int fd, t_cor *dst, t_dstr *err)
{
	t_header		head;

	if (read(fd, &head, sizeof(t_header)) != sizeof(t_header))
		return (LOAD_ERR(err, "Truncated file"));
	if (B32_REV(head.magic) != COREWAR_EXEC_MAGIC)
		return (LOAD_ERR(err, "Not a corewar file"));
	dst->prog_size = B32_REV(head.prog_size);
	if (dst->prog_size > CHAMP_MAX_SIZE)
		return (LOAD_ERR(err, "Program too heavy"));
	head.prog_name[PROG_NAME_LENGTH] = '\0';
	dst->name = ft_aprintf("%s", head.prog_name);
	head.comment[COMMENT_LENGTH] = '\0';
	dst->comment = ft_aprintf("%s", head.comment);
	dst->bytecode = MALLOC(dst->prog_size + MAX_OP_SIZE - 1);
	return (true);
}

static bool		load_bytecode(int fd, t_cor *dst, t_dstr *err)
{
	char			tmp;

	if (read(fd, dst->bytecode, dst->prog_size) < dst->prog_size)
		return (LOAD_ERR(err, "Truncated file"));
	if (read(fd, &tmp, 1) > 0)
		return (LOAD_ERR(err, "Prog size does not match"));
	return (true);
}

bool			load_cor(t_sub file, t_cor *dst, t_dstr *err)
{
	int				fd;
	bool			r;

	if ((fd = ft_open(file, O_RDONLY)) < 0)
	{
		ft_asprintf(err, "%s", strerror(errno));
		return (false);
	}
	r = false;
	if (!load_header(fd, dst, err))
		;
	else if (!load_bytecode(fd, dst, err))
		cor_destroy(dst);
	else
		r = true;
	close(fd);
	return (r);
}
