# easy flag

![screenshot at 2018-04-27 08-56-21](https://user-images.githubusercontent.com/22657154/39371342-b54844ac-4a41-11e8-8f4b-abd5b985e075.png)

the program is checking our input then prints Try harder! or correct!, open it up in IDA pro and find the check push button 

![serial1](https://user-images.githubusercontent.com/22657154/39371474-151cc3b2-4a42-11e8-922a-70ae7efc11dd.png)

the program is encoding our input using base64 then compare it to this string which is the flag ```RkxBR3tFQVNZX0xJS0VfMTIzNH0=``` using ```qstrcmp```
so lets deocde this string..
```
root@DESKTOP-NS9V6J9:~# echo RkxBR3tFQVNZX0xJS0VfMTIzNH0= | base64 -d ; echo
FLAG{EASY_LIKE_1234}
root@DESKTOP-NS9V6J9:~#
```

![screenshot at 2018-04-27 09-05-11](https://user-images.githubusercontent.com/22657154/39371581-66ef561e-4a42-11e8-8328-e4f2873b4766.png)
