#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*s;
	int		fd;
	int		res;
	
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		printf("Can't open file [%s].\n", av[1]);
		return (1);
	}

	while ((res = get_next_line(fd, &s)) == 1)
		printf("%s", s);
		//printf("%p - %s\n", s, s);

	if (res == -1)
		printf("Error occured.\n");
	if (res == 0)
		printf("Reading complete.\n");
	return (0);
}
