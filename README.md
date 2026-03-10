# PGO
CSCI 45: Profile Guided Optimization Project
=======================================================================

Part 1: The Data Scientist

Your job is to do data science and discover interesting things from a data file you download.
This is the link to the data file we will be using: https://www.kaggle.com/datasets/mathurinache/sleep-dataset?resource=download](https://www.kaggle.com/datasets/uom190346a/sleep-health-and-lifestyle-dataset

Tasks:

Find our data file through Kaggle

Import CSV file into C++ program

Do something fun or interesting with the data that will take 10 seconds to 1 minute to run
a. Needs to have multiple nested branches
b. Needs to have multiple loops

Update the README.md for this project and describe what we are all doing

Source code must have multiple .cc and .h files with function calls between the different files

Make a Makefile that will handle all the different compilation options (Gcov, PGO generate, PGO use, LTO, -O3, etc)
a. Should have a make clean option that will erase all .gcda, .gcno, and .gcov files
b. Incorporate the simple compilation examples shown later in the assignment
c. Partners may edit and revise the Makefile

Write up things you find interesting about your data analysis and send it to the Instrumenter for their report

=======================================================================

Part 2: The Tester

Get gcov to work:
a. Compile the code with: \g++ -O0 --coverage
b. Run a.out multiple times
c. Generate a coverage file via: gcov -o a-main main.cc

Make tests:
a. Make several small demo .csv files
b. Determine expected output for each
c. Run the code (with gcov coverage on) and verify all test cases pass
d. If the program takes input, write tests for good, bad, and edge cases

Validate that you have 100 percent coverage for every branch and loop in the code using Gcov.

Generate an HTML version of your Gcov report and attach it to the Instrumenter’s report.

Report any bugs to the Data Scientist.

=======================================================================

Part 3: The Instrumenter
This person will submit the report on canvas dhowing how long the program will take to run with all the optimizations.

Collect timing data for each part of the code using the following optimization configurations:
a. Optimizer off, ASAN and UBSAN on
b. Optimizer off, ASAN and UBSAN off
c. O3 Optimizer on, ASAN and UBSAN on
d. O3 Optimizer on, ASAN and UBSAN off
d2. Ofast Optimizer on, ASAN and UBSAN off (if using floats)
e. PGO + O3 on, ASAN and UBSAN off
f. PGO + LTO + O3 on, ASAN and UBSAN off
g. Likely + Unlikely + PGO + LTO + O3 on, ASAN and UBSAN off

Collect end‑to‑end timing by running "time a.out" and report results in human‑readable format.

For each optimization option, report how long the most important loop takes to run (using clock() or chrono).

For important branches inside the loop, try using [[likely]] or [[unlikely]] and measure any performance changes. This is optimization option g.

=======================================================================

Part 4: The Pogo Stick

This person handles PGO, perfing, and LTO.

PGO:

Compile the code with: g++ -O3 -std=c++26 -fprofile-generate main.cc

Run the code extensively and repeatedly, including all tests by the Tester. This will save profiling data to disk.

Recompile with: g++ -O3 -std=c++26 -fprofile-use main.cc This will use the profile data to optimize your code.

Hand data to Instrumenter to time (Optimization option E)

Perfing:

Compile the code with: g++ -O3 -g -fno-omit-frame-pointer -std=c++26 main.cc

Run: perf record -g a.out

Generate report as a text file: perf report --stdio > perf_report.txt

Review perf_report.txt to see call relationships and percentage of time spent in each function

Write up interesting findings and send them to the Instrumenter for the report

LTO:

Add -flto to your compile flags

Make clean

Make

Rerun timings and give results to the Instrumenter (Optimization options F and G)

=======================================================================

