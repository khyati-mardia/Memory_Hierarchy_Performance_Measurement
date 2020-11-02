CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -O0 -fno-aggressive-loop-optimizations -fno-prefetch-loop-arrays -fno-tree-loop-distribution -fno-tree-loop-distribute-patterns -fno-tree-loop-im 

OBJS =		LinearWrite.o LinearWrite4.o

LIBS =

TARGET =	LinearWrite LinearWrite4

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
