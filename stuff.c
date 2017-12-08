/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:55 by gmalpart          #+#    #+#             */
/*   Updated: 2017/12/08 06:09:40 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//change to integer 
//because i only need the position plus one to avoid printing the \n
int		ft_strchr_post(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-2);
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


static char		*read_again_store(char *buf, t_list *storage)
{
	t_store *iterdata;

	iterdata = storage->content;
	return (buf);
}

t_list			*create_element(int ret, char *buf, t_list **storage)
{
	t_store		*container;
	
	container = ft_memalloc(sizeof(t_store));
	// posiblemente esto siempre sea 0 asi que crare otra variable para probar
	container->x = 0;
	if (ft_strchr_post(buf, '\n') == -1)
		container->y = (ft_strlen(buf) - 1);
	else
		container->y = ft_strchr_post(buf, '\n');
	//variable a modificar - temporal de y;
//	container->z = 
	return(ft_lstnew(container, sizeof(t_store)));
}


int				get_next_line(const int fd, char **line)
{
	int				ret;
	char		*buf;
	static t_list			*storage;
	t_store			*id;

	if (!line || fd <= 0)
		return (0);
	if (ft_strchr_post(*line, '\n') == -2)
		*line = NULL;
	if (!buf)
		buf = ft_strnew(BUFF_SIZE);
	else
		;
	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if(!storage)
			storage = create_element(ret, buf, &storage);
		else
			ft_lstadd(&storage, create_element(ret, buf, &storage));
	}
	id = storage->content;
	printf("id -> x = %i\n", id->x);
	printf("id -> y = %i\n", id->y);
//	free(*line);
	*line =  ft_strnew(id->y - id->x);
//	line = ft_memalloc(sizeof(char) * (20));
//	ft_memccpy(*line, buf, id->y);
	ft_strncpy(*line, buf, id->y);
	return (1);
}

int main(int argc, char **argv)
{
	int fd;
	char *buf;

	if (argc !=2)
		printf("la pendejada no funciona\n");
	else
	{
		buf = NULL;
		if((fd = open(argv[1], O_RDONLY)) < 0)
			return (0);
		if (get_next_line(fd, &buf) > 0)
			printf("primera linea = |%s|\n", buf);
	}
	return (0);
}
