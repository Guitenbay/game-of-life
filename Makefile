build: main.c grid.h functional.h tips.h event.h _kbhit.h gol.h;
	gcc main.c --include grid.h grid.c functional.h functional.c event.h event.c tips.h tips.c _kbhit.h _kbhit.c gol.h && mv ./a.out ./main

run:
	./main

clean:
	rm ./main *.h.gch
	