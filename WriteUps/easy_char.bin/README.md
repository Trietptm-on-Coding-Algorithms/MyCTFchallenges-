# easy_char.bin
run the binary ..

```
┌─[root@parrot]─[~/crackmes/linux64-bin]
└──╼ #./easy_char.bin 
Usage: ./easy_char.bin Flag
┌─[root@parrot]─[~/crackmes/linux64-bin]
└──╼ #./easy_char.bin 12345
Try Harder :)
```

Using ```strings``` command we can clearly see the string ```Good job, Flag is :```

```
┌─[root@parrot]─[~/crackmes/linux64-bin]
└──╼ #strings easy_char.bin | grep "Try Harder" -A 5 -B 5 
AUATL
[]A\A]A^A_
Usage: 
 Flag
Good job, Flag is : 
Try Harder :)
;*3$"
zPLR
GCC: (Debian 7.3.0-11) 7.3.0
crtstuff.c
deregister_tm_clones
```
So the flag is generated using an algorithm inside the binary.
Open up the binary file using any disassembler i'm using radare2 here.

```
┌─[root@parrot]─[~/crackmes/linux64-bin]
└──╼ #radare2 -d ./easy_char.bin 
[0x7f0c6ab2f090]> aaaa
[0x7f0c6ab2f090]> afl
.............
0x55fc93258b30    1 43           entry0
0x55fc93258b60    4 50   -> 40   sym.deregister_tm_clones
0x55fc93258ba0    4 66   -> 57   sym.register_tm_clones
0x55fc93258bf0    4 49           sym.__do_global_dtors_aux
0x55fc93258c30    1 10           entry1.init
0x55fc93258c3a    4 99           sym.flag
0x55fc93258c9d    7 338  -> 312  main
..............
[0x7f0c6ab2f090]> s main
[0x55fc93258c9d]> pdf
/ (fcn) main 312
|   main ();
............
|      ,==< 0x55fc93258cea      e9d8000000     jmp 0x55fc93258dc7
|      |`-> 0x55fc93258cef      c645a046       mov byte [local_60h], 0x46 ; 'F' ; 70
|      |    0x55fc93258cf3      c645a14c       mov byte [local_5fh], 0x4c ; 'L' ; 76
|      |    0x55fc93258cf7      c645a241       mov byte [local_5eh], 0x41 ; 'A' ; 65
|      |    0x55fc93258cfb      c645a347       mov byte [local_5dh], 0x47 ; 'G' ; 71
|      |    0x55fc93258cff      c645a47b       mov byte [local_5ch], 0x7b ; '{' ; 123
|      |    0x55fc93258d03      c645a548       mov byte [local_5bh], 0x48 ; 'H' ; 72
|      |    0x55fc93258d07      c645a633       mov byte [local_5ah], 0x33 ; '3' ; 51
|      |    0x55fc93258d0b      c645a745       mov byte [local_59h], 0x45 ; 'E' ; 69
|      |    0x55fc93258d0f      c645a831       mov byte [local_58h], 0x31 ; '1' ; 49
|      |    0x55fc93258d13      c645a931       mov byte [local_57h], 0x31 ; '1' ; 49
|      |    0x55fc93258d17      c645aa30       mov byte [local_56h], 0x30 ; '0' ; 48
|      |    0x55fc93258d1b      c645ab5f       mov byte [local_55h], 0x5f ; '_' ; 95
|      |    0x55fc93258d1f      c645ac46       mov byte [local_54h], 0x46 ; 'F' ; 70
|      |    0x55fc93258d23      c645ad72       mov byte [local_53h], 0x72 ; 'r' ; 114
|      |    0x55fc93258d27      c645ae31       mov byte [local_52h], 0x31 ; '1' ; 49
|      |    0x55fc93258d2b      c645af38       mov byte [local_51h], 0x38 ; '8' ; 56
|      |    0x55fc93258d2f      c645b04e       mov byte [local_50h], 0x4e ; 'N' ; 78
|      |    0x55fc93258d33      c645b164       mov byte [local_4fh], 0x64 ; 'd' ; 100
|      |    0x55fc93258d37      c645b27d       mov byte [local_4eh], 0x7d ; '}' ; 125
|      |    0x55fc93258d3b      c645b300       mov byte [local_4dh], 0
.............
```
here is our first flag putted in a plain text as a char array ```FLAG{H3E110_Fr18Nd}``` lets try it as an input..
```
┌─[root@parrot]─[~/crackmes/linux64-bin]
└──╼ #./easy_char.bin FLAG{H3E110_Fr18Nd}
Good job, Flag is : 83916
```
and here is the flag we're looking for ```83916```

