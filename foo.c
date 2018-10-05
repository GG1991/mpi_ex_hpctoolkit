#include <stdio.h>
#include <stdlib.h>

#include "mpi.h"

int func_a(int n)
{
	int i, sum = 0;
	for(i = 1; i < n; ++i)
		sum += i;
	return sum;
}

int func_b(int n)
{
	int i, sum = 0;
	for(i = 1; i < 2 * n; ++i)
		sum += i;
	return sum;
}

int main(int argc, char **argv)
{
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(argc == 1) {
		printf("Error: One integer argument should be given as argument: <executable> NUM");
		exit(1);
	}

	int res_a = func_a(atoi(argv[1]));
	int res_b = func_b(atoi(argv[1]));

	printf("I'm rank %d the result of func_a is %d\n", rank, res_a);
	printf("I'm rank %d the result of func_b is %d\n", rank, res_b);

	MPI_Finalize();

	return 0;
}
