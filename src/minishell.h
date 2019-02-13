/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:42:11 by helmanso          #+#    #+#             */
/*   Updated: 2019/02/13 15:19:25 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define LSH_TOK_DELIM " \t\r\n\a"
# define LSH_TOK_BUFSIZE 64
# ifndef MAXARG
#  define MAXARG 100
#  define IS_QUOTE(x) (x == '"' || x == '\'')
#  include <stdio.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include <signal.h>
#  include <sys/types.h>
#  include <dirent.h>
#  include <string.h>
#  include <sys/stat.h>
#  include <stdarg.h>
#  include "../libft/libft.h"
#  include "../get_next_line.h"
#  define KRED  "\x1B[31m"
#  define KYEL  "\x1B[33m"
#  define KGRN  "\x1B[32m"
#  define KDEF  "\x1B[0m"
#  define BUFF_SIZE 2000
# endif

typedef struct	s_env
{
	int				overwrite;
	char			*name;
	char			*environ;
	char			*value;
	struct s_env	*next;
	struct s_env	*new;
}				t_env;

typedef struct	s_args
{
	int				env;
	int				echo;
	int				exit;
	int				setenv;
	int				unsetenv;
	int				cd;
}				t_args;

char			**call_functions1(char *envp[], char **line, t_args *arg);
void			call_functions(char *envp[], char **line, t_args *arg);
void			loop(char *envp[]);
void			ft_cdbugs(char **line);
int				ft_getenv(char **envlist);
char			**ft_cd(char *envp[], char **line, char **envlist);
void			echo_out(char **str, int pos);
void			echo_env(char **args, char	**envlist);
int				echo_builtin(char **args, char **envlist);
int				findpathenv(char **envlist);
char			**get_env(char **envp, char *envvar);
t_args			*builincmds(char **line);
int				builincmds1(char **line);
int				ft_forkini(char **args, char **envlist);
char			**ft_setenv(char **environ, char *envname,
		char *enval, int overwrite);
void			block_sig(void);
char			**lsh_split_line(char *line);
void			ft_tablefree(char **tables);
int				tablescount(char **table);
char			**unset_env(char **env, char **arg);
int				deltab(char **tab);
char			*notfoundcmd(char **line);
char			**verfienv(char **line, char *splited);
char			**lahyamethod(char	**line, char **splited);
void			ft_printenv(char **envlist);

#endif
