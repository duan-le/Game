#SOURCES specifies which files to compile as part of the project
SOURCES = Source/*.cpp

#INCLUDES specifies which directory to find header files
INCLUDES = -I Include

#CC specifies which compiler we're using
CC = g++

#C_FLAGS specifies the additional compilation options we're using
# -Wall shows all warnings and errors
# -g shows extra debug information
C_FLAGS = -Wall -g $(INCLUDES)

#L_FLAGS specifies the libraries we're linking against
L_FLAGS = -lSDL2main -lSDL2 -lSDL2_image

#EXECUTABLE specifies the name of our exectuable
EXECUTABLE = Build/game

#This is the target that compiles our executable
all : $(SOURCES)
	$(CC) $(SOURCES) $(C_FLAGS) $(L_FLAGS) -o $(EXECUTABLE)