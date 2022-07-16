#fork函数-对应名为clone的系统调用


#Usage:
cc -o fork fork.c
./fork

#Get elf info
//Header
readelf -h ./fork
//Section
readelf -S ./fork