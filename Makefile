CC      := gcc
NASM    := nasm
CFLAGS  := -m32 -std=c11 -O2 -Wall -DBISECTION -DRECTANGLES -I.
ASMFLAGS:= -f elf32
LDFLAGS := -m32 -lm

SRCS    := main.c \
           root_func/root.c \
           integral_func/integral.c \
           test_func/test.c
OBJS    := $(SRCS:.c=.o) asm_func/functions.o

TARGET  := program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

asm_func/functions.o: asm_func/functions.asm
	$(NASM) $(ASMFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
