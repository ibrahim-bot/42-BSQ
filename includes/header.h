/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 11:47:12 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 23:35:49 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_coord
{
	int		line;
	int		col;
	int		max;
}					t_coord;

typedef struct		s_info
{
	int		line_nb;
	int		col_nb;
	int		charset[3];
	int		endpos;
	int		cpt_n;
}					t_info;

typedef struct		s_pos
{
	int		i;
	int		j;
}					t_pos;

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
char	*ft_strcat(char *dest, char *src);
int		absvalue(int num);
void	ft_putnbr(int nb);
int		min(int a, int b, int c);
char	*get_charset(char *av);
int		get_col_nb(char *av);
int		**get_matrice(char *file, int **matrice, t_info info);
void	print_matrice(int **matrice, t_info info);
int		**alloc_matrice(int line_nb, int col_nb);
char	*get_file(char *av);
void	get_info(t_info *info, char *file);
void	fill_size(int **matrice, int i, int j);
void	set_ascii(int **matrice, t_info info, t_coord index);
int		is_in_square(int i, int j, t_coord index);
void	print_result(int **matrice, t_info info, t_coord index);
void	args(int ac, char **av);
int		noparams(void);
int		error(char *buf, t_info info);
int		check_charset(char *file, t_info info);
void	get_max(int **matrice, t_info info, t_coord *index);
int		fill1mat(int **matrice, t_info info);

#endif
