#
# Taken from pcg-c-basic Makefile
#

TARGETS = run-tiny-quake

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)
	rm -rf ./tiny-quake_dwo/

run-tiny-quake: build-tiny-quake
	./tiny-quake

build-tiny-quake: tiny-quake.o
	clang -Wall -Wextra -Wswitch-enum -ggdb -lraylib -lm -I/usr/include -DPLATFORM_DESKTOP_SDL -std=gnu23 tiny-quake.c -o tiny-quake

tiny-quake.o: tiny-quake.c
	clang -Wall -Wextra -Wswitch-enum -ggdb -c  tiny-quake.c -o tiny-quake.o
