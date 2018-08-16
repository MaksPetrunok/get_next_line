/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:30:11 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/14 18:38:50 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//BONUSES:
//use single static variable
//manage multiple file descriptors

/*
** Check if string *s contains \n. If it does - set *s equal string before \n
** and write remaining part (after \n to the list as remainder.
*/
static int	get_line(char **s, t_list rem)
{

}

/*
** Check if rem_buff list has remainder for file descriptor fd. If it does -
** remove part of string before \n (or entire string if there is no \n) from
** rem_buff and return it.
*/
static char	get_rem(int fd, t_list rem_buff)
{

}

int	get_next_line(const int fd, char **line)
{
	static t_list	*rem_buf;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				n;

	tmp = get_rem(fd, rem_buff);
	if (get_line(&tmp, rem_buff))
	{
		*line = tmp;
		return (1);
	}
	while (n = read(fd, &buff, BUFF_SIZE))
	{
		buff[n] = 0;
		if (
		*line = buff;
		return (1);
	}

	return (0);
}
