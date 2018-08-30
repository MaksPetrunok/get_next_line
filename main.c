#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*s;
//	char	*s2;
	int		fd[10];
	int		i;
	int		res;
	int		run;

	if (ac < 2)
		return (printf("usage: ./a.out [file1] ... [file10] (optional)]") > 0);	
	i = 0;
	while (i < ac - 1 && (fd[i] = open(av[i + 1], O_RDONLY)) != -1)
		i++;
	if (fd[i] == -1)
		return (printf("Cant open some file.\n") > 0);

	run = 1;
	while (run > 0)
	{
		run = 0;
		for (i = 0; i < ac - 1; i++)
		{
			res = get_next_line(fd[i], &s);
			if (res == 1)
				printf("FD-%d(%s):\t%s\n", i, av[i + 1], s);
			if (res == -1)
				break ;
			run += res;
		}
		if (res == -1)
			break ;
	}

	for (i = 0; i < ac - 1; i++)
		close(fd[i]);

	if (res == -1)
		printf(">>> Error occured. <<<\n");
//	if (res == 0)
//		printf(">>> Reading complete. <<<\n");
	return (0);
}
