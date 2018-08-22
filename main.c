#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*s;
//	char	*s2;
	int		fd;
	int		fd2;
	int		res;

	if (ac < 2)
		return (printf("usage: ./a.out [file1] [file2 (optional)]") > 0);	
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		printf("Can't open file1 [%s].\n", av[1]);
		return (1);
	}
	if (ac > 2)
	{
		if ((fd2 = open(av[2], O_RDONLY)) == -1)
		{
			printf("Can't open file2 [%s].\n", av[2]);
			return (1);
		}
	}
/*
	while ((res = get_next_line(fd, &s)) == 1 ||
			(ac == 3 && (res = get_next_line(fd2, &s2)) == 1))
	{
		printf("From file1: %s\n", s);
		if (ac == 3)
			printf("From file2: %s\n", s2);
	}
*/
	while ((res = get_next_line(fd, &s)) == 1)
	{
//printf("-----------------------------------------\n");
//system("leaks a.out -quiet");
//printf("-----------------------------------------\n");
		if (s != 0)
			printf("From file1: %s\n", s);
		free((void *)s);
	}
		//printf("%p - %s\n", s, s);

	close(fd);
	if (ac == 3)
		close(fd2);

	if (res == -1)
		printf(">>> Error occured. <<<\n");
	if (res == 0)
		printf(">>> Reading complete. <<<\n");
	return (0);
}
