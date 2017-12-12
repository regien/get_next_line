#include "get_next_line.h"
#include <stdio.h>


// plan
// 1) lee todo
// 2) todo se encarga otra funcion que retorna una parte del holder
// 		^^ recuerda devolver las new line vacias tambien

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

/* --------------------------*/
t_list				create_node(int fd, char *buf)
{
	t_fdstore		*iterdata;

	iterdata = ft_memalloc(sizeof(t_fdstore));
	iterdata->fd = fd;
	if (!iterdata->str)
		iterdata->str = ft_strnew(0);
//	aun no tengo algo definido para end
	return (ft_lstnew(iterdata, sizeof(t_fdstore)));
}

int					look_forit(t_list **fd_store, int fd)
{
	t_fdstore		*idata;
	t_list			*iter;
	
	iter = *fd_store;
	while (iter->next)
	{
		idata = iter->content;
		if (idata->fd == fd)
			return (1);
		iter = iter->next;
	}
	idata = iter->content;
	if (idata->fd == fd)
		return (1);
	return (0);
}

int					as

int					get_next_line(const int fd, char **line)
{
	static t_list	*fdstore
	char			*buf;
	int				ret;
	char			*temp;
	t_fdstore		*idata;

	if (fd < 0 || !line)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	
	while ((ret = read(fd,buf, BUFF_SIZE)) > 0)
	{
		if (!(*fdstore))
			*fdstore = create_node(fd, buf);
		else if (look_forit(&fdstore, fd) == 0)
			ft_lstadd(fdstore, create_node(fd, buf));
		
		buf[ret] = '\0';
		temp = ft_stra
	}
}

int main(int argc, char **argv)
{
	int			fd;
	char		*buf;

	if (argc != 2)
		printf("la pendejada no funciona asi\n");
	else
	{
		buf = NULL;
		if((fd = open(argv[1], O_RDONLY)) < 0)
			return (0);
		while (get_next_line(fd, &buf) > 0)
			printf("primera linea = |%s|\n", buf);
	}
	return (0);
}
