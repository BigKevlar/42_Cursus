/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/13 18:39:04 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	valgrind --leak-check=full ./minishell
*/

#ifndef MINI_H
# define MINI_H

# include "libft/includes/libft.h" // libft
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>  // redline
# include <readline/readline.h> // redline
# include <stdio.h>             // redline
# include <signal.h>            // señales (server/client)
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define NO_QUOTE 0
# define DQ_OPEN 1
# define SQ_OPEN 2

# define STDIN_FILENO 0  // entrada estandar de informacion (por la terminal)
# define STDOUT_FILENO 1 // salida estandar de informacion (en la terminal)
# define STDERR_FILENO 2 // error en la salida estandar (en la terminal)

# define SHELL_NAME "minishell"
# define SHELL_PROMPT "minishell$ "

# define NC "\033[0m"
# define RED "\033[31;1m"

/*
	Usaremos esta estructura para guardar los estados de pipes y redirecciones.
*/
typedef struct s_pipe_red
{
	int		pipe;
	int		red;
}			t_pipe_red;

/*
	Esta estructura de la expansion de las variabes de entorno.
*/
typedef struct s_var
{
	char	*key;
	char	*value;
}			t_var;

/*
	- *prompt	= linea de comandos leida por el shell, sin parsear.
	-
	- **env		= matriz de punteros a las variables de entorno del shell.
	- pid		= id del proceso actual de la consola.
	- *cmds		= puntero a la estructura de comandos.
*/
typedef struct s_shell
{
	char	*prompt;        // jmartos-
	char	*parsed_prompt; // jmartos-
	char	**env;
	pid_t	pid;
	t_list	*cmd;
}			t_shell;

/*
	- **full_prompt	= matriz bidimensional de la linea de comandos ya parseada y spliteada.
	- *cmd_path		= ruta del primer comandos encontrado en el input.
	- inline		= (STDIN 0) file descriptor a leer para ejecutar un comando.
	- outline		= (STDOUT 1)file descriptor a escribir para ejecutar un comando.
*/
typedef struct s_cmd
{
	char	**full_cmd; // jmartos-
	char	*cmd_path;
	int		g_status;
	int		cmd_exit_status; // jmartos-
	int		infile;
	int		outfile;
}			t_cmd;

/*********************/
/* FUNCIONES COMUNES */
/*********************/
void		if_signal(void);
int			main(int argc, char **argv __attribute__((unused)), char **envp);
/*******************************/
/* FUNCIONES JMARTOS- (PARSER) */
/*******************************/
/* init.c */
void		init_pipe_red(t_pipe_red *value);
void		init_prompt(t_shell *shell, t_cmd *cmd, char **envp);
/* command.c */
int			check_cmd(t_shell *shell);
/* check_quotes.c */
int			check_quotes(char quote, int state);
/* pipes_redirections.c */
int			check_first_pipe(char *prompt);
int			validating_pipes_reds(char *prompt);
/* parse.c */
char		**super_split(char *prompt);
char		**parse_input(char *prompt);
/* parse_utils_1.c */
char		*process_dq(char *prompt, int *pos);
char		*process_sq(char *prompt, int *pos);
char		*process_pipe(char *prompt, int *pos);
char		*process_red1(char *prompt, int *pos);
char		*process_red2(char *prompt, int *pos);
/* parse_utils_2.c */
int			strlen_end_word(char *prompt, int pos);
char		*process_char(char *prompt, int *pos);
/* env_var.c */
t_var		**parse_envp(char **envp);
char		*get_var(t_var **list_var, char *key);
char		*find_varname(char *str);
char 		*replace_value_var(t_cmd *cmd, t_var **env_list, char *str);
void		expand_env_var(t_cmd *cmd, char **envp);
/* env_var_utils.c */
void		remove_dquotes(char *str);
char 		*implement_dolar_question(char *str, char *start, char *end, int cmd_exit_status);
/* signal.c */
void	handle_SIGINT(int sig);
void	handle_EOF(char *line);
/*********************************/
/* FUNCIONES RGUERRER (EXECUTOR) */
/*********************************/
int			ft_cd(char *path);
int			ft_echo(char **args);
void		ft_env(t_shell *shell);
void		ft_exit(t_shell *shell);
void		ft_export(char *name_var, char *value_var, t_shell *shell);
int			ft_pwd(void);
int			ft_unset(char *name_var, t_shell *shell);
int			execute_builtin(char **full_cmd, t_shell *shell);
int			is_builtin(char *cmd);
int			execute_ins(t_shell *shell, t_cmd *cmd);
int			has_pipe(char **cmd);
void		exec_choose(t_shell *shell, t_cmd *cmds);

#endif