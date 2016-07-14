/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:04:07 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/09 15:59:01 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_global
{
	int		num_args;
	char	*pwd;
	char	**environ;
}				t_global;

int				main(int argc, char **argv, char **environ);
void			ft_minishell(t_global *g);
char			**get_args(char *line, t_global *g);
int				execute_args(char **args, t_global *g);
int				ft_ls(char **args);
int				ft_echo(char **args);
int				ft_cd(char **args, char **env);
int				ft_env(char **environ);
int				ft_pwd();
int				environ_check(char *str, char **path, char **env);

#endif
