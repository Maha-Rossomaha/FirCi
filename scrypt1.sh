#!/bin/bash
echo "ALL FLAGS COMPILATION"
gcc MaOp1.c FuOp1.c Tests1.c -O2 -Wall -Werror -pedantic-errors -Wno-pointer-sign -Wextra -std=gnu11 -ftrapv -fsanitize=undefined
echo "ALL FLAGS COMPILATION SUCCEEDED"
echo "-g FLAG COMPILATION"
gcc -g MaOp1.c FuOp1.c Tests1.c
echo "-g FLAG COMPILATION SUCCEEDED"
valgrind ./a.out
echo "--coverage FLAGS COMPILATION"
gcc -g MaOp1.c FuOp1.c Tests1.c --coverage
echo "--coverage FLAGS COMPILATION SUCCEEDED"
./a.out
gcov MaOp1.c FuOp1.c Tests1.c
lcov --capture --directory /home/maha/C+Programs --rc lcov_branch_coverage=1 --output-file coverage.info
genhtml coverage.info --branch-coverage
