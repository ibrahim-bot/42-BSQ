/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_alloc.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 16:49:15 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 22:32:21 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		**alloc_matrice(int line_nb, int col_nb)
{
	int i;
	int **matrice;

	i = 0;
	if (!(matrice = malloc(line_nb * sizeof(int*))))
		return (NULL);
	while (i < line_nb)
	{
		matrice[i] = malloc(col_nb * sizeof(int));
		i++;
	}
	return (matrice);
}
