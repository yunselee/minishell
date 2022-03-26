/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:00:30 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/26 17:35:37 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

void	builtin_echo(const char **args);
void	builtin_cd(const char **args);
void	builtin_pwd(void);
void	builtin_export(char **args);
void	builtin_env(void);
void	builtin_unset(const char **args);

#endif /* COMMAND_H */
