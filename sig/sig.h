/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:52:22 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/04 22:29:03 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

void	sig_set(void);
void	sig_disable(void);
void	sig_set_execve(void);
void	sig_set_heredoc(void);

#endif
