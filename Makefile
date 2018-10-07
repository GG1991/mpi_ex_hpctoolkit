
all: cpi foo

cpi: cpi.c
	mpicc -g -O0 cpi.c -o cpi

foo: foo.c
	mpicc -g -O0 foo.c -o foo
