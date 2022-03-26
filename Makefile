# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 15:36:01 by jin-lee           #+#    #+#              #
#    Updated: 2022/03/26 20:57:39 by yunselee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

READLINE_HEADER	= -I ~/.brew/opt/readline/include
READLINE_FOLDER	= -L ~/.brew/opt/readline/lib -lreadline -lhistory


LIBFT			= ./libft/libft.a
ALLOW_FUNCTION		= ./allow_function/allow_function.a

INCS_DIR		= 	-I ./as_tree \
					-I ./allow_function \
					-I ./builtin \
					-I ./command_initializer \
					-I ./env_variable \
					-I ./execute \
					-I ./exit_code \
					-I ./libft\
					-I ./sig \
					-I ./stdio_manager \

SRCS_DIR		= 	./ \
					./as_tree \
					./builtin \
					./command_initializer \
					./env_variable \
					./execute \
					./exit_code \
					./sig \
					./stdio_manager \
					
SRCS			= ./main.c \
				$(addprefix ./builtin/, \
						builtin_env.c \
						builtin_unset.c \
						builtin_cd.c \
						builtin_export.c \
						builtin_echo.c \
						builtin_pwd.c \
					) \
				$(addprefix ./command_initializer/, \
							command_initializer.c \
							command_reinterpreter.c \
							command_tokenizer.c \
					) \
				$(addprefix ./execute/, \
							execute_basic_cmd.c \
							execute_command.c \
							execute_command_util.c \
					) \
				$(addprefix ./as_tree/, \
							as_tree.c \
							as_tree_insert.c \
				) \
				 ./env_variable/env_variable.c \
				 ./exit_code/exit_code.c \
				 ./sig/sig.c \
				 ./stdio_manager/stdio_manager.c \


OBJS_DIR		= ./objects
OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)

RM				= rm -f


all: $(NAME)


#  -I $(INCS_DIR)  $(READLINE_HEADER)

# minishell
$(NAME): $(OBJS) $(LIBFT) $(ALLOW_FUNCTION)
	$(CC) $(CDEBUG) $(READLINE_FOLDER) $^ -o $@ -g
	

# -I $(INCS_DIR) $(READLINE_HEADER)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CDEBUG) $(CFLAGS) $(INCS_DIR) $(READLINE_HEADER) -c $^ -o $@ -g
	

$(OBJS_DIR):
	@mkdir -p $@


# libft
$(LIBFT):
	$(MAKE) -C ./libft all

$(ALLOW_FUNCTION) :
	$(MAKE) -C ./allow_function all

# clean, fclean, re
clean: 
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./allow_function clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./allow_function fclean
	$(RM) $(NAME)

re: fclean all


.PHONY: all, $(NAME), clean, fclean, re