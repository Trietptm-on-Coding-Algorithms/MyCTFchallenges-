# x_or_what

From IDA pro..

```C
 QTextStream::operator<<(&v31, "Input The Flag : ");
  QTextStream::~QTextStream(&v31);
  QTextStream::readLine(&v24, &v30);
  v25 = QString::fromAscii_helper("44", 0xFFFFFFFFLL, v3);
  v4 = v24;
  if ( *v24 != 1 || *(v24 + 16) != v24 + 26 )
  {
    QString::realloc(&v24);
    v4 = v24;
  }
  v5 = *(v4 + 16);
  v6 = *(v4 + 8);
  v7 = v25;
  if ( *v25 != 1 || (v8 = v25 + 26, *(v25 + 16) != v25 + 26) )
  {
    QString::realloc(&v25);
    v7 = v25;
  }
  v20 = *(v7 + 16);
  v9 = alloca(v6);
  v26 = QString::fromAscii_helper("", 0xFFFFFFFFLL, v8);
  v10 = &v18;
  if ( v6 >= 0 )
  {
    do
    {
      LOBYTE(v21) = QChar::toAscii(v5);
      v11 = QChar::toAscii(v20);
      v10 = (v10 + 1);
      v5 = (v5 + 2);
      *(v10 - 1) = v21 ^ v11;
    }
    while ( v6 >= (v10 - &v18) );
    v12 = 0LL;
    v21 = &v27;
    do
    {
      while ( 1 )
      {
        QString::number(v21, *(&v18 + v12), 10);
        v28 = v27;
        _InterlockedIncrement(v27);
        QString::fromAscii(&v31, " ", -1);
        QString::append(v22, &v31);
        if ( !_InterlockedDecrement(v31) )
          QString::free(v31, &v31);
        v13 = v22;
        QString::append(&v26, v22);
        if ( !_InterlockedDecrement(v28) )
          QString::free(v28, v13);
        if ( !_InterlockedDecrement(v27) )
          break;
        if ( v6 < ++v12 )
          goto LABEL_17;
      }
      ++v12;
      QString::free(v27, v13);
    }
    while ( v6 >= v12 );
  }
LABEL_17:
  QDebug::QDebug(&v31, 0LL);
  v14 = QTextStream::operator<<(v31, 34LL);
  v15 = QTextStream::operator<<(v14, &v26);
  QTextStream::operator<<(v15, 34LL);
  if ( *(v31 + 32) )
    QTextStream::operator<<(v31, 32LL);
  QDebug::~QDebug(&v31);
  if ( qStringComparisonHelper(&v26, "114 120 117 115 79 67 92 81 70 81 107 93 71 107 89 77 107 89 93 90 80 73 52 ") )
  {
    QDebug::QDebug(&v31, 0LL);
    v16 = "Correct !!";
  }
  else
  {
    QDebug::QDebug(&v31, 0LL);
    v16 = "Try Harder !";
  }
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
