/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:47:18 by ruchoa            #+#    #+#             */
/*   Updated: 2023/11/02 21:55:33 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* INCLUDES */
# include <libft.h>				// libft
# include <libftfprintf.h>		// libftfprintf
# include <unistd.h>			// getpwd | chdir | execve | fork
# include <stdlib.h>			// exit
# include <signal.h>			// signal
# include <limits.h>			// FILENAME_MAX
# include <sys/stat.h>			// stat
# include <sys/wait.h>			// wait
# include <readline/history.h>	// history
# include <readline/readline.h>	// readline

/* COLORS */
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define BLUE	"\e[1;34m"
# define PURPLE	"\e[1;35m"
# define LBLUE	"\e[1;36m"
# define WHITE	"\e[1;37m"
# define NONE	"\e[0m"

/* DEFINES */
# define EMPTY	0
# define APPEND	1
# define TRUNC	2
# define INPUT	3
# define PIPE	4
# define END	5
# define ARG	6
# define CMD	7

# define STDIN	0
# define STDOUT	1
# define STDERR	2

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

# define UNKNOWN_COMMAND	127

/* STRUCTS */
typedef struct s_input
{
	struct s_input	*prev;
	char			*content;
	int				type;
	struct s_input	*next;
}	t_input;

typedef struct s_minishell
{
	int		fdin;
	int		fdout;
	int		ret;
	char	*line;
	char	*pathname;
	char	**argv;
	char	**arge;
	int		**pipe_matrix;
	int		pipe_count;
	int		seq;
	t_list	*env;
	t_input	*token;
}	t_minishell;

/* PROTOTYPES */
int		minishell(t_minishell *data);

int		ft_banner(void);
int		ft_cd(t_minishell *data);
int		ft_echo(t_minishell *data);
int		ft_env(t_minishell *data);
int		ft_export(t_minishell *data);
char	*ft_get_cmd(t_minishell *data);
char	*ft_search_env(t_list *env, char *s1);
int		ft_exec_builtin(t_minishell *data);
int		ft_exec_bin(t_minishell *data);
char	*ft_expand(t_minishell *data, char *str);
int		ft_exit(t_minishell *data);
char	**ft_get_arge(t_minishell *data);
char	**ft_get_argv(t_minishell *data);
int		ft_history(char *line);
int		ft_init(t_minishell *data);
int		ft_init_data(t_minishell *data);
int		ft_init_env(t_minishell *data);
int		ft_is_builtin(t_minishell *data);
int		ft_is_bin(t_minishell *data);
int		ft_parse(t_minishell *data, char *line);
int		ft_readline(t_minishell *data, char *user);
int		ft_pwd(t_minishell *data);
void	ft_signal(int sig);
int		ft_strcmp(char *s1, char *s2);
int		ft_unset(t_minishell *data);
int		ft_tokenize(t_minishell *data, char *line);

int		ft_pipe_init(t_minishell *data);

#endif