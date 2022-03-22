/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:28:08 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/25 18:48:35 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# define OPEN_MAX 256
# define SUCCESS 1
# define FILE_EOF 0
# define ERROR -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		get_next_line(int fd, char **line);

#endif
