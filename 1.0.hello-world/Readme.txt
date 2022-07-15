C:

cc -o hello-world hello-world.c
./hello-world

strace -T -o hello-world.log ./hello-world

Python:

strace -T -o hello-world.py.log python3 ./hello-world.py