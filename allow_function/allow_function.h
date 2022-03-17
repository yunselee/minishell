/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allow_function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:55:48 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:14:09 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOW_FUNCTION_H
# define ALLOW_FUNCTION_H

void			*_malloc(unsigned int size);
void			_free(void *pointer);
int				_write(int fd, const char *buf, size_t size);
int				_open(const char *pathname, int flags);
ssize_t			_read(int fd, void*buf, size_t count);
int				_close(int fd);
pid_t			_fork(void);
pid_t			_wait(int *wstatus);
int				_kill(pid_t pid, int sig);
char			*_getcwd(char *buf, size_t size);
int				_chdir(const char *path);
int				_stat(const char *pathname, struct stat *statbuf);
int				_fstat(int fd, struct stat *statbuf);
int				_lstat(const char *pathname, struct stat *statbuf);
int				_unlink(const char *pathname);
int				_execve(const char *pathname, char *const argv[],
					char *const envp[]);
int				_dup(int oldfd);
int				_dup2(int oldfd, int newfd);
int				_pipe(int pipefd[2]);
DIR				_opendir(const char *name);
struct dirent	*_readdir(DIR *dirp);
int				_closedir(DIR *dirp);

#endif /* ALLOW_FUNCTION_H */