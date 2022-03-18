/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:00:30 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/18 19:20:03 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

void	builtin_echo(const char **tokens, int token_size);
void	builtin_cd(const char **tokens, int token_size);
void	builtin_pwd(void);
void	builtin_export(char **tokens, int token_size);
void	builtin_env(void);
void	builtin_unset(const char **tokens, int token_size);

#endif /* COMMAND_H */
