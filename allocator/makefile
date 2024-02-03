CXX=g++

CXXFLAGS=-std=c++20 -Wall

TARGET=build/main

OBJDIR=build

OBJECTS=$(OBJDIR)/main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJDIR)/*.o
	@rmdir $(OBJDIR)

.PHONY: all clean