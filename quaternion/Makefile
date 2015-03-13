CC=gcc
dir=quaternion
PKG=.build/${dir}.o
TEST=.build/test
SAMPLE=.build/sample

build: ${PKG}

${PKG}: quaternion.c quaternion.h .build
	gcc -c $< -o $@

.build:
	mkdir .build

clean:
	rm .build/quaternion.o

test: ${TEST}
sample:${SAMPLE}
	./.build/$@
	

${TEST}: test.c ${PKG}
${SAMPLE}: sample.c ${PKG}
	${CC} $^ -lm -o $@

cleantest:
	rm .build/test

cleansample:
	rm .build/sample

cleanall:
	rm -rdf .build
