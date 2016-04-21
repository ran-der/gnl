#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(int argc, char **argv)
{
	char		**line;
	int			fd;
	int			ret;

	line = NULL;
	if (argc != 1)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			printf("get_next_line test : could not open '%s'\n", argv[1]);
			return (0);
		}
		while ((ret = get_next_line(fd, line)) == 1)
			printf("line -> %s\n", *line);
		if (ret == -1)
			printf("\n           ////~/// #AN ERROR OCCURED!# ///~////\n");
		close(fd);
	}
	return (0);
}
