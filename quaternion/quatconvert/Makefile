CC=gcc
dir=quatconvert
PKG=.build/${dir}.o
TEST=.build/test
SAMPLE=.build/sample
LIBVEC=../../vector/.build/vector.o
LIBQUAT=../../quaternion/.build/quaternion.o

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
${SAMPLE}: sample.c ${PKG} ${LIBVEC} ${LIBQUAT}
	${CC} $^ -lm -o $@

${LIBVEC}:
	cd ../../vector; make;

${LIBQUAT}:
	cd ../../quaternion; make;

cleantest:
	rm .build/test

cleansample:
	rm .build/sample

cleanall:
	rm -rdf .build
