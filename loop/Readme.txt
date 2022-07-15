cc　-o loop loop.c
./loop


cc　-o loop-with-ppid loop-with-ppid.c
./loop-with-ppid



#查看ＣＰＵ在用户模式和内核模式的时间(采样间隔１s,%user + %nice 为用户模式时间,%system为在内核模式下执行系统调用所用的时间)
sar -P ALL 1