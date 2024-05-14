all:
	gcc -o ttt ./tictactoe.c -L./lib -lgame -lutils

clean:
	rm -f ./ttt
