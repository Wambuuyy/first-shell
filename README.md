<h1 align ="center">SIMPLE SHELL WRITTEN IN C LANGUAGE</h1><br>

<h2>Description</h2>
The repo contains files of the simple shell that mimics the Unix SHell program:
It accepts and executes user commands.

I mostly used these calls:
fork, wait, waitpid, free, getline, read, write, open, execve, exit, fflush,
malloc, isatty, perror, strtok.
## Process Description

The next steps are a brief description about how the shell works:

1. First, the parent process is created when the user run the program.
2. Then, the *isatty()* function using *STDIN_FILENO* file descriptor -fd- to tests if there is an open file descriptor referring to a terminal. If *isatty()* returns 1, the prompt is showed using *write()* with *STDOUT_FILENO* as fd and waits for an input user command line.
3. When the user types a command, *getline()* function reads an entire line from the stream and *strtok()* function breaks the inputted command into a sequence of non-empty tokens.
4. Next, it creates a separate child process suing *fork()* that performs the inputted command. Unless otherwise is specified, the parent process waits for the child to exit before continuing.
5. After tokening the command, *execve()* function brings and executes it, the it frees all allocated memory with *free()*.
6. Finally, the program returns to main process: prints the prompt, and waits for another user input.

Prompt looks like this: Pru$$

<h2>Features used</h2>

*  program displays a prompt and waits for the user to input
*  it always ends in a new line(user has to press enter for command to be run)
*  the prompt is displayed infinitely provided all processes have been executed and exited
*  when user types *exit*, the shel ends in a return status 0
*  when user enters *exit status*, the shell ends and returns the status
*  status is anyvalue from 0-255.
*  there is also and end file condition of ctrl + D used to end a program
*  it handles commandlines with arguments and PATH.
*  Ctrc + C does not exit instead it outputs ^C
*  It prints the working environment when user enters *env*
*  It executes shell programs like *ls*, *grep*, *mv*, *exit*, *history*, *cp*, *rm*... with arguments
*  If the command is not executable, an error is displayed and the prompt appers again.


<h2>HOW IT WORKS:</h2>
1. When the user runs a program, aparent process is created.<\n>
2. The * i don know yet* function tests if there is an open file descriptor reffering to the terminal using the STD_FILENO file descriptor.If return is 1, the prompt is dispalyed and waits for the user to input.
3. When user types a command, *getline()* function parses the line and *strtok()* function breaks the input to non-empty tokens.
4. A child process is  then created using *fork()* command: It does as the command says. The parent process has to wait for the child to exit before it continues.
5. After tokenization, *execve()* brings and executes it and later frees all allocated memory using *free()*.
6. The program returns the output if there was any and then displays the prompt and waits for another command input.


<h2>Requirements:</h2>

<h3>General</h3>h3>
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` `-pedantic` `-std=gnu89`
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl)
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
- Write a README with the description of your project
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker](https://github.com/moby/moby/blob/master/AUTHORS)
