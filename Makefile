# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 12:54:28 by root              #+#    #+#              #
#    Updated: 2023/06/02 12:31:58 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm
RMF = rm -rf

INC_DIR = include
INCS = -I$(INC_DIR)

SRC_DIR = src
SRCS = $(wildcard  $(SRC_DIR)/main.cpp) \
		$(wildcard $(SRC_DIR)/ConfigParser.cpp)

OBJ_DIR	= objs
OBJ_FILES = $(notdir $(SRCS:.cpp=.o))
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CPP) $(FLAGS) -c $< $(INCS) -o $@

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RMF) $(OBJS)
	$(RMF) $(OBJ_DIR)

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re