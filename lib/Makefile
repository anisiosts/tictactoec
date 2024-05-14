all:
	gcc -shared -fPIC -o libgame.so game.c
	gcc -shared -fPIC -o libutils.so utils.c

clean:
	rm -f libgame.so
	rm -f libutils.so

install:
	install -m 0644 libgame.so /usr/lib/libgame.so
	install -m 0644 libutils.so /usr/lib/libutils.so

uninstall:
	rm -f /usr/lib/libgame.so
	rm -f /usr/lib/libutils.so
