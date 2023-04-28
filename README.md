# Code4Test &middot; [![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/ShinonomeRyouko/Code4Test/blob/main/LICENSE) [![Build Status](https://app.travis-ci.com/ShinonomeRyouko/Code4Test.svg?branch=main)](https://app.travis-ci.com/ShinonomeRyouko/Code4Test) [![codecov](https://codecov.io/gh/ShinonomeRyouko/Code4Test/branch/main/graph/badge.svg?token=SMRDNEML4X)](https://codecov.io/gh/ShinonomeRyouko/Code4Test) 

Code4Test is a personal tiny project aimed to solve leetcode problems with [GoogleTest](https://github.com/google/googletest.git) integrated.

# Building
### Build for POSIX
```bash
bash ./build.sh
```
# How to use
Modify `SolutionNames.txt` in top directory to add other solutions. `gen.py` will create corresponding files in folders(include, src, test) automatically. Modify the created files to complete solution and test cases.
If you're using [Visual Studio Code](https://code.visualstudio.com/), install plugin [C++ TestMate](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter) and [Test Explorer UI](https://marketplace.visualstudio.com/items?itemName=hbenl.vscode-test-explorer) to enhance gtest.