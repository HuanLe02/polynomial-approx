# script to run to obtain for error analysis

# compile demo.out
./compile.sh
# T = 1
export OMP_NUM_THREADS=1
./demo.out 8 1000000 T
./demo.out 8 1000000 T
./demo.out 8 1000000 T

# T = 2
export OMP_NUM_THREADS=2
./demo.out 8 1000000 T
./demo.out 8 1000000 T
./demo.out 8 1000000 T

# T = 3
export OMP_NUM_THREADS=3
./demo.out 8 1000000 T
./demo.out 8 1000000 T
./demo.out 8 1000000 T

# T = 4
export OMP_NUM_THREADS=4
./demo.out 8 1000000 T
./demo.out 8 1000000 T
./demo.out 8 1000000 T

# T = 8
export OMP_NUM_THREADS=5
./demo.out 8 1000000 T
./demo.out 8 1000000 T
./demo.out 8 1000000 T

# T = 6
export OMP_NUM_THREADS=6
./demo.out 8 1000000 T
./demo.out 8 1000000 T
./demo.out 8 1000000 T

# T = 7
export OMP_NUM_THREADS=7
./demo.out 8 1000000 T
./demo.out 8 1000000 T
./demo.out 8 1000000 T

# T = 8
export OMP_NUM_THREADS=8
./demo.out 8 1000000 T
./demo.out 8 1000000 T
./demo.out 8 1000000 T

