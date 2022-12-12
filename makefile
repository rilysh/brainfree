CC=cc
FLAGS=-Os -s -ffast-math -Wno-nonnull -Wno-nonnull-compare -fno-builtin -Wno-larger-than -Wno-stack-usage -Wdisabled-optimization
TARGET=bf.c
BIN=bf

all:
	@$(CC) $(FLAGS) $(TARGET) -o $(BIN)

clean:
	@rm $(BIN)
