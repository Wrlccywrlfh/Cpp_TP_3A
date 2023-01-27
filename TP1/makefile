# Makefile with dependencies management (Q4)

CXX        = clang++
CXXFLAGS   = -Wall  -std=c++20
DEPFLAGS   = -MMD
LDFLAGS    =
SRCS       = auteur.cpp lecteur.cpp main.cpp date.cpp livre.cpp emprunt.cpp bibliotheque.cpp#Ensemble fes fichiers à compiler
OBJS       = $(SRCS:.cpp=.o)
TARGET     = app
DEPS	   = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c  $<

clean:
	rm -f *.o *.d

mrproper: clean
	rm -f $(TARGET)

exe: $(TARGET)
	./$(TARGET)

-include $(DEPS)

