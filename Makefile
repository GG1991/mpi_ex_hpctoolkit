
all: cpi foo

cpi: cpi.c
	mpicc -g -O3 cpi.c -o cpi

foo: foo.c
	mpicc -g -O3 foo.c -o foo
