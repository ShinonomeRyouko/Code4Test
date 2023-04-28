#!/bin/bash

set -euo pipefail

mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DSANITIZER_CHECK=OFF -DCODE_COVERAGE=OFF .. && make -j $(nproc)
cd test && ctest -j $(nproc) --output-on-failure