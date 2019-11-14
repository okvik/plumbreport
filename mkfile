</$objtype/mkfile

BIN=/$objtype/bin

TARGET=bin/eatplumb
OFILES=obj/eatplumb.$O

stub:VQ:
	mkdir -p bin obj
	mk all

all:V: $TARGET

install:V: all
	cp bin/* $BIN

uninstall:V:
	rm -f $BIN/$TARGET
	rm -f $BIN/`{cd bin; ls}

clean:V:
	rm -f $TARGET obj/*

$TARGET: $OFILES
	$LD $LDFLAGS -o $target $prereq

obj/%.$O: %.c
	$CC $CFLAGS -o $target $stem.c
