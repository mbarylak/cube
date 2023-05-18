/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:30:15 by mbarylak          #+#    #+#             */
/*   Updated: 2023/05/18 20:25:00 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	error_msg(int i)
{
	if (i == 0)
		printf("Error! \nThe file is no valid! \n");
	else if (i == 1)
		printf("Error! \nInvalid map size! \n");
	else if (i == 2)
		printf("Error! \nNo player was found! \n");
	else if (i == 3)
		printf("Error! \nInvalid player starting position! \n");
	return (1);
}