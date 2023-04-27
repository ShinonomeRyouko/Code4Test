Code4Test is a personal tiny project aimed to solve leetcode problems with [GoogleTest](https://github.com/google/googletest.git) integrated.

# Building
### Build for POSIX
```bash
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DSANITIZER_CHECK=false .. && make -j`nproc`
cd test && ctest
```
# How to use
Modify `SolutionNames.txt` in top directory to add other solutions. `gen.py` will create corresponding files in folders(include, src, test) automatically. Modify the created files to complete solution and test cases.
If you're using vscode, install plugin [C++ TestMate](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter) and [Test Explorer UI](https://marketplace.visualstudio.com/items?itemName=hbenl.vscode-test-explorer) to enhance gtest.