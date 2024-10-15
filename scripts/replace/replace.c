#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	replace_all_in_file(const char *filename, const char *s1, const char *s2)
{
	int	fd;

	fd = open(filename, O_WR)
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("Unvalid number of argument for replace fucntion!");
		return (0);
	}
	replace_all_in_file(argv[1], argv[2], argv[3]);
}
