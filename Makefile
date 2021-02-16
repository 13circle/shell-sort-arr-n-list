TARGET = pa1
OBJECTS = pa1.o shell_array.o shell_list.o

FLAGS = -g -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic

ALL: $(TARGET) cleanobj

$(TARGET): $(OBJECTS)
	gcc $(FLAGS) -o $@ $^

cleanobj:
	rm $(OBJECTS)

clean:
	rm pa1

