# Datei: Makefile

CXX = cl
CXXFLAGS = /EHsc /nologo
LD = link
LDFLAGS = /nologo
RM = del

MAIN_EXECUTABLE = main.exe

all: $(MAIN_EXECUTABLE)
.PHONY: all

$(MAIN_EXECUTABLE): main.obj sort.obj
	$(LD) $(LDFLAGS) $^ /OUT:$@

%.obj: %.cpp %.h
	$(CXX) $(CXXFLAGS) /c $<

clean:
	$(RM) *.obj
.PHONY: clean

distclean: clean
	del $(MAIN_EXECUTABLE)
.PHONY: distclean