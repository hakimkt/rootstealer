#!/usr/bin/python
import os
import gi
gi.require_version('Wnck', '3.0') 
from gi.repository import Wnck
from gi.repository import GObject

def changed (screen, window, data):
    if window:
     test_title=window.get_name()
# for debug,remove  comments
#     print test_title+"\n"
     if test_title.find("root@") > 0:
#       print ("Root in terminal window detected")
# call external program to make CMD with X11
       os.system("./sendkeys/bin/sendkeys")


screen = Wnck.Screen.get_default ()
screen.connect ("active-window-changed", changed, None)

mainLoop = GObject.MainLoop ()

try:
    mainLoop.run ()
except KeyboardInterrupt:
    print ("error")

mainLoop.unref ()
