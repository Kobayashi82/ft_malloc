#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr;

	addr = malloc(42);
	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 0) == NULL)
		print("Hello\n");
}
