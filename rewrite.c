#include "get_next_line.h"
#include <stdio.h>

void	*ft_realloc(void *src, size_t srcsize, size_t dstsize)
{
	void	*ret;

	if (!src)
		return (NULL);
	ret = ft_memalloc(dstsize);
	ft_memcpy(ret, src, ft_min(srcsize, dstsize));
	free(src);
	return (ret);
}


/*---------------------------------------------------------------*/

/*
static t_file_buff	*get_extra(int fd, t_list **extra_list)
{
	
}

int	get_next_line(int fd, char **line)
{
	static t_list	*extra_list;
	char		*ret;
	int		count;
	char		*tmps[2];
	t_file_buff	*extra;
	
	if (!line)
		return (-1);
	extra = get_extra(fd, &extra_list);

}
*/

static int	input_line(char **input, char **line, int fd, int ret)
{
	char 	*temp;
	int	len;

	// len es para encontrar la posicion de la pendejada es practicamente
	// strchr_position , aha moment, entonces cuando aloca memoria para la nueva pendejada
	// comienza despues del new line
	len = 0;
	while (input[fd][len] && input[fd][len] != '\n')
		len++;
	if (input[fd][len] == '\n')
	{
		*line = ft_strsub(input[fd], 0, len);
		temp = ft_strdup(input[fd] + len + 1);
		free(input[fd]);
		input[fd] = temp;
	}
	else if (!input[fd][len])
	{
		if (ret == BUFF_SIZE)
			return (0);
		*line = ft_strdup(input[fd]);
		free(input[fd]);
		input[fd] = NULL;
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*input[5000];
	char		*temp;
	char		buf[BUFF_SIZE + 1];
	int		ret;

	if (fd < 0 || !line)
		return (-1);
	// va a leer hasta que encuentre otro new line, sino solo va a seguir metiendo informacion al
	// input[fd]
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		// allocating memory or set a position for the fd;
		if (!input[fd])
			input[fd] = ft_strnew(0);
		buf[ret] = '\0';
		temp = ft_strjoin(input[fd], buf);
		free (input[fd]);
		input[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (!ret && (!input[fd] || !input[fd][0]))
		return (0);
	return (input_line(input, line, fd, ret));
}

int main(int argc, char **argv)
{
	int fd;
	char *buf;

	if (argc !=2)
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
