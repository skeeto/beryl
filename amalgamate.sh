#!/bin/sh
set -e
cat src/interpreter.h \
    src/io.h \
    src/lexer.h \
    src/libs/int_libs.h \
    src/libs/io_lib.h \
    src/libs/lib_utils.h \
    src/utils.h \
    src/interpreter.c \
    src/io.c \
    src/lexer.c \
    src/libs/common_lib.c \
    src/libs/core_lib.c \
    src/libs/datastructures_lib.c \
    src/libs/debug_lib.c \
    src/libs/io_lib.c \
    src/libs/math_lib.c \
    src/libs/modules_lib.c \
    src/libs/string_lib.c |
  sed -r 's@^(#include +".+)@/* \1 */@g'
