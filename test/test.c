#include "../inc/libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *line = NULL;
	int fd;
	int is_er;

	char *buf;

	buf = ft_strnew(10000);
	fd = open(argv[1], O_RDONLY);
	is_er = read(fd, buf,10000);

	printf("%s\nerror is == %d\n", buf, is_er);

	printf("%s\n", &buf[9]);
	
	return 0;
}
