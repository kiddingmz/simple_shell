#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/* To get envirionment variable */
extern char **environ;

char *_get_location(char *);
char *_getenv(char *);
size_t _strlen(const char *);
char *_strcat_path(char *, char *);
void _strcat_path(const char *, const char *, char *);
int check_path(char *);
/*void non_interactive(int, char **, char **);*/
/*void interactive(int, char **, char **);*/
/*int _strcmp(const char *, const char *);*/
/*void _exe(int, char **, char *, char *, char **);*/
/*void _free_array(char **);*/
/*int _putchar(char);*/
/*int _putstring(const char *);*/
/*void _putenv(char **);*/
/*char *_strdup(char *);*/
/*char *_strtok(char *, const char *);*/
/*char *_strcat(char *, char *);*/
/*char *_strcat_space(char *, char *);*/
/*char *_strcpy(char *, const char *);*/
/*char *_strncpy(char *, const char *, size_t);*/
/*char *allocator(size_t);
char *_realloc(char *, size_t);
ssize_t _getline(char **, size_t *, FILE *);
char **process_args(char *);
char *_cpy_arg(char **);
int _atoi(char *);
int _isspace(int);
char *_strtrim(char *);
char *_memmove(char *, const char *, size_t);
char *_memcpy(char *, const char *, size_t);*/
#endif
