/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:05:01 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 14:11:24 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_minishell(t_global *g)
{
	int		confirm;
	char	*line;
	char	**args;

	g->pwd = getcwd(NULL, 0);
	confirm = 1;
	while (confirm)
	{
		write(1, "minishell $> ", 13);
		get_next_line(0, &line);
		args = get_args(line, g);
		confirm = execute_args(args, g);
		if (line != NULL)
		{
			free(line);
			free(args);
		}
	}
}
