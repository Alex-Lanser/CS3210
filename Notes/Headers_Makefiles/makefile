
#target:prerequisites	for example... math.cpp is a prerequisite for math.o
    #recipe/commands to make the target

# Compiler name is g++
CC = g++
EXECUTABLE = making_ex1
CFLAGS = -c -MMD
LINKFLAG =
SOURCES = math.cpp main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)

$(EXECUTABLE):$(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LINKFLAG)

# math.o: math.cpp
# 	$(CC) $(CFLAGS) math.cpp

# main.o: main.cpp
# 	$(CC) $(CFLAGS) main.cpp
-include *.d

%.o:%.cpp
	$(CC) $(CFLAGS) $<
# Instead of making the targets individually, this does all of them

#!! Then type make in console to recompile !!

clean:
	rm -f $(EXECUTABLE)
	rm -f $(OBJECTS)
	rm -f *.d
# Type make clean in console and it will only run the clean target
# Same thing with just typing make math.o, it will only run that target
# -f tags will prevent from the console from complaining if make clean is called twice in a row