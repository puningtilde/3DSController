CC      := gcc
LN      := gcc
ODIR    := build
SDIR    := source
IDIR    := include
LDIR    := lib
CFLAGS  := -I$(IDIR) -fms-extensions -O2 -Wall
LFLAGS  := -L$(LDIR) -lvJoyInterface -lws2_32 -lgdi32 -lgdiplus -static-libgcc
CFILES  := $(wildcard $(SDIR)/*.c)
OBJS    := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(wildcard $(SDIR)/*.c))

TARGET  := 3DSController.exe

$(TARGET): $(ODIR) $(OBJS)
	$(LN) $(ODIR)/*.o -o $(TARGET) $(CFLAGS) $(LFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	@mkdir -p $@

.PHONY: clean

clean:
	rm -f $(TARGET) $(ODIR)/*.o