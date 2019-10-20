
# PROGRAM:  assign2
# AUTHOR:   Melvyn Salvatierra


# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign2: assign2.o Player.o Team.o
        g++ $(CCFLAGS) -o assign2 assign2.o Player.o Team.o

# Rules to compile source code files to object code
assign2.o: assign2.cpp Team.h
        g++ $(CCFLAGS) -c assign2.cpp

Player.o: Player.cpp Player.h
        g++ $(CCFLAGS) -c Player.cpp

Team.o: Team.cpp Team.h
        g++ $(CCFLAGS) -c Team.cpp

Team.h: Player.h

# Pseudo-target to remove object code and executable files
clean:
        -rm *.o assign2

