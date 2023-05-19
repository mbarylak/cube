/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:49:52 by mbarylak          #+#    #+#             */
/*   Updated: 2023/05/19 19:50:07 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	*str;
	char	ch;

	i = 0;
	ch = (char) c;
	str = (char *) s;
	res = NULL;
	while (str[i])
	{
		if (str[i] == ch)
			res = &str[i];
		i++;
	}
	if (str[i] == ch)
		res = &str[i];
	return (res);
}