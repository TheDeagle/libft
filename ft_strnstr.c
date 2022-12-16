/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:00:38 by hben-bou          #+#    #+#             */
/*   Updated: 2022/10/22 03:00:38 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		if (haystack[i] == needle[k])
		{
			while (haystack[i + k] == needle[k] && i + k < len)
			{
				k++;
				if (!needle[k])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
