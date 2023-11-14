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

int _exit(char **arguments, char *allocated_line);
char *custom_strdup(const char *src);
char *custom_strcpy(char *dest, char *src);
const char *custom_strchr(const char *s, char c);
char *custom_strcat(char *dest, const char *src);
int custom_strlen(const char *s);
int custom_strcmp(const char *s1, const char *s2);
int custom_atoi(char *s);
void displayErrorMessage(char **programName, char **inputArgs, int iterationCount);
void displayIterationNumber(int iterations);
char **tokenizer(char *line, int len);




#endif
