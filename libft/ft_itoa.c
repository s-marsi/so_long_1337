/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:07:41 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/27 14:36:09 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	calcule_number(long n)
{
	long	count;

	count = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static	char	*to_string(char *str, long nb, int n, long len)
{
	int	divided;

	if (n < 0)
		str[0] = '-';
	divided = 10;
	while (len--)
	{
		if (n < 0 && len == 0)
			return (str);
		str[len] = (nb % divided) + '0';
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	long	count;
	char	*str;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count = calcule_number(-nb) + 1;
		nb = -nb;
	}
	else
		count = calcule_number(nb);
	str = ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (to_string(str, nb, n, count));
}
