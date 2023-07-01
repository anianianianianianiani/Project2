#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	put_msg(char *str, int fd)
{
	write(fd, str, (int)(ft_strlen(str)));
	if (fd == 2)
		exit(0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new_str;
	size_t		i;
	size_t		j;

	new_str = malloc(sizeof (char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			new_str[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i])
			new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = -1;
	dup = (char *)malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	while (src[++i])
		dup[i] = src[i];
	dup[i] = 0;
	return (dup);
}

int	ft_atoi(const char *str)
{
	int			is_negative;
	long int	res;

	res = 0;
	is_negative = 1;
	if (ft_strncmp(str, "-0", 2) == 0 || ft_strncmp(str, "+0", 2) == 0)
		put_msg("Error", 2);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		is_negative *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if ((res > INT_MAX && is_negative == 1)
			|| ((res * -1) < INT_MIN && is_negative == -1))
			put_msg("Error", 2);
		str++;
	}
	if (*str != '\0')
		put_msg("Error", 2);
	return (res * is_negative);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1 && str1[i])
		i++;
	return (str1[i] - str2[i]);
}
