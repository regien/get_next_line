#include <stdio.h>
#include <unistd.h>

int		ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i++])
			return (-1);
	}
	return (i);
}

/*
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i++])
			return (NULL);
	}
	return ((char*)&s[i]);
}
*/

int main(void)
{
	printf("pendejada = %i\n", ft_strchr("0123456798\n0123456789",'\n'));
}
