/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 16:41:41 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 23:39:21 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

char	*get_file(char *av)
{
	char	*file;
	char	buf[8193];
	int		fd;
	int		ret;
	int		nbr;

	ret = 1;
	nbr = 0;
	fd = open(av, O_RDONLY);
	while ((ret = read(fd, buf, 8192)))
		nbr += ret;
	fd = open(av, O_RDONLY);
	file = (char*)malloc((nbr + 1) * sizeof(char));
	if (!file)
		return (NULL);
	*file = 0;
	fd = open(av, O_RDONLY);
	if (fd != -1)
		read(fd, file, nbr);
	else
	{
		ft_putstr("Cannot read file.\n");
		return (NULL);
	}
	return (file);
}

void	get_info(t_info *info, char *file)
{
	int	i;
	int k;
	int j;

	j = 0;
	i = 0;
	info->cpt_n = 0;
	info->line_nb = 0;
	info->col_nb = 0;
	while (file[j++])
		if (file[j] == '\n')
			info->cpt_n += 1;
	while (file[i] != '\n')
		i++;
	info->charset[2] = (int)file[i - 1];
	info->charset[1] = (int)file[i - 2];
	info->charset[0] = (int)file[i - 3];
	k = -1;
	while (++k < i - 3)
		info->line_nb = info->line_nb * 10 + (int)file[k] - 48;
	info->endpos = i + 1;
	while (file[++i] != '\n')
		info->col_nb += 1;
}

int		**get_matrice(char *file, int **matrice, t_info info)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = info.endpos;
	while (++i < info.line_nb)
	{
		j = 0;
		while (j < info.col_nb)
		{
			if ((int)file[k] == info.charset[0])
			{
				matrice[i][j++] = 1;
				fill_size(matrice, i, j - 1);
			}
			if ((int)file[k] == info.charset[1])
				matrice[i][j++] = 0;
			k++;
		}
	}
	return (matrice);
}

void	fill_size(int **matrice, int i, int j)
{
	int up;
	int left;
	int diag;

	if (i == 0 || j == 0)
		return ;
	up = matrice[i - 1][j];
	left = matrice[i][j - 1];
	diag = matrice[i - 1][j - 1];
	matrice[i][j] = 1 + min(up, left, diag);
}

void	get_max(int **matrice, t_info info, t_coord *index)
{
	int i;
	int j;

	i = 0;
	while (i < info.line_nb)
	{
		j = 0;
		while (j < info.col_nb)
		{
			if (matrice[i][j] > index->max)
			{
				index->max = matrice[i][j];
				index->line = i;
				index->col = j;
			}
			j++;
		}
		i++;
	}
}
