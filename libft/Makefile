# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 15:51:44 by dmazurki          #+#    #+#              #
#    Updated: 2021/07/13 17:07:41 by dmazurki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = ft_printf
SRCS = srcs
REG_OBJ_FILES = $(SRCS)/ft_isalnum.o $(SRCS)/ft_isprint.o $(SRCS)/ft_memcmp.o $(SRCS)/ft_putchar_fd.o $(SRCS)/ft_split.o $(SRCS)/ft_strlcat.o $(SRCS)/ft_strncmp.o \
					$(SRCS)/ft_substr.o $(SRCS)/ft_atoi.o $(SRCS)/ft_isalpha.o $(SRCS)/ft_itoa.o $(SRCS)/ft_memcpy.o $(SRCS)/ft_putendl_fd.o $(SRCS)/ft_strchr.o \
					$(SRCS)/ft_strlcpy.o $(SRCS)/ft_strnstr.o $(SRCS)/ft_tolower.o $(SRCS)/ft_bzero.o $(SRCS)/ft_isascii.o $(SRCS)/ft_memccpy.o $(SRCS)/ft_memmove.o \
					$(SRCS)/ft_putnbr_fd.o $(SRCS)/ft_strdup.o $(SRCS)/ft_strlen.o $(SRCS)/ft_strrchr.o $(SRCS)/ft_toupper.o $(SRCS)/ft_calloc.o $(SRCS)/ft_isdigit.o \
					$(SRCS)/ft_memchr.o $(SRCS)/ft_memset.o $(SRCS)/ft_putstr_fd.o $(SRCS)/ft_strjoin.o $(SRCS)/ft_strmapi.o $(SRCS)/ft_strtrim.o
BONUS_OBJ_FILES = $(SRCS)/ft_lstadd_back.o $(SRCS)/ft_lstadd_front.o $(SRCS)/ft_lstclear.o $(SRCS)/ft_lstdelone.o $(SRCS)/ft_lstiter.o \
					$(SRCS)/ft_lstlast.o $(SRCS)/ft_lstnew.o $(SRCS)/ft_lstsize.o
FT_PTINTF_OBJ_FILES = $(FT_PRINTF)/ft_printf.o $(FT_PRINTF)/ft_printf_utils.o $(FT_PRINTF)/ft_printf_itoa.o $(FT_PRINTF)/ft_hex_converter.o $(FT_PRINTF)/ft_u_handler.o \
				$(FT_PRINTF)/ft_p_handler.o $(FT_PRINTF)/ft_c_handler.o $(FT_PRINTF)/ft_s_handler.o $(FT_PRINTF)/ft_d_i_handler.o $(FT_PRINTF)/ft_prctg_handler.o \
				$(FT_PRINTF)/ft_itoa_unsigned.o $(FT_PRINTF)/ft_hex_converter_2.o $(FT_PRINTF)/ft_printf_utils_2.o

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
AR = ar
HEADER = libft.h
CC = gcc

all: $(NAME)

$(NAME): $(REG_OBJ_FILES) $(HEADER) $(BONUS_OBJ_FILES) $(FT_PTINTF_OBJ_FILES)
	$(AR) rc $(NAME) $(REG_OBJ_FILES) $(BONUS_OBJ_FILES) $(FT_PTINTF_OBJ_FILES)
	@echo "Build done"

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(REG_OBJ_FILES) $(BONUS_OBJ_FILES) $(FT_PTINTF_OBJ_FILES)
	@echo "clean done"

fclean: clean
	rm -f $(NAME)
	@echo "fclean done"

re: fclean all
