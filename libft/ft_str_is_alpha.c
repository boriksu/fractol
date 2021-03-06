/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:43:15 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/16 16:47:16 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	if (*str == '\0')
		return (1);
	else
		while (str[i] != '\0')
		{
			if ((str[i] > 96 && str[i] < 123) || (str[i] > 64 && str[i] < 91))
				i++;
			else
				return (0);
		}
	return (1);
}
