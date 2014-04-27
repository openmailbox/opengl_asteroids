OBJS = main.cpp ship.o bullet.o bullet_pool.o asteroid.o asteroid_pool.o
LIBS = -lGL -lGLU -lglut
CC = g++ 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Asteroids : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o Asteroids

ship.o : ship.h ship.cpp
	$(CC) $(CFLAGS) ship.cpp $(LIBS)

bullet.o : bullet.h bullet.cpp
	$(CC) $(CFLAGS) bullet.cpp $(LIBS)

bullet_pool.o : bullet_pool.h bullet_pool.cpp
	$(CC) $(CFLAGS) bullet_pool.cpp $(LIBS)

asteroid.o : asteroid.h asteroid.cpp
	$(CC) $(CFLAGS) asteroid.cpp $(LIBS)

asteroid_pool.o : asteroid_pool.h asteroid_pool.cpp
	$(CC) $(CFLAGS) asteroid_pool.cpp $(LIBS)

clean:
	\rm *.o Asteroids
