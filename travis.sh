#!/bin/bash

set -euo pipefail

cppcheck -ibuild . --force --quiet --error-exitcode=1 --enable=warning,performance,portability --suppress=missingIncludeSystem
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DSANITIZER_CHECK=ON -DCODE_COVERAGE=ON .. && make -j $(nproc)
cd test && ctest -j $(nproc) --output-on-failure