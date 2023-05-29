TARGETC=Client
TARGETG=Game
TARGETS=Server
CC=gcc
CFLAGS=-o

all: $(TARGETC) $(TARGETG) $(TARGETS)

$(TARGETC): Client.cpp
	$(CC) Client.cpp $(CFLAGS) $(TARGETC)

$(TARGETS): Server.cpp
	$(CC) Server.cpp $(CFLAGS) $(TARGETS)

$(TARGETG): Game.cpp
	$(CC) Game.cpp $(CFLAGS) $(TARGETG)


clean:
	rm -f $(TARGETC)
	rm -f $(TARGETG)
	rm -f $(TARGETS)

