CC = g++
EXECUTABLE = main
CFLAGS = -c -MMD
LINKFLAG =
SOURCES = line.cpp matrix.cpp row.cpp gcontext.cpp x11context.cpp
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