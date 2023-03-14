CC = g++
EXECUTABLE = main
CFLAGS = -c -MMD
LINKFLAG =
SOURCES = main.cpp row.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(EXECUTABLE):$(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LINKFLAG)

-include *.d

%.o:%.cpp
	$(CC) $(CFLAGS) $<
clean:
	rm -f $(EXECUTABLE)
	rm -f $(OBJECTS)
	rm -f *.d