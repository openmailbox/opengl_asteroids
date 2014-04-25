OBJS = main.cpp 
LIBS = -lGL -lGLU -lglut
CC = g++ 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Asteroids : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o Asteroids

clean:
	\rm *.o Asteroids
