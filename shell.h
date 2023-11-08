#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#define BUFFER_SIZE 1024


/************change_dir.c*************/
int cd_builtin(char *args);
int change_dir(char **args);

/************exit.c************/
int exit_builtin(char *string);
void exit_shell(char **args, char *input_buf, char *program, int exit_code);
void exit_free(char **args);

/************pid.c************/
void child(char **args, char *program, char **env, int iterations);

/************print.c************/
void perror_(const char *program, int err_code, char **args);

/************special.c************/
size_t strlen_(const char *string);
char *strcpy_(char *destination, const char *source);
int strcmp_(const char *string1, const char *string2);

/************strings.c************/
void rem_newline(char *string);
void free_str(char **string);
	
/* execute command*/
//void execute_cmd(const char *command);
/* user input*/
//void user_input(char * command, size_t size);

/************token.c************/
char **tokenizer(char *input_buf, const char *delimiter);

/************prompt.c************/
void display_prompt (void);
void sign_handle(int signal);
void handle_EOF(char **input);
void signal_handler(void);

/************shell.c************/
int  main(int __attribute__((unused)) argc, char **argv, char **env);

#endif
