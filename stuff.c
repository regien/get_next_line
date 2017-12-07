/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:55 by gmalpart          #+#    #+#             */
/*   Updated: 2017/12/06 19:32:46 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_net_line.h"


//change to integer 
//because i only need the position plus one to avoid printing the \n
int		ft_strchr_post(const char *s, int c)
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

/*
int				get_buffer(static char *str, t_list store)
{
	int			i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (1);
}
*/
t_list			create_element(int ret, static char *buf, t_list *storage)
{
	t_store		container;
	
	container = ft_memamlloc(sizeof(t_store));
	// posiblemente esto siempre sea 0 asi que crare otra variable para probar
	container->x = 0;
	if (ft_strchr_post(buf, '\n') == -1)
		container->y = (ft_strlen(buf) - 1);
	else
		container->y = ft_strchr_post(buf, '\n');
	//variable a modificar - temporal de y;
//	container->z = 
	return(ft_lstnew(storage, sizeof(t_store)))
}


int				get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*buf;
	t_list			*storage;
	t_store			*iterdata;

	if (!line || fd <= 0)
		return (0);
	if (ft_strchr(line, \n) == NULL)
		line = NULL;
	buf = ft_strnew(BUFF_SIZE);
	if (ret = read(fd, buf, BUFF_SIZE) > 0)
	{
		buf[ret] = '\0';
		
	}
}
