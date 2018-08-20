/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:30:11 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/20 18:59:24 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//BONUSES:
//use single static variable
//manage multiple file descriptors

static void	set_rem_buff(t_list **rem, int fd, char *str)
{
	t_list	*cur;
	t_rem	*tmp;

	if (*str == '\0')
		return ;
	tmp = 0;
if (rem)
{
	cur = *rem;
	while (cur)
	{
		tmp = (t_rem *)(cur->content);
		if (tmp->id == fd)
		{
			if (tmp->str != 0)
				free((void *)(tmp->str));
			tmp->str = str;
			return ;
		}
		cur = cur->next;
	}
}
	tmp = (t_rem *)malloc(sizeof(t_rem));
	//add protection for NULL here if needed
	tmp->id = fd;
	tmp->str = str;
	if (rem)
		ft_lstadd(rem, ft_lstnew((void *)tmp, sizeof(t_rem)));
	else
		*rem = ft_lstnew((void *)tmp, sizeof(t_rem));
//printf("Remainder = %s\n", (char *)(tmp->str));
	free((void *)tmp);
}

/*
** Append buffer before \n to str, write buffer remainder ot rem_buff
** and return 1.
** If there is no \n in buffer append entire buffer to str and return 0.
*/
static int	append_buff(char *buff, char **str, int fd, t_list **rem)
{
	size_t	i;
	char	*tmp;
	char	flag;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	flag = (buff[i] == '\n');
	buff[i] = '\0';
//printf("-----------------------------------------------------------\n");

	tmp = ft_strnew(ft_strlen(buff) + ((*str == 0) ? 0 : ft_strlen(*str)));
	if (tmp == 0)
		return (-1);
	tmp =(*str == 0) ? ft_strcpy(tmp, buff) : ft_strcat(ft_strcpy(tmp, *str), buff);
	free((void *)(*str));
	*str = tmp;

//printf("Added string: %s\n", *str);
	if (flag)
	{
		set_rem_buff(rem, fd, ft_strdup(buff + i + 1));
//printf("Set to buffer: %s\n", &buff[i + 1]);
	}

    return (flag);
}

/*
** Check if rem_buff list has remainder for file descriptor fd.
** If it does:
** - if remainder contains \n - copy remainder before \n and return 1.
** - if there is no \n in remainder - copy remainder to str and return 0.
** If there is no remainder for fd - return 0.
*/
static int	get_rem(int fd, t_list *rem, char **str)
{
	t_list	*cur;
	t_rem	*tmp;
	char	*s;
	size_t	i;
	int		flag;

	tmp = 0;
	cur = rem;
	while (cur)
	{
//printf("There is some remainder\n");
		if (((t_rem *)(cur->content))->id == fd)
			break ;
		cur = cur->next;
	}
	if (cur == 0)
		return (0);
	tmp = cur->content;
	s = tmp->str;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	tmp->str = (flag = (s[i] == '\0')) ? 0 : ft_strdup(s + i + 1);
	s[i] = '\0';
	*str = ft_strdup(s);
	free((void *)s);
	return (flag);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*rem_buff;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				n;
	int				append;

    tmp = 0;
    if (get_rem(fd, rem_buff, &tmp))
    {
	   	*line = tmp;
    	return (1);
	}
	while ((n = read(fd, &buff, BUFF_SIZE)) > 0)
	{
printf("\n\n========GET_NEXT_LINE(WHILE)==========\n");
printf("Remainder addrress (list) = %p\n", rem_buff);
//printf("tmp = %s\n", tmp);
		buff[n] = '\0';
		if ((append = append_buff(buff, &tmp, fd, &rem_buff)) == 1)
	    	*line = tmp;
printf("Append = %d\n", append);
		if (append == 1 || append == -1)
	    	return (append);
	}
	if (n == -1)
		return (-1);
	if (tmp != 0)
		*line = tmp;
	return ((tmp == 0) ? 0 : 1);
	//check what’s going on when \n not found or file is empty.
}
