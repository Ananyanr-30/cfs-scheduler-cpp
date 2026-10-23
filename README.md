# CFS Scheduler Simulation

## Overview
A C++ project that simulates CPU process scheduling using
virtual runtime and process weights, inspired by the Linux
Completely Fair Scheduler (CFS).

## Technologies Used
- C++
- Ubuntu Linux (WSL)
- CMake
- Git

## Features
- Simulates multiple processes
- Selects processes based on virtual runtime
- Tracks process completion times
- Calculates turnaround time and waiting time

## Build Instructions

```bash
cmake -S . -B build
cmake --build build
./build/scheduler
```

## Learning Outcomes
- CPU scheduling concepts
- C++ structures and vectors
- Linux terminal commands
- CMake-based builds

## Note
This is an educational simulation, not an implementation
of the actual Linux kernel scheduler.
v
