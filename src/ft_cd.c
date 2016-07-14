/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:45:21 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 14:41:17 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args, char **env)
{
	char	*path;

	if (args[1] == NULL)
	{
		if (environ_check("HOME", &path, env) == -1)
		{
			write(1, "Error-> Cannot find Home directory.", 36);
			return (1);
		}
		else
			chdir(path);
	}
	else if (chdir(args[1]) != 0)
		write(1, "Invalid Directory\n", 20);
	return (1);
}
