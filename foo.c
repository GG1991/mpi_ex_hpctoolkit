#include <stdio.h>
#include <stdlib.h>

#include "mpi.h"

#define N 50000000
#define N_LOOP 20

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
	int i, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	for(i = 0; i < N_LOOP; ++i) {

		MPI_Barrier(MPI_COMM_WORLD);

		int res_a = func_a(N);

		MPI_Barrier(MPI_COMM_WORLD);

		int res_b = func_b(N);

		MPI_Barrier(MPI_COMM_WORLD);
	}

//	printf("I'm rank %d the result of func_a is %d\n", rank, res_a);
//	printf("I'm rank %d the result of func_b is %d\n", rank, res_b);

	MPI_Finalize();

	return 0;
}
