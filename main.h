#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

extern char **environ;
char *_getinput(void);
void free_last_input(void);
void *__getline(void);
int _check_command(char **);
int execute_buitlin(char *, char **);
void _help(void);
void exit_status(char **);
void _cd(char **);
int _setenv(char **);
int _unsetenv(char **);
int _env(void);
int _clear(char **);
void handle_sigint(int);
void handle_sigquit(int);
void handle_sigstp(int);
int _execute(char **);
char **tokenize(char *, const char *);
char **tokenize_input(char *);
char *_getenv(const char *);
char *find_in_path(char *);
void free_error(char **, char *);
void free_array(char **);
void free_path(void);
void _putstring(char *);
void _puterror(char *);
int _strlen(const char *);
int _strcmp(const char *, const char *);
int _strncmp(const char *, const char *, size_t);
char *_strstr(char *, char *);
char *_strchr(char *, char);
char *_strcpy(char *, char *);
char *_strcat(char *, const char *);
char *_strdup(const char *);
int _putchar(char);
unsigned int _strspn(char *, char *);
int _atoi(const char *);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *, char *, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int, unsigned int);
char *allocator(size_t );
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *__realloc(char *src, size_t size);
#endif
