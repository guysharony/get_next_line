#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int main(int argc, char **argv) {
	int fd;
	int fd2;
	char *line;
	int res;
	int res2;

	res = -1;
	res2 = -1;
	if (argc != 3) {
		fd = 0;
		while ((res = get_next_line(fd, &line)))
			printf("Line : %s, res : %d\n", line, res);
		printf("Line : %s, res : %d\n", line, res);
	}
	else if ((fd = open(argv[1], O_RDONLY)) != -1 && (fd2 = open(argv[2], O_RDONLY)) != -1) {
		while (res != 0 && res2 != 0) {
			res = get_next_line(fd, &line);
			printf("Line : %s, res : %d\n", line, res);
			res2 = get_next_line(fd2, &line);
			printf("file2 Line : %s, res : %d\n", line, res2);
		}
		printf("Line : %s, res : %d\n", line, res);
	}
}
