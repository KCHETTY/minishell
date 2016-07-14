/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 11:54:44 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 12:22:12 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_env(char **environ)
{
	while (*environ != NULL)
	{
		ft_str(*environ);
		write(1, "\n", 1);
		environ++;
	}
	return (1);
}
