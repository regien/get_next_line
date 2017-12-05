/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:48:17 by gmalpart          #+#    #+#             */
/*   Updated: 2017/12/04 16:54:37 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_F
# define GET_NEXT_LINE_F
# define BUFF_SIZE 32
# include "libft/libft.h"

typedef	struct	s_store
{
	int			x;
	int			y;
	char		*str;
}				t_store;

int			get_next_line(const int fd, char **line);

#endif
