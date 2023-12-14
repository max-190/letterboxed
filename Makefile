TARGET = letterboxed
CXX = g++
INC_DIR = inc
SRC_DIR = src
CFLAGS = -Wall -Wextra -Wpedantic -Wfatal-errors -std=c++11 -g

CPPFLAGS = $(addprefix -I, $(INC_DIR))
SOURCES = $(sort $(shell find $(SRC_DIR) -name '*.cc'))
OBJECTS = $(SOURCES:.cc=.o)
DEPS = $(OBJECTS:.o=.d)

.PHONY: all clean
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $^
%.o: %.cc
	$(CXX) $(CFLAGS) $(CPPFLAGS) -MMD -o $@ -c $<
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)
-include $(DEPS)