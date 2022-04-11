# First compile the c files into object files in any order, doesn't matter
echo "Begin search prog"
rm *.o
rm *.out
gcc -c -m64 -std=c17 -o outputs.o output_integers.c
gcc -c -m64 -std=c17 -o copy.o copyfile.c
gcc -c -m64 -std=c17 -o sea.o search.c

# Now call the linker to link these obejct files into an executable file
gcc -m64 -std=c17 -o search.out sea.o copy.o outputs.o

# Now execute the executable
./search.out
echo "All Done."
