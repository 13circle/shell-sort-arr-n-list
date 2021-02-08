TARGET = pa1
OBJECTS = src/pa1.o src/util/shell_array.o src/util/shell_list.o

FLAGS = -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic

ALL: $(TARGET) cleanobj

$(TARGET): $(OBJECTS)
	gcc $(FLAGS) -o $@ $^

cleanobj:
	rm $(OBJECTS)

clean:
	rm pa1

