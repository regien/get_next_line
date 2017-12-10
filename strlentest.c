#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char	*holder;

	holder = malloc(sizeof(char) * 34);
	strcpy(holder, "01234567890123456789");
	printf("posiciones = %lu", strlen(holder));
}
