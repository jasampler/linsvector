# linsvector - Simple fixed-size array of strings in C

A simple data structure with fixed-memory for storing text lines in an array:

     _ _ _ _ __ __
    |*|5|3|*|15|10|
     |     |
     |     |buf   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
     |     '---->|a|a|a|a|0|b|b|0|c|0|_|_|_|_|_|
     |arr         ^         ^     ^
     v            |         |     |
    |*|-----------'         |     |
    |*|---------------------'     |
    |*|---------------------------'
    |_|
    |_|

The struct must be first initialized with:

* An array of pointers to char (arr).
* The maximum of pointers that the array can contain (arrmax).
* The number of pointers cointained in the array (arrlng), initially 0.
* An array of chars as a buffer for storing the text (buf).
* The maximum of chars that the buffer can contain (bufmax).
* The number of chars cointained in the buffer (buflng), initially 0.

You can use the function linsvector_init() to do that.

Then, the function linsvector_insert() allows you to insert
text lines ensuring that the limits will not be surpassed.

And the function linsvector_reduce() allows you to reduce
the number of text lines stored to a given number.
