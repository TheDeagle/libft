/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:55:22 by hben-bou          #+#    #+#             */
/*   Updated: 2022/10/27 00:24:16 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	leng;
	char	*ptr;

	i = 0;
	leng = len(n);
	ptr = (char *)malloc(leng + 1);
	if (!ptr)
		return (NULL);
	ptr[leng] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		i++;
	}
	while (i < leng--)
	{
		if (n < 0)
			ptr[leng] = 48 + n % 10 * (-1);
		else
			ptr[leng] = n % 10 + 48;
		n /= 10;
	}
	return (ptr);
}
