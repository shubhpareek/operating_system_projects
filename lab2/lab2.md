# Lab 2: Makefiles (deadline: 05-Oct 2022 23:59 hrs)

## Instructions

1.  All the source files and header files have to be present under the
    directory `lab2` (possibly under other sub-directories that are inside
    `lab2`)

2.  Commit your progress often.

3.  Do not commit temporary files and folders into the repo. (Do a `make clean`
    before you commit your changes into the repo)

4.  The `makefile` should be part of the repo. Avoid using absolute paths in
    the `makefile` because that will affect portability (I will not be able to
    pull your submission and run `make` on it).

5.  The instructor/TA will pull the repo, and issue to the following commands
    to build, run, and grade your submission. Therefore, make sure that your
    submission is in order. `test.in` has all the input values (scalar or
    matrix), and `test.out` should have all the matrices that are output at
    the end of the execution. Create multiple test inputs and expected outputs
    to create a test-suite for your code. Command-line arguments can indicate
    any operation listed in question below.

```
$ cd lab2
$ make
$ make tests
$ make clean
```

## Format of matrix (input and output)

The input and output files are considered to be legal if it follows the
following rules:

1.  A line that starts with # is a comment. The character '#' should be the first
    character in the line, and a comment has to be a line by itself.

2.  A single value in a line is a scalar.

3.  Two values in a line indicates the dimensions of the matrix. Such a line
    should be followed by the content/elements of the matrix.

4.  Each row of the matrix is in one line. Therefore, a M &times; N matrix will
    span over M+1 lines: one line for the dimensions and then one line for each
    of the M rows.

5.  If there are more than one matrix in a file, then the matrices are
    concatenated (or appended) one after the other.

6.  Empty lines (and lines with only whitespaces) are ignored.

7.  Two sample files (sample1.in and sample2.in) illustrates the format better.


## Question

1.  **[30 marks]** Write a C/C++ program to do the following:
    -   Read an input file that contains one (or more) inputs (scalars/matrices
        given in the format above). If the input files have more than two inputs
        (scalars/matrices), use only the first one (or two) values (depending in
        the number of operands required) and ignore the rest of the input values.
    
    -   Implement the following functions. You can use external libraries if
        required. Some useful libraries are the Standard Template Library (STL),
        and [Getopt](https://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/Getopt.html). 
        -   Scalar Operations
            -   addition (add a scalar value to all elements of a matrix)
                [COMMAND-LINE OPTION: -a]
            
            -   subtraction (subtract a scalar value to all elements of a matrix)
                [COMMAND-LINE OPTION: -s]
            
            -   multiplication (multiply all elements of a matrix with a scalar)
                [COMMAND-LINE OPTION: -m]
            
            -   2. division (divide all elements of a matrix with a scalar)
                [COMMAND-LINE OPTION: -d]
        
        -   Matrix Operations
            -   add two matrices [COMMAND-LINE OPTION: -A]
            
            -   subtract one matrix from the other matrix [COMMAND-LINE OPTION: -S]
            
            -   multiply two matrices [COMMAND-LINE OPTION: -M]
            
            -   transpose a matrix [COMMAND-LINE OPTION: -T]
            
            -   compute the determinant of a matrix [COMMAND-LINE OPTION: -X]
    
    -   Write the resultant matrix (or scalar value) in the format
        mentioned above. You may create other output files such as log files, temp
        files, etc as you deem fit in the same directory. However, the output
        should not be cluttered with error and debug prints.
    
    -   Spread the code across multiple files.
    
    -   Implement a logging mechanism such that debug prints (or
        messages) are directed to a separate log file. Note that the log messages
        should not clutter the output. There are several simple loggers available
        on the internet such as [this](https://cppcodetips.wordpress.com/2014/01/02/a-simple-logger-class-in-c/), [this](https://www.drdobbs.com/cpp/logging-in-c/201804215), or [this](https://bitbucket.org/volkanozyilmaz/logcpp/src/master/main.cpp). NOTE: there are more powerful
        loggers but using them will not satisfy the submission instructions.
    
    -   Handle errors gracefully. The output should continue to be in
        the format mentioned above even in case of an error. It is fine to not
        print any output messages if the error is logged in a log file. Follow
        [this FAQ](https://isocpp.org/wiki/faq/exceptions) to help you achieve this. Pay special attention to the fifth
        question.

2.  **[10 marks]** Write at least four test cases for your code. You have to create a
    file with the test input and another file with expected output. The input and
    output formats were described in lab2. In addition to the input and output
    formats, you will need a mechanism to compare the output produced with the
    expected output. You can the command `diff` to do the comparison.

3.  **[20 marks]** Create separate folders and organize your code (in the
    following manner):
    -   `src/` - This folder should contain all the source files (.cpp or .cc)
    
    -   `include/` - This folder should contain all the header files (.h or .hpp)
    
    -   `lib/` - This folder should contain all the libraries against which you code
        will link. This should also contain the libraries that you will generate
        from your code (as part of this lab).
    
    -   `bin/` - The final executable should be in this folder
    
    -   `tests/` - This folder should contain all the input files and expected output
        files for all the test cases that you have written to test your code.
    
    -   `build/` - This is optional. You can have all the temporarily files that are
        created when compiling your code (such as object files) in this folder.

4.  **[40 marks]** Setup a build system for your application using the make utility
    with the following targets. Use Makefile variables, text-substitutions,
    pattern-matching, implicit rules, etc as much as possible. **Do not embed
    absolute paths in your makefile.** The folders have to be created as part of
    the makefile (`make` or `make build`) itself. Do not expect that the folder
    structure mention above is created beforehand (or is to be manually created).
    -   `build` - compile your code to produce an executable (name of the executable
        does not matter because we will never call the executable directly from the
        terminal) in the appropriate folder (`bin/` in our case). This should be
        the default target (just issuing \`make\` without any targets should build
        the executable).
    
    -   `libs` - create two libraries: (i) a static library that contains only the
        scalar operations in it, and (ii) a dynamically linked library that
        contains only the matrix operations in the appropriate folder (`lib/` in
        our case).
    
    -   `run` - runs the executable created using the build target. It assumes that
        the input and output files are `run.in` and `run.out` (which are located in
        the present working directory).
    
    -   `tests` - runs all test cases on your application
    
    -   `test1` / `test2` / `test3` / &#x2026; - runs only test case 1/2/3/&#x2026; on your
        application
    
    -   `clean` - deletes the executable, the temporary files, and any files that
        are generated such as execution logs, output files etc. After running `make
             clean`, the folder should have only the makefile, source files, header
        files, and the test cases (including their corresponding expected outputs).
        Should also delete the containing folders such as `build`.

