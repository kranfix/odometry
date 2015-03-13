CC=gcc
dir=vector
PKG=.build/vector.o
TEST=.build/test
SAMPLE=.build/sample

build: ${PKG}

${PKG}: ${dir}.c ${dir}.h .build
	gcc -c $< -o $@

.build:
	mkdir .build

clean:
	rm .build/${dir}.o

test: ${TEST}
sample: ${SAMPLE}
	./.build/$@
	

${TEST}: test.c ${PKG}
${SAMPLE}: sample.c ${PKG}
	${CC} $^ -o $@

cleantest:
	rm .build/test

cleansample:
	rm .build/sample

cleanall:
	rm -rdf .build
