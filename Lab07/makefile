CC = g++
EXECUTABLE = main
CFLAGS = -c -MMD
LINKFLAG = -lX11
SOURCES = line.cpp triangle.cpp image.cpp matrix.cpp row.cpp gcontext.cpp x11context.cpp main.cpp mydrawing.cpp
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