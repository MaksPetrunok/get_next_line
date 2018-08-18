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
** Append buffer before \n to str, write buffer remainder ot rem_buff
** and return 1.
** If there is no \n in buffer append entire buffer to str and return 0.
** If there is no buffer return -1.
*/
static int	append_buff(char *buff, char **str, t_list *rem)
{
    return (0);
}

/*
** Check if rem_buff list has remainder for file descriptor fd.
** If it does:
** — if remainder contains \n - copy remainder before \n and return 1.
** - if there is no \n in remainder - copy remainder to str and return 0.
** If there is no remainder for fd - return 0.
*/
static int	get_rem(int fd, t_list rem_buff, char *str)
{
    return (0);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*rem_buf;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				n;

    tmp = 0;
    if (get_rem(fd, rem_buff, &tmp))
    {
	   	*line = tmp;
    	return (1);
	}
	while (n = read(fd, &buff, BUFF_SIZE))
	{
		buff[n] = 0;
		if (append_buff(buff, &tmp, rem_buff))
		{
	    	*line = buff;
	    	return (1);
		}
	}
	//check what’s going on when \n not found or file is empty.
	return (0);
}
