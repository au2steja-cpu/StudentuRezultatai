# Studentų Rezultatai

Studentų rezultatai is a C++ console application for managing student records, calculating final grades, and benchmarking data structures for performance tests. The project is written primarily in C++20 and targets Windows-based development with Visual Studio/MSBuild.

## Overview

This application allows you to:

- enter student data manually,
- generate student data automatically,
- calculate final grades from homework and exam results,
- sort students by name, surname, or final grade,
- compare performance of `std::vector` and `std::list` containers,
- export benchmark results to a report file.

The project is intended for educational use and demonstrates common student-record processing patterns as well as performance analysis of container selection.

## Features

- Manual student input and result calculation
- Randomized test data generation
- Sorting by:
  - name,
  - surname,
  - final grade
- Automatic performance benchmarking for large datasets
- Output of comparison tables to `rezultatai.md`
- Console-based menu-driven interface

## Project Structure

The repository contains the C++ source files for the application and a Visual Studio project configuration:

- `StudentuRezultatai.cpp`
- `main.cpp`
- `StudentuRezultatai.vcxproj`
- `StudentuRezultatai.slnx`
- supporting C++ headers and source files for logic, input/output, benchmarking, and data handling

## Requirements

- Windows
- Visual Studio 2022 or a compatible MSVC toolchain
- C++20 support
- Desktop development with C++ workload

## Build and Run

1. Open the solution file `StudentuRezultatai.slnx` in Visual Studio.
2. Restore the solution if prompted.
3. Build the project in Debug or Release mode.
4. Run the executable.

You can also run the program from the command line:

```bash
StudentuRezultatai.exe
```

Optional argument:

```bash
StudentuRezultatai.exe 10000000
```

This sets the maximum generated dataset size for benchmarking.

## Usage

When the program starts, it displays a menu:

- `1` - Manual input
- `2` - Container testing (`vector` vs `list`)
- `0` - Exit

### Manual input mode

In this mode, the user enters:

- student name,
- student surname,
- homework grades,
- exam grade,
- calculation of the final grade is done automatically.

### Benchmark mode

This mode generates test data for different dataset sizes and compares the runtime of:

- `std::vector<Studentas>`
- `std::list<Studentas>`

It then writes benchmark summary tables to a file named `rezultatai.md`.

## Example Workflow

1. Launch the application.
2. Choose option `2` for benchmark testing.
3. Select sorting criterion:
   - name,
   - surname,
   - final grade.
4. Confirm whether to regenerate files.
5. Wait for the benchmark to complete.
6. Review results in `rezultatai.md`.

## Notes

- The project uses UTF-8 output settings for Lithuanian text support.
- The application is designed as a learning-oriented project and is especially useful for demonstrating:
  - data processing,
  - algorithm performance,
  - comparison of standard library containers.

## Summary

This repository presents a compact but practical C++ student results management and benchmarking utility. It is suitable for academic assignments, performance comparisons, and understanding container behavior in real-world data processing scenarios.
