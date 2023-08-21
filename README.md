# Array transformer

A utility program for parsing an input file with numbers. The data is represented as an array which contains three other arrays of arbitrary size.
Program is working in a loop until the user won't type an exit command. If a wrong command or typo was detected the program continue looping until user won't exit by itself.

## Commands
There are four main procedures that transform input arrays:
  - sort (ASC).
  - intersection of two largest (if input arrays have equal sizes then first two found will be used).
  - intersection of all.
  - create an array sorted in a reversed order that contains a unique elements of each of three input arrays.

All transformations are printed in command buffer.

## List of input commands
  - "--exit"
  - "--sort"
  - "--intersect-all"
  - "-intersect-two-largest"
  - "--diff"
