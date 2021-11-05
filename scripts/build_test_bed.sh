# Simple script to automate compilation and execution
LIBS=$1
echo "INFO: This script assumes that you have cloned the repository in your home directory."
echo "Compiling..."

# Check if a directory does not exist
if [ ! -d "~/test_bed/build" ] 
then
    echo "Creating build folder..." 
    mkdir ~/test_bed/build
fi

cc -o ~/test_bed/build/test_bed ~/test_bed/src/test_bed.c $LIBS
echo "Compilation complete. Running executable... "
echo "======================================================="
~/test_bed/build/test_bed