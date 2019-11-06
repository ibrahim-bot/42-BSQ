/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_base.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 18:35:13 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 18:37:10 by lumeyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
		nbr = nbr * 10 + ((int)str[i++] - '0');
	nbr *= sign;
	return (nbr);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
