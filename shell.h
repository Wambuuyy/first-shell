#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
// #include <sys/wait.h>
// #include <signal.h>
// #include <sys/stat.h>
// #include <limits.h>
// #include <fcntl.h>
// #include <errno.h>
// #include <ctype.h>

#define BUFFER_SIZE 1024


/* print function*/
void pru_print(const char *output);
/* execute command*/
void execute_cmd(const char *command);
/* user input*/
void user_input(char * command, size_t size);
/* tokenizer*/
void execute_cmd(const char *command);
/*prompt*/
void display_prompt (void);

#endif
