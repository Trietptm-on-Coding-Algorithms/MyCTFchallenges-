# x_or_what

the  program logic is seems to be obfuscating at tje first look but after taking some time debugging and renaming the values you'll get this 

```C
```
After you remove the unnecessary parts, you will have this clear code..
```C

```

the program is reading the input from us, set the xor key value to 44 then do xor 
on our input string char by char.. after this it combines all the xored hex values in one string
to comparte it with ```114 120 117 115 79 67 92 81 70 81 107 93 71 107 89 77 107 89 93 90 80 73 52 ``` string

i wrote this python script to reverse the algorithm 
```python
#!/bin/python
import string

strings = "ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`{}!abcdefghijklmnopqrstuvwxyz0123456789"
strings = list(strings)
key = "44"
I=0
flag =  ''
hexstring = "114,120,117,115,79,67,92,81,70,81,107,93,71,107,89,77,107,89,93,90,80,73,52"
hexstring = hexstring.split(",")
for i in range(len(hexstring)):
   I=0
   for s in strings:
      temp = ord(strings[I])^ ord(key[0])
      if str(temp) == hexstring[i]:
          print str(temp) + "\t=>\t" + str(s)
          flag += s
          break
      I+=1
print ""
print "Flag : " + flag
```

```assembly
root@DESKTOP-NS9V6J9:/mnt/c/Users/Magdy Moustafa/Desktop# python alg.py
114     =>      F
120     =>      L
117     =>      A
115     =>      G
79      =>      {
67      =>      w
92      =>      h
81      =>      e
70      =>      r
81      =>      e
107     =>      _
93      =>      i
71      =>      s
107     =>      _
89      =>      m
77      =>      y
107     =>      _
89      =>      m
93      =>      i
90      =>      n
80      =>      d
73      =>      }

Flag : FLAG{where_is_my_mind}
```
