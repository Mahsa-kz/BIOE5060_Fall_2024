CC = gcc
CFLAGS = -Wall -pedantic -g
TARGET = laplace2d

all: $(TARGET)

$(TARGET): laplace2d_solver.o laplace2d_func.o
	$(CC) $(CFLAGS) -o $(TARGET) laplace2d_solver.o laplace2d_func.o

laplace2d_solver.o: laplace2d_solver.c laplace2d_func.h
	$(CC) $(CFLAGS) -c laplace2d_solver.c

laplace2d_func.o: laplace2d_func.c laplace2d_func.h
	$(CC) $(CFLAGS) -c laplace2d_func.c

run: $(TARGET)
	./$(TARGET) 60 60 1e-5 1.6

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET) 60 60 1e-5 1.6

clean:
	rm -f *.o $(TARGET)
