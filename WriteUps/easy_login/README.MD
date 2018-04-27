# easy_login
here we have a program that requires username and password to login if we run it with random inputs it prints ```Try Harder!```
so lets try harder.. open up IDA pro, start linux remote debugging and since we know that this program is using QT libraries because of all this Q letters at the first of every function we have find a push button to see what is going inside.
![easylogin1](https://user-images.githubusercontent.com/22657154/39370358-faeab5b0-4a3e-11e8-8ff1-1260797b02f1.png)
to print out correct we have to access label_51
which will be called if v23 is equal to ```NzczNDZiMzM1NTcwNmU2NTMwMzA=``` inside label_33
which will be called if v22 is equal to ```NmU2NTZm``` inside label 48 
![easylogin2](https://user-images.githubusercontent.com/22657154/39370461-3dff566c-4a3f-11e8-8f4a-4ce2a6359530.png)

and here between 73-76 and 33-36 we can see that our input is modified into several formats before being comparted 

![easylogin73-76](https://user-images.githubusercontent.com/22657154/39370500-5b03678a-4a3f-11e8-933e-2e475e81afc3.png)
![easylogin33-36](https://user-images.githubusercontent.com/22657154/39370501-5b416f08-4a3f-11e8-8687-9da57c29a228.png)

```
text->ascii->hex->base64
```

so we clearly see that we have to decode these two strings to get the valid username and password..
```
root@DESKTOP-NS9V6J9:~# echo NzczNDZiMzM1NTcwNmU2NTMwMzA= | base64 -d ; echo
77346b3355706e653030
root@DESKTOP-NS9V6J9:~# echo NmU2NTZm | base64 -d ; echo
6e656f
root@DESKTOP-NS9V6J9:~# python
Python 2.7.12 (default, Dec  4 2017, 14:50:18)
[GCC 5.4.0 20160609] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> "77346b3355706e653030".decode("hex")
'w4k3Upne00'
>>> "6e656f".decode("hex")
'neo'
>>>
```
![screenshot at 2018-04-27 09-33-17](https://user-images.githubusercontent.com/22657154/39370642-bbdbf482-4a3f-11e8-99f4-f98a0172197f.png)
