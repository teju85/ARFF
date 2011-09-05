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
GTESTSRC := $(shell find $(TESTDIR) -name "*.cc")
TESTOBJS := $(patsubst %.cpp,%.o,$(TESTSRC))
GTOBJS   := $(patsubst %.cc,%.o,$(GTESTSRC))
GTLIB    := libgtest.a
TEST     := arff-test

CPP      := g++
CPPFLAGS := -g -Wall
INCLUDE  := -I$(SRCDIR) -I$(GTESTDIR)/include -I$(GTESTDIR)
LD       := g++
LDFLAGS  := -g -Wall -shared
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
	$(TEST)

$(TEST): $(TESTOBJS) $(GTLIB) $(STATIC)
	$(CPP) $(CPPFLAGS) -o $@ $^

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

%.o: %.cc
	$(CPP) $(CPPFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm -f $(STATIC) $(DYNAMIC) $(OBJFILES)
	rm -f $(TEST) $(TESTOBJS) $(GTOBJS) $(GTLIB)
###