CFLAGS = -Wall -g

all: hello hello-puts getchar age-height ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex19 ex20 ex21 ex22_main ex23 ex24 ex25 ex31

ex19: object.o

ex22_main: ex22_main.o ex22.o

clean:
	rm -f hello hello-puts getchar age-height ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex19 object.o ex20 ex21 ex22.o ex22_main.o ex22_main ex23 ex24 ex25 ex31