#BLAH_USE_GLUT = 0

All: blahoo_shared
all: All

clean:
	rm *.o

LIBFLAGS := -lGL -lSDL -lGLU

ifdef BLAH_USE_GLUT
	LIBFLAGS := $(LIBFLAGS) -lglut
	BLAHOODEFS := -DBLAH_USE_GLUT
endif

BLAHOOFILES := $(shell echo *.cc)

BLAHOOOBJS := $(subst .cc,.o, $(BLAHOOFILES))

%.o : %.cc %.h
	$(CXX) -c -Wall -Werror  -fPIC $< -o $@

blahoo_shared: $(BLAHOOOBJS)
	g++ -Wall -Werror $(BLAHOOOBJS) $(LIBFLAGS) $(BLAHOODEFS) -shared -o libblahoo.so

install: blahoo_shared
	cp *.h /usr/local/include/blahoo
	cp libblahoo.so /usr/local/lib
