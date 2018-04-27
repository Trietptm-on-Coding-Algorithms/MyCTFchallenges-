# easy_jump.bin

run the binary ..

```assembly
┌─[root@parrot]─[~/crackmes/linux64-bin]
└──╼ #./easy_jump.bin 
There is nothing to do here !
```

open it up with gdb and list functions ..
```assembly
gdb-peda$ info functions 
All defined functions:

Non-debugging symbols:
0x0000000000000790  _init
0x00000000000007c0  __cxa_atexit@plt
0x00000000000007d0  std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt
0x00000000000007e0  std::ostream::operator<<(std::ostream& (*)(std::ostream&))@plt
0x00000000000007f0  std::ios_base::Init::Init()@plt
0x0000000000000800  std::ostream::operator<<(int)@plt
0x0000000000000820  _start
0x0000000000000850  deregister_tm_clones
0x0000000000000890  register_tm_clones
0x00000000000008e0  __do_global_dtors_aux
0x0000000000000920  frame_dummy
0x000000000000092a  nothing()
0x0000000000000944  flag()
0x00000000000009d8  main
0x00000000000009f3  __static_initialization_and_destruction_0(int, int)
0x0000000000000a3c  _GLOBAL__sub_I__Z7nothingv
0x0000000000000a60  __libc_csu_init
0x0000000000000ad0  __libc_csu_fini
0x0000000000000ad4  _fini
gdb-peda$ 
```
here is we can see the functions named ```flag``` and ```nothing``` which located before the main function..
```assembly
gdb-peda$ set disassembly-flavor intel
gdb-peda$ disassemble main
Dump of assembler code for function main:
   0x00000000000009d8 <+0>:	push   rbp
   0x00000000000009d9 <+1>:	mov    rbp,rsp
   0x00000000000009dc <+4>:	sub    rsp,0x10
   0x00000000000009e0 <+8>:	mov    DWORD PTR [rbp-0x4],edi
   0x00000000000009e3 <+11>:	mov    QWORD PTR [rbp-0x10],rsi
   0x00000000000009e7 <+15>:	call   0x92a <_Z7nothingv>
   0x00000000000009ec <+20>:	mov    eax,0x0
   0x00000000000009f1 <+25>:	leave  
   0x00000000000009f2 <+26>:	ret    
End of assembler dump.
```
the main function is just calling the function ```nothing``` and exits.. so all we have to do is to call the ```flag``` function..

```assembly
gdb-peda$ b main
Breakpoint 1 at 0x9dc
gdb-peda$ run
gdb-peda$ call flag() 
Good job : Flag is : 32767
$1 = 0x55755060
gdb-peda$ 
```
``` Flag is 32767 ```

