NAMES	= ./server
NAMEC	= ./client

SRCSC	= ./minitalk_utils.c ./client.c 
SRCSS	= ./minitalk_utils.c ./server.c 

CC		= gcc -Wall -Wextra -Werror
RM		= rm -rf

OBJS	= $(SRCSS:.c=.o)
OBJC	= $(SRCSC:.c=.o)

HDRS = ./minitalk.h

.c.o = ${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

all : ${NAMES} ${NAMEC}

$(NAMES) : $(OBJS)
$(NAMEC) : $(OBJC)

clean	:
		  ${RM} $(OBJS)
		  ${RM} $(OBJC)

fclean	: clean
		  ${RM} $(NAMES)
		  ${RM} $(NAMEC)

re : fclean all

.PHONY: all bonus clean fclean re
