#
# Generic makefile for Mac OSX an example program using the cprocessing library
#
OSTYPE := $(shell uname)
CFLAGS = -g -fPIC

LDFLAGS	= -lcprocessing -lGL -lglut -lGLU
ifeq ("$(OSTYPE)", "Darwin")
	LDFLAGS	= -framework Carbon -framework OpenGL -framework GLUT
endif

CPROCESSINGPATH=../..


SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

all: $(TARGET)
	@echo $(TARGET) built

$(TARGET): $(OBJECTS) $(CPROCESSINGLIB)/libcprocessing.a
	@g++ $(CFLAGS) -o $@ $(OBJECTS) -L$(CPROCESSINGLIB) $(LDFLAGS) -lcprocessing 

clean:
	rm -rf $(OBJECTS) $(TARGET)

%.o: %.cpp $(CPROCESSINGPATH)/cprocessing.hpp
	@echo compiling $<
	@g++ $(CFLAGS) -c $< -o $@ -I$(CPROCESSINGPATH)
