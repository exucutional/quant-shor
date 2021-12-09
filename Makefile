TARGET = main
ARGS   =

.PHONY: all compile run debug clean

all: clean run

compile: $(TARGET).cpp
	g++ $(TARGET).cpp -o $(TARGET) -g -Wall

run: compile
	./$(TARGET) $(ARGS)

debug: compile
	gdb --args ./$(TARGET) $(ARGS)

clean:
	rm -rf $(TARGET)
