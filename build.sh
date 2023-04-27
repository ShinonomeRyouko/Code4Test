mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DSANITIZER_CHECK=false .. && make -j`nproc`
cd test && ctest