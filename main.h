#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

/* Function Declarations */

/* Command Execution */
void execute_command(char **args);

/* Input Processing */
char *read_line(void);
char **split_line(char *line);

/* Built-in Commands */
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

/* Utility Functions */
void free_args(char **args);
void print_prompt(void);
void print_error(const char *error_message);

/* System Calls */
int shell_execve(const char *path, char *const argv[], char *const envp[]);
int shell_access(const char *path, int mode);
int shell_chdir(const char *path);
int shell_close(int fd);
DIR *shell_opendir(const char *name);
struct dirent *shell_readdir(DIR *dir);
int shell_closedir(DIR *dir);
pid_t shell_fork(void);
void shell_exit_status(int status);
void shell_signal(int signum, void (*handler)(int));
ssize_t shell_read(int fd, void *buf, size_t count);
ssize_t shell_write(int fd, const void *buf, size_t count);
int shell_open(const char *pathname, int flags, mode_t mode);
int shell_stat(const char *path, struct stat *buf);
int shell_lstat(const char *path, struct stat *buf);
int shell_fstat(int fd, struct stat *buf);
char *shell_getcwd(char *buf, size_t size);
pid_t shell_getpid(void);
int shell_isatty(int fd);
int shell_kill(pid_t pid, int sig);
void *shell_malloc(size_t size);
void shell_free(void *ptr);
int shell_wait(int *status);
pid_t shell_waitpid(pid_t pid, int *status, int options);
pid_t shell_wait3(int *status, int options, struct rusage *rusage);
pid_t shell_wait4(pid_t pid, int *status, int options, struct rusage *rusage);

#endif /* SHELL_H */

