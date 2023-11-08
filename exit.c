/**
 * exit_builtin - a function that checks if a string is the exit built-in command.
 * @string: The command to check if it is exit
 *
 * Return: 1 if the command is the exit built-in command, 0 otherwise.
 */
int exit_builtin(char *string) {
    if (strcmp_(command, "exit") == 0) {
        return 1;
    } else {
        return 0;
    }
}
