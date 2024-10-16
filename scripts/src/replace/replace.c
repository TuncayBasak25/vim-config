#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char	*str_ext_cat(char *str, char *src)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (strlen(str) + strlen(src) + 1));
	if (new_str == 0)
	{
		return (0);
	}
	strcat(new_str, str);
	strcat(new_str, src);
	free(str);
	return (new_str);
}

char	*get_file_content(const char *filename)
{
	int		fd;
	size_t	byte_read;
	char	buff[512 * 512];
	char	*content;

	fd = open(filename, O_RDONLY);
	content = malloc(sizeof(char) * 1024);
	*content = 0;
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buff, sizeof(buff) - 1);
		if (byte_read > 0)
		{
			buff[byte_read] = 0;
			content = str_ext_cat(content, buff);
		}
	}
	close(fd);
	return (content);
}

void	file_replace(char *filename, const char *s1, const char *s2)
{
	char	*file_content;
	char	*content;
	int		fd;

	file_content = get_file_content(filename);
	content = file_content;
	fd = open(filename, O_WRONLY);
	while (*content)
	{
		if (strncmp(content, s1, strlen(s1)))
		{
			write(fd, content++, 1);
		}
		else {
			content += strlen(s1);
			write(fd, s2, strlen(s2));
		}
	}
	close(fd);
	free(file_content);
}

int	main(int argc, char **argv)
{
	if (argc != 4 && argv)
	{
		printf("Unvalid number of argument for replace fucntion!\n");
		return (0);
	}
	file_replace(argv[1], argv[2], argv[3]);
}
