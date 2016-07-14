/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:04:18 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 15:47:24 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			get_arg_num(char *line, int *num_args)
{
	int wd;

	wd = 0;
	while (*line)
	{
		if (*line == '"')
		{
			line++;
			while (*line != '"' && *line != '\0')
				line++;
			if (*line == '"' && *line != '\0')
				line++;
			*num_args += 1;
		}
		if (wd == 0 && *line != ' ' && *line != '\t')
			wd = 1;
		if (wd == 1 && (*line == ' ' || *line == '\t' || line[1] == '\0'))
		{
			wd = 0;
			if (*line != '\0')
				*num_args += 1;
		}
		line++;
	}
}

static char		*ft_get_qut_str(char *str, char **tmp, int *i)
{
	if (*str == '"')
	{
		str++;
		while (*str != '"' && *str != '\0')
		{
			tmp[0][*i] = *str;
			*i = *i + 1;
			str++;
		}
		str++;
	}
	(*str != ' ' && *str != '\t') ? tmp[0][*i] = *str : 0;
	return (str);
}

char			**write_args(char *str, int num)
{
	char	*tmp;
	char	**args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	args = NULL;
	tmp = (char *)malloc(sizeof(char) * 50);
	args = (char **)malloc(sizeof(char *) * num + 1);
	while (*str)
	{
		str = ft_get_qut_str(str, &tmp, &i);
		if ((*str == ' ' || *str == '\t' || str[1] == '\0') && (tmp != NULL))
		{
			tmp[i + 1] = '\0';
			args[j++] = tmp;
			tmp = (char *)malloc(sizeof(char) * i);
			i = -1;
		}
		i++;
		str++;
	}
	args[j] = NULL;
	return (args);
}

char			**get_args(char *line, t_global *g)
{
	int		arg_num;
	char	**tmp;

	arg_num = 0;
	get_arg_num(line, &arg_num);
	tmp = (char **)malloc(sizeof(char *) * (arg_num + 1));
	if (tmp == NULL)
	{
		write(1, "Malloc Error-> Unable to allocate Memory.", 42);
		return (NULL);
	}
	tmp = write_args(line, arg_num);
	g->num_args = arg_num;
	return (tmp);
}
