/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:30:32 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/22 14:25:31 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"

# define BUFF_SIZE 1

typedef struct	s_rem
{
	int			id;
	char		*str;
}				t_rem;

int				get_next_line(const int fd, char **line);

#endif
