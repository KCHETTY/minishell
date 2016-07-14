/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 09:48:38 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 14:02:25 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	special_print(char c)
{
	if (c == 'n')
		write(1, "\n", 1);
	if (c == 't')
		write(1, "\t", 1);
	if (c == 'v')
		write(1, "\v", 1);
	if (c == 'r')
		write(1, "\r", 1);
	if (c == 'a')
		write(1, "\a", 1);
	if (c == 'b')
		write(1, "\b", 1);
	if (c == '\\')
		write(1, "\\", 1);
}

void	echo_print(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && str[i] != '\0')
		{
			i++;
			special_print(str[i]);
		}
		else if (str[i] != '\\')
			write(1, &str[i], 1);
		i++;
	}
}

int		ft_echo(char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		echo_print(args[i]);
		if (args[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}
