#ifndef SHELL_H
#define SHELL_H

/**Libraries Used **/
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**Buffers **/
#define BUFFER_SIZE 1024
#define MAX_LEN 1024
#define MAX_ARGS 20

extern char **environ;

/**Custom String Prototypes **/
char *custom_strncpy(char *dest, const char *src, int n);
int custom_strcmp(const char *s1, const char *s2);
char *custom_strcat(char *dest, const char *src);
char *custom_strdup(const char *str);
char *custom_strcpy(char *dest, char *src);
int custom_strlen(const char *s);
const char *custom_strchr(const char *s, char c);
int custom_atoi(char *s);
int custom_strncmp(const char *s1, const char *s2, size_t n);
char *custom_strtok(char *line, char *delim);
void process_command(char *cmd, ssize_t *status);

/**Shell Prototypes **/
void env_print(void);
char *_getenv(const char *name);
void free_main_env(char **env_main);
char **environ_capt(void);
char *find_path(const char *program, char *_pathexec);
void _builtin(char *str);
void _execve(const char *location, char *args[]);
void separate_args(char *input_str, char *output_arr[]);
void handle_comments(char *str);
ssize_t handle_cd(char **input, ssize_t *status);


#endif
