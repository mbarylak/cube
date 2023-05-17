/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:30:15 by mbarylak          #+#    #+#             */
/*   Updated: 2023/05/17 20:33:44 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	error_msg(int i)
{
	if (i == 0)
	{
		printf("Error \n The file is no valid \n");
		return (1);
	}
	else if (i == 1)
	{
		printf("Error \n Invalid map size \n");
		return (1);
	}
	return (0);
}