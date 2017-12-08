/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:55 by gmalpart          #+#    #+#             */
/*   Updated: 2017/12/07 22:44:02 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_net_line.h"


//change to integer 
//because i only need the position plus one to avoid printing the \n
int		ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i++])
			return (-1);
	}
	return (i);
}

// ^ funcion addition


// maybe i'll have to change it 
int				get_buffer(static char *str, t_list store)
{
	int			i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (1);
}

t_list			create_element(int buffer, static char *str)
{
	t_store		container;
	
	container = ft_memamlloc(sizeof(t_store));
	container->x = get_buffer()
}


int				get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*buf;
	t_list			*storage;

	if (!line || fd <= 0)
		return (0);
	if (ft_strchr(line, \n) == NULL)
		line = NULL;
	buf = ft_strnew(BUFF_SIZE);
	if ()
	while (ret = read(fd, buf, BUFF_SIZE) > 0 &&)
	{
		
	}
}
