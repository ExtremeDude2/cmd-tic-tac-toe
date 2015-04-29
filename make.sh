src="."
obj="$src"

FLAGS_x86="\
    -masm=intel \
    -msse2 \
    -mstackrealign"

echo Compiling C source code...
cc -S -o $obj/tic_tac_toe.asm $src/tic_tac_toe.c -O3 -Wall -pedantic -ansi -std=c89 $FLAGS_x86

echo Assembling compiled sources...
as -o $obj/tic_tac_toe.o $obj/tic_tac_toe.asm

echo Linking assembled object files...
gcc -o $obj/tic_tac_toe $obj/tic_tac_toe.o -s
