# script to run to obtain for error analysis

# compile demo.out
./compile.sh

# setup environment
touch errors.txt
export OMP_NUM_THREADS=8

# n = 2
./demo.out 2 10 E >> errors.txt
./demo.out 2 100 E  >> errors.txt
./demo.out 2 10000 E >> errors.txt
./demo.out 2 1000000 E >> errors.txt

# n = 3
./demo.out 3 10 E >> errors.txt
./demo.out 3 100 E >> errors.txt
./demo.out 3 10000 E >> errors.txt
./demo.out 3 1000000 E >> errors.txt

# n = 4
./demo.out 4 10 E >> errors.txt
./demo.out 4 100 E >> errors.txt
./demo.out 4 10000 E >> errors.txt
./demo.out 4 1000000 E >> errors.txt

# n = 5
./demo.out 5 10 E >> errors.txt
./demo.out 5 100 E >> errors.txt
./demo.out 5 10000 E >> errors.txt
./demo.out 5 1000000 E >> errors.txt

# n = 6
./demo.out 6 10 E >> errors.txt
./demo.out 6 100 E >> errors.txt
./demo.out 6 10000 E >> errors.txt
./demo.out 6 1000000 E >> errors.txt

# n = 7
./demo.out 7 10 E >> errors.txt
./demo.out 7 100 E >> errors.txt
./demo.out 7 10000 E >> errors.txt
./demo.out 7 1000000 E >> errors.txt

# n = 8
./demo.out 8 10 E >> errors.txt
./demo.out 8 100 E >> errors.txt
./demo.out 8 10000 E >> errors.txt
./demo.out 8 1000000 E >> errors.txt
