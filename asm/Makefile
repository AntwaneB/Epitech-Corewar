##
## Makefile for do-op in /home/buchse_a/Documents/Piscine-C-lib/my
##
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
##
## Started on  Mon Oct 21 09:30:31 2013 Antoine Buchser
## Last update Thu Apr 10 17:33:56 2014 Antoine Buchser
##

LIB_DIR		=	./libmy

RM		=	rm -f
CC		=	cc
NAME		=	asm
CFLAGS		=	-Wall -Wextra -g -ggdb
CFLAGS		+=	-Wno-unused-variable -Wno-unused-parameter -Wno-unused-function

SRCS		=	main.c \
			op.c \
			args.c \
			remove_space.c \
			op_operations.c \
			misc.c \
			file_funcs.c \
			magic_number.c \
			program_name.c \
			program_size.c \
			program_comment.c \
			program_content/program_content.c \
			program_content/program_content2.c \
			program_content/all_params.c \
			program_content/write_sti_param.c \
			program_content/args_sum.c \
			program_content/args_check.c \
			program_content/write_direct.c \
			validate_file_content/file_content_is_valid.c \
			validate_file_content/comment_is_valid.c \
			validate_file_content/name_is_valid.c \
			validate_file_content/content_is_valid.c \
			validate_file_content/get_pos_jump.c \
			label.c \
			label2.c \
			validate_labels.c \
			validate_file.c \
			content_list.c \
			my_explode.c \
			get_next_line.c

OBJS		=	$(SRCS:.c=.o)

all: lib $(NAME)

lib:
	make -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lmy -L$(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all

.SILENT:
