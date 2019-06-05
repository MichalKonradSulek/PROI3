CC := g++

SRCDIR := src
BUILDDIR := build
TARGET := bin/main
TARGETDIR := bin
TESTFILE := test/test.cpp
TESTOUTPUT := bin/tester
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -Wall -pedantic
TESTFLAGS := -Wall -pedantic -lboost_unit_test_framework
INC := -Iinclude

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) "; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

tester:
	@mkdir -p $(TARGETDIR)
	@echo " $(CC) $(TESTFILE) -o $(TESTOUTPUT) $(TESTFLAGS)"; $(CC) $(TESTFILE) -o $(TESTOUTPUT) $(TESTFLAGS)

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TESTOUTPUT) $(TARGET) $(TARGETDIR)"; $(RM) -r $(BUILDDIR) $(TESTOUTPUT) $(TARGET) $(TARGETDIR)


.PHONY: clean
