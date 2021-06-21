CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic

xlat:

clean:
	${RM} *.o xlat

.PHONY: clean
