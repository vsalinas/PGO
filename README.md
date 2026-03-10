# PGO
CSCI 45: Profile Guided Optimization Project

-------------------------------------------------------------------------------------------------------------------
Part 1: The Data Scientist

Your job is to do data science and discover interesting things from a data file you download.

This is the link to the data file we will be using: "https://www.kaggle.com/datasets/mathurinache/sleep-dataset?resource=download"

-Tasks:
  1.Find our data file through kaggle
  2. Import CSV file into C++ program
  3. do something fun/intersting with the data that will take 10 seconds to 1 minute to run
    a. Needs to have multiple nested branches
    b. Needs to have multuple loops
  4. Update the README.md for this project and describe what we are all doing.
  5. SOurce code must have multiple .cc and .h files with function calls between the different files.
  6. Make a Makefile that will handle all the different compilation options (Gcov, PGO generate, PGO use, LTO, -03, etc)
    a. Should have a make clean option that will erase all .gcda, .gcno, and .gcov files.
    b. Down below when there are examples of how to compile a simple program with just main.cc in it, you will need to incorporate those into the Makefile.
    c. Your partners can edit and revise the Makefile as well.
  7. Write up things you find interesting about your data analysis and send it to the Instrumenter for their report.
-------------------------------------------------------------------------------------------------------------------
Part 2: The Tester

1. Get gcov to work:
   a. Compile the code with: \g++ -O0 --coverage
   b. Run a.out a bunch of times
   c. Generate a coverage file via: gcov -o a-main main.cc
2. Make tests:
   a. Make several small demo .csv files
   b. Figure out what the output of the program should be for each one
   c. Run the code (with gcov coverage on) and verify all test cases are passed.
   d. If your code takes input, write input tests for those as well, both good, bad, and edge.
3. Validate that you have 100% coverage for every branch and loop in the code using Gcov. In other words, if you start with a clean Gcov slate and run all the tests, it should show every line of code getting exercised by your tests.
4. Generate an HTML version of your Gcov report and attach it in the report of the Instrumenter.
5. If you find bugs in the code, report them to the Data Scientist to fix.

-------------------------------------------------------------------------------------------------------------------
Part 3: The Instrumenter

1. Collect the timing data for each part of the code and write a report that will be submitted on Canvas showing how long the program takes to run with all the different options of:
   a. Optimizer off, ASAN and UBSAN on
   b. Optimizer off, ASAN and UBSAN off
   c. O3 Optimizer on, ASAN and UBSAN on
   d. O3 Optimizer on, ASAN and UBSAN off
     d2. Ofast Optimizer on, ASAN and UBSAN off (if you're using floats)
   e. PGO + O3 on, ASAN and UBSAN off
   f. PGO + LTO + O3 on, ASAN and UBSAN off
   g. Likely+Unlikely + PGO + LTO + O3 on, ASAN and UBSAN off
2. Collect end to end timing by running time a.out and parse the output of time and report it to Kereny in human readable format for each of these optimization options.
3. For each of these optimization options, report how long the most important loop in your code takes to run. You can either time the loop using the C way with clock() or the C++ way with chrono.
4. For any important branches inside of the for loop, try using the [[likely]] or [[unlikely]] tags and see if that affects the running time. This is optimization option G above.

-------------------------------------------------------------------------------------------------------------------
Part 4: The Pogo Stick

This person will do the profile guided optimization (PGO), perfing, and LTO

PGO:
1. Compile the code with \g++ -O3 -std=c++26 -fprofile-generate main.cc
2. Run the code extensively and repeatedly, including using all tests made by The Tester so you have full code coverage. This will save profiling data to disk.
3. Compile the code again this time with \g++ -O3 -std=c++26 -fprofile-use main.cc when you compile it with -fprofile-use, it will use the profile data to optimize your code.
4. Hand this to The Instrumenter to time (it is Optimization option E above)

Perfing:
1. Compile the code with: \g++ -O3 -g -fno-omit-frame-pointer -std=c++26 main.cc
2. Run the code with: perf record -g a.out and run through all the tests and such
3. Put the perf report into a text file with: perf report --stdio > perf_report.txt
4. View perf_report.txt and see which functions are calling which functions and what percentage of time is spent in each function.
5. Write up things you fing interesting about this and send it to the Instrumenter for their report.

LTO:
1. Add -flto to your compile flags
2. Make clean
3. Make
4. Rerun the timings and hand it to the Instrumenter (this is Optimization options F and G above)
