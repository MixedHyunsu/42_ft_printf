
Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)
SRCS ?= $(shell find . -name "*.c" | cut -c 3-)
NAME := test.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -L../src -lftprintf
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

all: $(NAME)
$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LDFLAGS)

clean:
	$Qfind . -type f \( -name "*.o" -o -name "*.d" \) -delete

fclean: clean
	$Qrm -f $(NAME)
	
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all

.PHONY: all clean fclean re

%.o: %.c
	$Q$(CC) $(CFLAGS) -c $< -o $@ -MMD

# test의 Makefile에서 libft_printf.a 파일을 같이 링크해주면 됩니다! LDFLAGS에 -L../src -lft_printf같은 플래그를 추가해 보세오