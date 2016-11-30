SHEDSKIN_LIBDIR=/usr/share/shedskin/lib
CC=g++
CCFLAGS=-O2 -march=native -Wno-deprecated $(CPPFLAGS) -I. -I${SHEDSKIN_LIBDIR}
LFLAGS=-lgc -lpcre $(LDFLAGS)

CPPFILES=/home/tmn07/Project/Bioinf/DT/DT.cpp \
	${SHEDSKIN_LIBDIR}/re.cpp \
	${SHEDSKIN_LIBDIR}/math.cpp \
	${SHEDSKIN_LIBDIR}/csv.cpp \
	${SHEDSKIN_LIBDIR}/builtin.cpp

HPPFILES=/home/tmn07/Project/Bioinf/DT/DT.hpp \
	${SHEDSKIN_LIBDIR}/re.hpp \
	${SHEDSKIN_LIBDIR}/math.hpp \
	${SHEDSKIN_LIBDIR}/csv.hpp \
	${SHEDSKIN_LIBDIR}/builtin.hpp

all:	DT

DT:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o DT

DT_prof:	$(CPPFILES) $(HPPFILES)
	$(CC) -pg -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o DT_prof

DT_debug:	$(CPPFILES) $(HPPFILES)
	$(CC) -g -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o DT_debug

clean:
	rm -f DT DT_prof DT_debug

.PHONY: all clean

