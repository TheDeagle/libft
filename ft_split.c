/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:58:20 by hben-bou          #+#    #+#             */
/*   Updated: 2022/10/22 19:58:22 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	countwrd(char const *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (*str)
	{
		if (*str != c && k < 0)
		{
			k = 1;
			i++;
		}
		if (*str == c)
			k = -1;
		str++;
	}
	return (i);
}

static char	*wordalc(char const *str, int start, int end)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		ptr[i++] = str[start++];
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	int		start;
	char	**ptr;

	i = 0;
	k = 0;
	start = -1;
	ptr = (char **)malloc(sizeof(char *) * (countwrd(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			ptr[k++] = wordalc(s, start, i);
			start = -1;
		}
		i++;
	}
	ptr[k] = 0;
	return (ptr);
}
