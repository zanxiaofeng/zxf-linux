cc　-o loop loop.c
./loop


cc　-o loop-with-ppid loop-with-ppid.c
./loop-with-ppid

#查看loop-with-ppid依赖于哪些库
ldd loop-with-ppid


#查看ＣＰＵ在用户模式和内核模式的时间(采样间隔１s,%user + %nice 为用户模式时间,%system为在内核模式下执行系统调用所用的时间)
sar -P ALL 1

＃查看给定进程的CPU绑定（亲和性掩码）
taskset -p <pid>

#启动进程时指定CPU绑定
taskset -c 0 ./loop&
taskset -c 1,2 ./loop-with-ppid&

#为已启动的进程指定CPU绑定
taskset -cp <core_no>,<core_no> <pid>
eg: taskset -cp 0,1 7788

taskset -p <mask> <pid>
eg: taskset -p 0x00000003 7788