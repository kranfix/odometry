CC=gcc
dir=quaternion
PKG=.build/${dir}.o
TEST=.build/test

build: ${PKG}

${PKG}: quaternion.c quaternion.h .build
	gcc -c $< -o $@

.build:
	mkdir .build

clean:
	rm .build/quaternion.o

test: ${TEST}
	./.build/test
	

${TEST}: test.c ${PKG}
	${CC} $^ -lm -o $@

cleantest:
	rm .build/test

cleanall:
	rm -rdf .build
