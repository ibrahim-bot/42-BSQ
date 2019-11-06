/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numbers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 15:35:23 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 19:57:47 by lumeyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int		absvalue(int num)
{
	if (num >= 0)
		return (num);
	return (num * -1);
}

int		min(int a, int b, int c)
{
	int min;

	min = a;
	b < min ? min = b: 0;
	c < min ? min = c: 0;

	return (min);
}

void	ft_putnbr(int nb)
{
	unsigned int abs;
	unsigned int pop_unit;

	if (nb < 0)
		ft_putchar('-');
	abs = absvalue(nb);
	if (abs < 10)
		ft_putchar(abs + '0');
	else
	{
		if (abs == 2147483648)
		{
			ft_putnbr(2147483648 / 10);
			ft_putchar(2147483648 % 10 + '0');
			return ;
		}
		pop_unit = abs % 10;
		abs /= 10;
		ft_putnbr(abs);
		ft_putchar(pop_unit + '0');
	}
}
