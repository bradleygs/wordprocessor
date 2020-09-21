The program will read input and perform some changes, and generate output. The program reads lines of input and print out paragraphs. 


The line length for each output line may be specified as a command line argument. If n ocommand line argument for the line length is specified, the program should 
use a line length of 40. 

The number of spaces to indent each paragraph may be specified as a command lineargument. 
If no command line argument for indent is specified, the program should use an indent of 8.

Words in the output are separated by a single whitespace character.
Ex:
“Hello         world” should appear as “Hello world” in the output.


One or more consecutive empty or blank lines, or the end of file, should be interpreted as the end of a paragraph. 
Several consecutive empty or blank lines should cause a single empty line to be generated on output.

The output must be filled out to a length less than or equal to the line length. This may involve combining several lines of input into a single line of output.
Note that the length of the output line should not exceed the line length. The only exception tothis rule is if there is only a single word on the output line.


You are allowed to have multiple -LL and -IN flag arguments. If you do, the last one specified isused. So, for example, 
providing the command line arguments “-LL=5 -LL=20 -LL=100” results in a line length of 100.
