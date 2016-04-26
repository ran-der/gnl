#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(int argc, char **argv)
{
	char		**line;
	int			fd;
	int			ret;
	int			i;

	i = 0;
	while (++i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
		{
			printf("get_next_line test : could not open '%s'\n", argv[i]);
			return (0);
		}
	}
	line = NULL;
	while ((ret = get_next_line(fd, line)) == 1)
		printf("ret: %d line -> %s\n", ret, *line);
	printf("ret: %d line -> %s\n", ret, *line);
	if (ret == -1)
		printf("\n           ////~/// #AN ERROR OCCURED!# ///~////\n");
	close(fd);
	return (0);
}
