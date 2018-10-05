#!/bin/bash

#SBATCH --workdir=.
#SBATCH --output=example_%j.out
#SBATCH --error=example_%j.err
#SBATCH --cpus-per-task=1
#SBATCH --ntasks=16
#SBATCH --qos=debug
#SBATCH --time=00:00:30

#mpirun hpcrun ./a.out 100
mpirun hpcrun -t ./foo 100

