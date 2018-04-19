CC=gcc
CFLAGS=-Wall -lX11 -lXtst -g
DFLAGS=
LDFLAGS=-Wl,-z,relro,-z,now 
DIR=src/
DIROUT=bin/


sendkeys: $(DIR)sendkeys.c
	$(CC) $(CFLAGS) $(DFLAGS) -c $(DIR)*.c
	$(CC) -o $(DIROUT)sendkeys lib/ice_config.c lib/ice_config_mem.c *.o $(LDFLAGS) $(CFLAGS) 
	rm *.o

clean:
	rm -f *.o sendkeys

