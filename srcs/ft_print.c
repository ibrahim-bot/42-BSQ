/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 16:45:35 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 23:40:42 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int		is_in_square(int i, int j, t_coord index)
{
	if (i <= index.line && i >= (index.line - (index.max - 1))
			&& j <= index.col && j >= (index.col - (index.max - 1)))
		return (1);
	return (0);
}

void	set_ascii(int **matrice, t_info info, t_coord index)
{
	int i;
	int j;

	i = 0;
	while (i < info.line_nb)
	{
		j = 0;
		while (j < info.col_nb)
		{
			if (is_in_square(i, j, index))
				matrice[i][j] = info.charset[2];
			else if (matrice[i][j])
				matrice[i][j] = info.charset[0];
			else
				matrice[i][j] = info.charset[1];
			j++;
		}
		i++;
	}
}

void	print_line(int *matrice, t_info info)
{
	int		i;
	char	*temp;

	if (!(temp = malloc(info.col_nb * sizeof(char))))
		return ;
	i = -1;
	while (++i < info.col_nb)
		temp[i] = matrice[i];
	write(1, temp, info.col_nb);
	free(temp);
}

void	print_result(int **matrice, t_info info, t_coord index)
{
	int i;

	i = 0;
	set_ascii(matrice, info, index);
	while (i < info.line_nb)
	{
		print_line(matrice[i], info);
		write(1, "\n", 1);
		if (matrice[i + 1] != NULL)
		{
			print_line(matrice[i + 1], info);
			write(1, "\n", 1);
			i++;
		}
		i++;
	}
}

int		fill1mat(int **matrice, t_info info)
{
	int i;
	int j;

	i = 0;
	while (i < info.line_nb)
	{
		j = 0;
		while (j < info.col_nb)
		{
			if (matrice[i][j] > 0)
			{
				matrice[i][j] = info.charset[2];
			}
			else
			{
				matrice[i][j] = info.charset[1];
			}
			write(1, &matrice[i][j], 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
