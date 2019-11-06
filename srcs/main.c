/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bsq01.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/16 14:32:46 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 23:32:41 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int check_map_uno(t_info info, char *file)
{
	if (info.line_nb == 1 && info.cpt_n != 2)
		return (1);
	if (info.line_nb == 1 && file[info.endpos] == info.charset[0]
			&& info.col_nb == 1)
	{
		write(1, &info.charset[2], 1);
		write(1, "\n", 1);
		return (0);
	}
	if (info.line_nb == 1 && file[info.endpos] == info.charset[1])
	{
		write(1, &info.charset[1], 1);
		write(1, "\n", 1);
		return (0);
	}
	if (file[info.endpos] == '\n')
		return (1);
	return (2);
}

int		bsq(char *av)
{
	int		**matrice;
	t_coord	index;
	t_info	info;
	char	*file;

	index.max = 0;
	file = get_file(av);
	get_info(&info, file);
	if (error(file, info) == 84 || check_charset(file, info) == 84)
	{
		write(2, "map error\n", 10);
		return (84);
	}
	if (check_map_uno(info, file) == 0)
		return (0);
	else if (check_map_uno(info, file) == 1)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	matrice = alloc_matrice(info.line_nb, info.col_nb);
	matrice = get_matrice(file, matrice, info);
	if (info.line_nb == 1 || info.col_nb == 1)
	{
		set_ascii(matrice, info, index);
		if (fill1mat(matrice, info) == 0)
			return (0);
	}
	get_max(matrice, info, &index);
	print_result(matrice, info, index);
	free(matrice);
	return (0);
}

char	*read_map_stdin(void)
{
	char buf[8193];
	char *dest;
	int ret;

	ret = 1;
	dest = malloc(100000999 * sizeof(char));
	*dest = 0;
	while ((ret = read(0, buf, 8192)))
	{
		buf[ret] = '\0';
		ft_strcat(dest, buf);
	}
	return (dest);
}

int		noparams(void)
{
	char	*input;
	int		**matrice;
	t_coord	index;
	t_info info;

	index.max = 0;
	input = read_map_stdin();
	get_info(&info, input);
	if (error(input, info) == 84 || check_charset(input, info) == 84)
	{
		write(2, "map error\n", 10);
		return (84);
	}
	if (check_map_uno(info, input) == 0)
		return (0);
	write(1, "\n", 1);
	matrice = alloc_matrice(info.line_nb, info.col_nb);
	matrice = get_matrice(input, matrice, info);
	print_result(matrice, info, index);	
	free(matrice);
	free(input);
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
	{
		noparams();
		return (0);
	}
	while (i < ac)
	{
		bsq(av[i]);
		if (i < ac - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
