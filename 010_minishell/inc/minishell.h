/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 17:24:38 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	valgrind --leak-check=full ./minishell
*/

#ifndef MINISHELL_H
# define MINISHELL_H

# define _XOPEN_SOURCE 700	// Macro utilizada para evitar errores por
							// inicializaciones o estructuras incompletas.

# include "libft/includes/libft.h" // libft
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>  // redline
# include <readline/readline.h> // redline
# include <stdio.h>             // redline
# include <signal.h>            // señales
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>

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
	Variable Global:
		0 = close
		1 = open
*/
extern int	g_error;

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
	char	**full_cmd; // jmartos-
	char	*cmd_path;
	int		g_status;
	int		infile;
	int		fdin;
	int		pin;
	int		outfile;
	int		fdout;
	int		pout;
	pid_t	pid;
	int		exit;
	int		exec_signal;
}			t_shell;

/*
	- **full_prompt	= matriz bidimensional de la linea de comandos ya parseada y spliteada.
	- *cmd_path		= ruta del primer comandos encontrado en el input.
	- inline		= (STDIN 0) file descriptor a leer para ejecutar un comando.
	- outline		= (STDOUT 1)file descriptor a escribir para ejecutar un comando.
*/

/*********************/
/* FUNCIONES COMUNES */
/*********************/
int			main(int argc, char **argv, char **envp);
/*******************************/
/* FUNCIONES JMARTOS- (PARSER) */
/*******************************/
/* init.c */
void		init_pipe_red(t_pipe_red *value);
void		init_prompt(t_shell *shell);
/* command.c */
int			check_cmd(t_shell *shell);
/* check_quotes.c */
int			check_quotes(char quote, int state);
/* pipes_redirections.c */
int			check_first_pipe(char *prompt);
int			validating_pipes_reds(char *prompt);
/* parse.c */
char		**super_split(char *prompt, t_shell *shell);
char		**parse_input(char *prompt, t_shell *shell);
/* parse_utils_1.c */
char 		*process_dq(char *prompt, int *pos, t_shell *shell);
char 		*process_sq(char *prompt, int *pos);
char		*process_pipe(char *prompt, int *pos);
char		*process_red1(char *prompt, int *pos);
char		*process_red2(char *prompt, int *pos);
/* parse_utils_2.c */
int			strlen_end_word(char *prompt, int pos);
char		*process_char(char *prompt, int *pos);
/* env_var.c */
t_var		**init_envp(char **envp);
char		*get_var(t_var **list_var, char *key);
char 		*find_varname(char *str, int pos);
char 		*replace_key_x_value(t_var **env_list, char *str, t_shell *shell);
void		expand_env_var(t_shell *shell, char **envp);
void mini_expand_env_var(char *prompt, char **env, int *pos, t_shell *shell);
/* env_var_utils.c */
void		remove_dquotes(char *str);
char 		*implement_dolar_question(char *str, char *start, char *end, int cmd_exit_status);
/* signal.c */
void		handler(int signal);
void		if_signal(void);
/*********************************/
/* FUNCIONES RGUERRER (EXECUTOR) */
/*********************************/
/* builtins */
void		ft_cd(char **full_cmd, t_shell *shell);
void		ft_echo(char **args);
void		ft_env(t_shell *shell);
void		ft_exit(char **cmd, t_shell *shell);
void		ft_export(char **full_cmd, t_shell *shell);
void		ft_pwd(t_shell *shell);
void		ft_unset(char **name_var, t_shell *shell);
int			is_builtin(char *cmd);
void		execute_builtin(t_shell *shell, char **full_cmd);
/* executor */
int			execute_ins(t_shell *shell, char **cmd);
void		exec_choose(t_shell *shell, char **cmd);
void		execute(t_shell *shell);
/*redirection*/
void		apply_outfile(char **name, t_shell *shell, int i);
void		apply_infile(char **name, t_shell *shell, int i);
void		apply_pipe(t_shell *shell, char **cmd, int *prev_fd);
/*clean*/
void		ft_close_resets(t_shell *shell);

#endif