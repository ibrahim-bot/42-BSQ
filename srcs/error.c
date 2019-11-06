/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 19:50:23 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 23:36:46 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		error(char *buffer, t_info info)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 1;
	while (buffer[i] != '\n')
		i++;
	i++;
	while (x < info.line_nb)
	{
		j = 0;
		while (buffer[i] != '\n')
		{
			i++;
			j++;
		}
		if (j != info.col_nb)
			return (84);
		x++;
		i++;
	}
	return (0);
}

int		check_charset(char *file, t_info info)
{
	int i;
	int x;

	x = 0;
	if (info.charset[0] == info.charset[1]
			|| info.charset[0] == info.charset[2]
			|| info.charset[1] == info.charset[2])
		return (84);
	i = info.endpos;
	while (x < info.line_nb)
	{
		while (file[i] != '\n')
		{
			if (!(file[i] == info.charset[0] || file[i] == info.charset[1]))
				return (84);
			i++;
		}
		i++;
		x++;
	}
	if (info.line_nb < 1)
		return (84);
	return (0);
}
