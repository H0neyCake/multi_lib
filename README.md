# multi_lib
Extension contains time and logger for arma 3.

**Execution time: 0.863871 ms**

## Usage:

* "mllib" callExtension ""; // general information about extension

* "mllib" callExtension "time"; // shows the system time of the computer in the format ['_year','_month','_day','_hour','_minute','_second','_weekday','_yearday','_dst'];

* "mllib" callExtension "about"; 

* "mllib" callExtension ["logger", ["logenry", "logname", "logdir"]]
// Creates a log with the specified arguments. If you want to create a log to the root, leave the last argument blank.

## Compiling:
1. Put .bat or .sh file in folder with .cpp file.
2. Call this file thouhgt bash/terminal.
3. Profit.

*Also, its multi library, if you have some ideas what we can add, we wait you in Issues.*
