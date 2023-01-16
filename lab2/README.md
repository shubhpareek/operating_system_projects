## Description of options
If you type ```make``` in terminal then the program will be compiled and the executable will be in bin directory .
You can do ```make run``` and type the input in run.in, the options will be as a comment (it has # in the beginning and is) in the first line of run.in .
You can also use the executable directly as ```bin/mat [-options] < [input_file] > [output_file]``` .
The program also takes multiple options as arguments for example
```
bin/mat -a -s -m -d -A -S -M -T -X
```
will also work given the input has 4 matrices of required size and 4 scalars, if there are less matrices or scalars then only those options will be done
which are possible.

## Description of logger
loggfile contains the control flow of the program along with time so, if at any time an error occours we can know where it occoured for debugging purpose.


