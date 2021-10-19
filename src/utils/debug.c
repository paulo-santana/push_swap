#include <stdio.h>

void	print_list(char **list)
{
	while (*list)
	{
		printf("%s ", *list++);
	}
	printf("\n");
}
