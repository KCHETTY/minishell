/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:04:31 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 14:40:37 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_str(const char *s)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

char	**env_duplicate(char **env)
{
	char	**str;
	int		env_size;
	int		n;

	env_size = 0;
	n = 0;
	str = NULL;
	while (env[env_size])
		env_size++;
	str = (char **)malloc(sizeof(char *) * env_size);
	if (str == NULL)
	{
		write(1, "Unable to allocate memory to ->\
				variable: str, Function: env_duplicate.", 76);
		return (NULL);
	}
	while (env[n])
	{
		str[n] = get_str(env[n]);
		n++;
	}
	str[n] = NULL;
	return (str);
}

int		main(int argc, char **argv, char **environ)
{
	t_global	g;

	if (argc != 1)
	{
		write(1, "ERROR: ", 8);
		write(1, argv[0], 11);
		return (-1);
	}
	else
	{
		g.environ = env_duplicate(environ);
		ft_minishell(&g);
	}
	return (0);
}
