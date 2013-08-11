#
# Main file responsible for compiling the source code and generating
# doxygen documentation
#

SRCDIR   := src
SRCFILES := $(shell find $(SRCDIR) -name "*.cpp")
OBJFILES := $(patsubst %.cpp,%.o,$(SRCFILES))

TESTDIR  := tests
GTESTDIR := $(TESTDIR)/gtest
TESTSRC  := $(shell find $(TESTDIR) -name "*.cpp")
GTESTSRC := $(TESTDIR)/gtest/src/gtest-all.cc
TESTOBJS := $(patsubst %.cpp,%.o,$(TESTSRC))
GTOBJS   := $(patsubst %.cc,%.o,$(GTESTSRC))
GTLIB    := libgtest.a
TEST     := arff-test

CPP      := g++
CPPFLAGS := -O2 -Wall -Wextra -pedantic
INCLUDE  := -I$(SRCDIR)
TEST_INCLUDE := $(INCLUDE) -I$(GTESTDIR)/include -I$(GTESTDIR)
D       := g++
LDFLAGS  := -O2 -Wall -shared
AR       := ar
ARFLAGS  := rcs

LIBRARY  := arff
DYNAMIC  := lib$(LIBRARY).so
STATIC   := lib$(LIBRARY).a



default: static dynamic test


doc:
	@echo "Generating documentation..."
	docs/genDoc.sh


### unit testing ###
test: $(TEST)
	./$(TEST)

$(TEST): $(TESTOBJS) $(GTLIB) $(STATIC)
	$(CPP) $(CPPFLAGS) -o $@ $^ -lpthread

$(GTLIB): $(GTOBJS)
	$(AR) $(ARFLAGS) $@ $^
###


### dynamic library ###
dynamic: $(DYNAMIC)

$(DYNAMIC): $(OBJFILES)
	@echo TODO
###


### static library ###
static: $(STATIC)

$(STATIC): $(OBJFILES)
	$(AR) $(ARFLAGS) $@ $^
###


### mostly generic ###
%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDE) -c -o $@ $<

tests/%.o: tests/%.cpp
	$(CPP) $(CPPFLAGS) $(TEST_INCLUDE) -c -o $@ $<

%.o: %.cc
	$(CPP) $(CPPFLAGS) $(TEST_INCLUDE) -c -o $@ $<

clean:
	rm -f $(STATIC) $(DYNAMIC) $(OBJFILES)
	rm -f $(TEST) $(TESTOBJS) $(GTOBJS) $(GTLIB)
###
