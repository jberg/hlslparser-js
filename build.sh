#!/bin/bash
emcc src/Main.cpp hlslparser/src/*.cpp -o dist/hlslparser.js -s 'EXPORT_NAME="HLSLParser"' -s EXPORTED_FUNCTIONS="['_parseHLSL']" -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' -s NO_EXIT_RUNTIME=1 -s SINGLE_FILE=1 -s WASM=1 -s MODULARIZE=1 --bind -O3
