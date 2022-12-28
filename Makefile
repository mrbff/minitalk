NAME			:=	minitalk

SE_NAME			:=	server

CL_NAME			:=	client

SRCS_DIR		:=	./srcs/

SE_FILES		:=	server.c \

CL_FILES		:=	client.c \

SE_SRCS			:= 	$(addprefix $(SRCS_DIR), $(SE_FILES))

CL_SRCS                 :=      $(addprefix $(SRCS_DIR), $(CL_FILES))

SE_OBJS			:=	$(SE_SRCS:.c=.o)

CL_OBJS                 :=      $(CL_SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CC			:=	gcc

FLAGS			:=	-Wall -Wextra -Werror -g

CLR_RMV         := \033[0m
RED                 := \033[1;31m
GREEN           := \033[1;32m
YELLOW          := \033[1;33m
BLUE            := \033[1;34m
CYAN            := \033[1;36m

RM                  := rm -f

LIBFT			:=	libft/libft.a
LIBFTMAKE		:=	make -sC libft

$(NAME):		$(SE_NAME) $(CL_NAME)

$(SE_NAME):		$(SE_OBJS)
			@$(LIBFTMAKE)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(SE_NAME) ${CLR_RMV}..."
			@$(CC) $(FLAGS) $(SE_OBJS) $(LIBFT) -o $(SE_NAME)
			@echo "$(GREEN)$(SE_NAME) created ✔️ ${CLR_RMV}"

$(CL_NAME):		$(CL_OBJS)
			@$(LIBFTMAKE)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(CL_NAME) ${CLR_RMV}..."
			@$(CC) $(FLAGS) $(CL_OBJS) $(LIBFT) -o $(CL_NAME)
			@echo "$(GREEN)$(CL_NAME) created ✔️ ${CLR_RMV}"

all:			$(NAME)

clean:
				@ make -sC ./libft clean
				@ ${RM} *.o */*.o */*/*.o
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(SE_NAME) $(CL_NAME) $(LIBFT)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binaries✔️"

re:				fclean all

.PHONY:			all clean fclean re
