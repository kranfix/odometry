CC=gcc
dir=vector
PKG=.build/vector.o
TEST=.build/test

build: ${PKG}

${PKG}: vector.c vector.h .build
	gcc -c $< -o $@

.build:
	mkdir .build

clean:
	rm .build/vector.o

test: ${TEST}
	./.build/test
	

${TEST}: test.c ${PKG}
	${CC} $^ -o $@

cleantest:
	rm .build/test

cleanall:
	rm -rdf .build
