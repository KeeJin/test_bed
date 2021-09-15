# simple script to automate compilation and execution
echo "Compiling..."
cc -o ~/test_bed/build/test_bed ~/test_bed/src/test_bed.c
echo "Compilation complete. Running executable... "
echo "======================================================="
~/test_bed/build/test_bed