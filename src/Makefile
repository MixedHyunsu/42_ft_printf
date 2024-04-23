Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)
SRCS ?= $(shell find . -name "*.c" | cut -c 3-)
OBJS := $(SRCS:.c=.o)
NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar rcus
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(MAKE) clean

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
