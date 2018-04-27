# x_or_what

the  program logic is seems to be obfuscated at first look but after taking some time debugging and renaming the values you'll get this 
```C
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // edx
  __int64 INPUT; // rax
  QChar *input_16; // r13
  signed int input_length; // er12
  __int64 v7; // rax
  int v8; // edx
  __int64 v9; // rcx
  void *v10; // rsp
  __int64 counter; // rbx
  char output; // al
  __int64 Counter3; // rbx
  QTextStream *v15; // [rsp+0h] [rbp-B0h]
  QCoreApplication *v16; // [rsp+8h] [rbp-A8h]
  int KEY_lenght; // [rsp+14h] [rbp-9Ch]
  __int64 v18; // [rsp+18h] [rbp-98h]
  QString *input_after_mod; // [rsp+20h] [rbp-90h]
  int Counter2; // [rsp+28h] [rbp-88h]
  int v21; // [rsp+2Ch] [rbp-84h]
  __int64 v22; // [rsp+38h] [rbp-78h]
  __int64 KEY; // [rsp+40h] [rbp-70h]
  volatile signed __int32 *empty_string; // [rsp+48h] [rbp-68h]
  char v25; // [rsp+50h] [rbp-60h]
  __int64 v26; // [rsp+60h] [rbp-50h]
  volatile signed __int32 *serial_char_by_char; // [rsp+70h] [rbp-40h]

  v21 = argc;
  v16 = &v25;
  QCoreApplication::QCoreApplication(&v25, &v21, argv, 17041415);
  LODWORD(serial_char_by_char) = 3;
  v15 = &v26;
  QTextStream::QTextStream(&v26, stdin, &serial_char_by_char);
  LODWORD(empty_string) = 3;
  input_after_mod = &empty_string;
  QTextStream::QTextStream(&serial_char_by_char, stdout, &empty_string);
  QTextStream::operator<<(&serial_char_by_char, "Input The Flag : ");
  QTextStream::~QTextStream(&serial_char_by_char);
  QTextStream::readLine(&v22, &v26);
  KEY = QString::fromAscii_helper("44", 0xFFFFFFFFLL, v3);
  INPUT = v22;
  if ( *v22 != 1 || *(v22 + 16) != v22 + 26 )
  {
    QString::realloc(&v22);
    INPUT = v22;
  }
  input_16 = *(INPUT + 16);
  input_length = *(INPUT + 8);
  v7 = KEY;
  if ( *KEY != 1 || (v8 = KEY + 26, *(KEY + 16) != KEY + 26) )
  {
    QString::realloc(&KEY);
    v7 = KEY;
  }
  v9 = *(v7 + 16);
  KEY_lenght = *(v7 + 8);
  v18 = v9;
  v10 = alloca(input_length);
  counter = 0LL;
  empty_string = QString::fromAscii_helper("", 0xFFFFFFFFLL, v8);
  if ( input_length >= 0 )
  {
    do
    {
      Counter2 = counter;
      LOBYTE(Counter2) = QChar::toAscii(input_16);
      output = QChar::toAscii((v18 + 2LL * (counter % KEY_lenght) + 2));
      input_16 = (input_16 + 2);
      *(&v15 + counter++) = Counter2 ^ output;
    }
    while ( input_length >= counter );
    Counter3 = 0LL;
    do
    {
      while ( 1 )
      {
        QString::number(&serial_char_by_char, *(&v15 + Counter3), 10);
        QString::append(input_after_mod, &serial_char_by_char);
        if ( !_InterlockedDecrement(serial_char_by_char) )
          break;
        if ( input_length < ++Counter3 )
          goto LABEL_13;
      }
      ++Counter3;
      QString::free(serial_char_by_char);
    }
    while ( input_length >= Counter3 );
  }
LABEL_13:
  if ( qStringComparisonHelper(input_after_mod, "114761177179119921017051107497195895510710951108012552") )
  {
    QDebug::QDebug(&serial_char_by_char, 0);
    QDebug::operator<<(&serial_char_by_char, "Correct !!");
  }
  else
  {
    QDebug::QDebug(&serial_char_by_char, 0);
    QDebug::operator<<(&serial_char_by_char, "Try Harder !");
  }
  QDebug::~QDebug(&serial_char_by_char);
  if ( !_InterlockedDecrement(empty_string) )
    QString::free(empty_string);
  if ( !_InterlockedDecrement(KEY) )
    QString::free(KEY);
  if ( !_InterlockedDecrement(v22) )
    QString::free(v22);
  QTextStream::~QTextStream(v15);
  QCoreApplication::~QCoreApplication(v16);
  return 0;
}
```
After you remove the unnecessary parts, you will have this clear code..
```C
int __cdecl main(int argc, const char **argv, const char **envp)
{

  QTextStream::QTextStream(&v26, stdin, &serial_char_by_char);
  LODWORD(empty_string) = 3;
  input_after_mod = &empty_string;
  QTextStream(stdout) << "Input The Flag : ";
  QTextStream::readLine(&take_input, &v26);
  KEY = "44";
  INPUT = take_input;
  if ( *v22 != 1 || *(v22 + 16) != v22 + 26 )
  {
    QString::realloc(&v22);
    INPUT = v22;
  }
  input_16 = *(INPUT + 16);
  input_length = *(INPUT + 8);
  v7 = KEY;
  if ( *KEY != 1 || (v8 = KEY + 26, *(KEY + 16) != KEY + 26) )
  {
    QString::realloc(&KEY);
    v7 = KEY;
  }
  v9 = *(v7 + 16);
  KEY_lenght = *(v7 + 8);
  v18 = v9;
  v10 = alloca(input_length);
  counter = 0LL;
  empty_string = QString::fromAscii_helper("", 0xFFFFFFFFLL, v8);
  if ( input_length >= 0 )
  {
    do
    {
      Counter2 = counter;
      LOBYTE(Counter2) = QChar::toAscii(input_16);
      output = QChar::toAscii((v18 + 2LL * (counter % KEY_lenght) + 2));
      input_16 = (input_16 + 2);
      *(&v15 + counter++) = Counter2 ^ output;
    }
    while ( input_length >= counter );
    Counter3 = 0LL;
    do
    {
      while ( 1 )
      {
        QString::number(&serial_char_by_char, *(&v15 + Counter3), 10);
        QString::append(input_after_mod, &serial_char_by_char);
        if ( !_InterlockedDecrement(serial_char_by_char) )
          break;
        if ( input_length < ++Counter3 )
          goto LABEL_13;
      }
      ++Counter3;
      QString::free(serial_char_by_char);
    }
    while ( input_length >= Counter3 );
  }
LABEL_13:
  if ( qStringComparisonHelper(input_after_mod, "114761177179119921017051107497195895510710951108012552") )
  {
    QDebug::operator<<(&serial_char_by_char, "Correct !!");
  }
  else
  {
    QDebug::operator<<(&serial_char_by_char, "Try Harder !");
  }
  return 0;
}
```
so let's explain what is going on, first the program is taking an input from us
then declare a key with the value 44, then declaring two variables the first one is the key length the second is our input length 
afer this step the program starts two loops,
the first one is doing xor on our inputted string char by char using ```(counter % KEY_lenght) + 2)```
the second loop is for recombine the xored hex values together inside one string then compare it to the value ``` 114761177179119921017051107497195895510710951108012552```
and if both values are the same it will print correct..
i wrote this python script to reverse the algorithm 
