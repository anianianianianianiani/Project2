/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:41:07 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/01 17:53:09 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	if ((size_t)start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	free_malloc(char **str)
{
	int	i;

	i = 0;
	if (str[i])
		free(str[i++]);
	if (str)
		free(str);
		i++;
	return (1);
}

static size_t	word_length(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (count);
}

static char	**fill_str(char **store, char const *str, char c)
{
	size_t		len;
	size_t		index;
	char const	*st;

	index = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			while (*str && *str != c)
			{
				len++;
				str++;
			}
			st = str - len;
			store[index] = ft_substr(st, 0, len);
			if (store[index++] == NULL)
				return (NULL);
		}
		else
			str++;
	}
	store[index] = 0;
	return (store);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_string;
	size_t	word_len;

	if (!s)
		return (NULL);
	word_len = word_length(s, c);
	splited_string = malloc(sizeof(char *) * (word_len + 1));
	if (!splited_string)
		return (NULL);
	splited_string = fill_str(splited_string, s, c);
	if (!splited_string && free_malloc(splited_string))
		return (NULL);
	return (splited_string);
}
