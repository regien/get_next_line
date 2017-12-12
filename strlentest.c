#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int main(void)
{
	char	*holder;

	holder = malloc(sizeof(char) * 34);
	strcpy(holder, "01234567890123456789");
	printf("pendejadastrsub = |%s|\n", ft_strsub("pendejada X de prueba", 4, 10));
	printf("posiciones = %lu", strlen(holder));
}
