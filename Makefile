CXX:=clang++
CXXFLAGS:=-Wall
LDFLAGS:=-lSDL2 -lSDL2_image
SOURCES:=$(wildcard *.cpp)
OBJS:=$(SOURCES:.cpp=.o)
EXECUTABLE:=template

$(EXECUTABLE): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(EXECUTABLE)
