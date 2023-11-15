#ifndef SHELL_H
#define SHELL_H

#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <stdarg.h>


/**
 *struct binary_file - Represents a built-in command
 *along with its implementation.
 *@command_name: The name of the built-in command.
 *@function_ptr: A function pointer to the implementation
 *of the built-in command.
 */
typedef struct binary_file
{
	char *command_name;
	int (*function_ptr)(void);
} builtin;


int custom_exit(char **arguments, char *allocated_line);
char *custom_strdup(const char *src);
char *custom_strcpy(char *dest, char *src);
const char *custom_strchr(const char *s, char c);
char *custom_strcat(char *dest, const char *src);
int custom_strlen(const char *s);
int custom_strcmp(const char *s1, const char *s2);
int custom_atoi(char *s);
void displayErrorMessage(char **programName, char **inputArgs,
		int iterationCount);
void displayIterationNumber(int iterations);
char **tokenizer(char *line, int len);
void format_eq_sign(char **string);
int find(char **arguments);
int find_command_in_dirs(char **directories, char **command_to_find);
int find_builtins(char **args);
char *find_path(char *target_name);
int countArguments(char *str);
int execute_command(char **args);
void custom_sig_handler(int signal);
int interpreter(char **arguments);
int print_env(void);

extern char **environ;





#endif
