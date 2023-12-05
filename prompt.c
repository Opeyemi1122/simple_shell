#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t d;
	d = 0;
	char *buf = NULL;
	
	printf("$ ");
	getline(&buf, &d, stdin);
	printf("%s", buf);

	free(buf);
	return (0);
}
