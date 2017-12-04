/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:55 by gmalpart          #+#    #+#             */
/*   Updated: 2017/11/30 16:46:59 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_net_line.h"

int			get_next_line(const int fd, char **line)
{
	int		ret;
	char	*buf;

	buf = ft_strnew(BUFF_SIZE);
	while (ret = read(fd, buf, BUFF_SIZE) > 0 &&)
	{
	}
}
