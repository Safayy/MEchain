CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra #-pedantic
LDFLAGS =  -I -L ~/repos/internal/medical_chain/lib/libsocket.cpp.so.0.0.1 -lgtest -lgtest_main -pthread

SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = mechain

SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
INCL = -I $(INCDIR)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CXX) $^ -o $(TARGET) $(LDFLAGS)"; $(CXX) $^ -o $(TARGET) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(shell mkdir -p $(dir $@))
	@echo " $(CXX) $(CXXFLAGS) $(INCL) -c -o $@ $<"; $(CXX) $(CXXFLAGS) $(INCL) -c -o $@ $<

test: $(TARGET)
	./$(TARGET)

run: $(TARGET)
	./$(TARGET)

$(BUILDDIR)/test/%_test.o: test/%_test.cpp
	$(shell mkdir -p $(dir $@))
	$(CXX) $(CXXFLAGS) $(INCL) -c -o $@ $<

$(BUILDDIR)/test/%_test: $(BUILDDIR)/test/%_test.o $(filter-out $(BUILDDIR)/main.o,$(OBJECTS))
	$(shell mkdir -p $(dir $@))
	$(CXX) $(LDFLAGS) $^ -o $@

test-all: $(patsubst %.cpp,$(BUILDDIR)/%.o,$(wildcard test/*_test.cpp))
	$(foreach test, $^, echo Running test $(test); ./$(test);)

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET) $(patsubst %.cpp,$(BUILDDIR)/%.o,$(wildcard test/*_test.cpp)) $(patsubst %.cpp,$(BUILDDIR)/test/%,$(wildcard test/*_test.cpp))

.PHONY: test clean

####################################

# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra #-pedantic
# LDFLAGS =  -I -L ~/repos/internal/medical_chain/lib/libsocket.cpp.so.0.0.1

# SRCDIR = src
# INCDIR = include
# BUILDDIR = build
# TARGET = mechain

# SRCEXT = cpp
# SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
# INCL = -I $(INCDIR)

# $(TARGET): $(OBJECTS)
# 	@echo " Linking..."
# 	@echo " $(CXX) $^ -o $(TARGET) $(LDFLAGS)"; $(CXX) $^ -o $(TARGET) $(LDFLAGS)

# $(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
# 	$(shell mkdir -p $(dir $@))
# 	@echo " $(CXX) $(CXXFLAGS) $(INCL) -c -o $@ $<"; $(CXX) $(CXXFLAGS) $(INCL) -c -o $@ $<

# clean:
# 	@echo " Cleaning..."; 
# 	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# run: $(TARGET)
# 	./$(TARGET)

# .PHONY: clean


