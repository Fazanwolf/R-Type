#!/bin/bash

file=.clang-format
targets="BreakAfterAttributes BreakArrays BreakBeforeInlineASMColon InsertNewlineAtEOF IntegerLiteralSeparator RemoveSemicolonRequiresExpressionIndentation"

comment_clang_16()
{
  for target in ${targets[@]}; do
    sed -i "s/^${target}/#${target}/g" $file
  done
}

uncomment_clang_16()
{
  for target in ${targets[@]}; do
    sed -Ei "s/^#${target}/${target}/g" $file
  done
}

if [ $# -eq 1 ] && [ "$1" == "-w" ] || [ "$1" == "--windows" ]; then
  comment_clang_16
elif [ $# -eq 1 ] && [ "$1" == "-l" ] || [ "$1" == "--linux" ]; then
  uncomment_clang_16
else
  echo "Usage: $0 [-w/--windows|-l/--linux]"
fi