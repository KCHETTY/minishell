/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:49:14 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 14:41:46 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_ls(char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		write(1, "Error -> Could not execute Fork()", 34);
		return (1);
	}
	if (pid == 0)
	{
		write(1, "Please press enter to return to shell.", 38);
		write(1, "\n", 1);
		execve("/bin/ls", args, NULL);
	}
	return (1);
}
