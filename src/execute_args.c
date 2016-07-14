/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:57:56 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 14:28:57 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	launch(void)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		write(1, "Error-> Invalid Input.\n", 24);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		write(1, "ERROR\n", 7);
	else
	{
		while (1)
		{
			wpid = waitpid(pid, &status, WUNTRACED);
			if (!(!WIFEXITED(status) && !WIFSIGNALED(status)))
				break ;
		}
	}
	return (1);
}

int	execute_args(char **args, t_global *g)
{
	if (args[0] == NULL)
		return (1);
	if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	if (ft_strcmp(args[0], "ls") == 0)
		return (ft_ls(args));
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	if (ft_strcmp(args[0], "clear") == 0)
	{
		write(1, "\033c", 7);
		return (1);
	}
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_env(g->environ));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args, g->environ));
	return (launch());
}
