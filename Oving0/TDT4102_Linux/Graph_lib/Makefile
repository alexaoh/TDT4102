INSTALL_DIR=/usr/local
INSTALL_DIR_INCLUDE=$(INSTALL_DIR)/include/Graph_lib
INSTALL_DIR_LIB=$(INSTALL_DIR)/lib/Graph_lib

CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LINK = $(CXX)

CXXFLAGS += $(shell fltk-config --use-images --cxxflags)
LDFLAGS  += $(shell fltk-config --use-images --ldflags)
LDSTATIC = $(shell fltk-config --use-images --ldstaticflags)

SOURCES := $(wildcard src/*.cpp)

ifdef DEBUG
OBJECTS := $(SOURCES:src/%.cpp=lib/%d.o)
CXXFLAGS += -g -Og -DDEBUG
else
OBJECTS := $(SOURCES:src/%.cpp=lib/%.o)
CXXFLAGS += -O3 -DNDEBUG
endif

lib:
	@mkdir -p $@

lib/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
lib/%d.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

lib/%.a: lib $(OBJECTS)
	$(AR) -r $@ $(filter-out $<, $^)

.PHONY: clean
clean:
	$(warning Cleaning all build files)
	@$(RM) -r lib

.PHONY: install
install:
	$(info Installing libraries and include files)
	mkdir -p $(INSTALL_DIR_LIB)
	mkdir -p $(INSTALL_DIR_INCLUDE)
	cp -r lib/. $(INSTALL_DIR_LIB)
	cp -r include/. $(INSTALL_DIR_INCLUDE)

.PHONY: uninstall
uninstall:
	$(warning Uninstalling libraries and include files)
	$(RM) -r $(INSTALL_DIR_LIB)
	$(RM) -r $(INSTALL_DIR_INCLUDE)

# Helper targets to ease build of debug and release versions
.PHONY: debug release
debug:
	DEBUG=1 $(MAKE) lib/libGraph_libd.a
release:
	$(MAKE) lib/libGraph_lib.a

.PHONY: all
all: debug release
