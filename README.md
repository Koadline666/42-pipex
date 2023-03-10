# 42-pipex

This is a project for [42Heilbronn](https://www.42heilbronn.de/en/curriculum/) school`s curriculum.
The goal of the project is to implement a program that behaves lika a shell command that redirects input ad output using pipes.

## Description
### mandatory part:
**run _`make`_**

The program behaves exactly the same as this shell command:

`$> < file1 cmd1 | cmd2 > file2`

The program will be executed as follows:

__`./pipex file1 cmd1 cmd2 file2`__

It takes 4 arguments:
+ file1: the name of the input file
+ cmd1: the first shell command to be executed with its parameters
+ cmd2: the second shell command to be executed with its parameters
+ file2: the name of the output file

e.g:
`$> ./pipex infile "ls -l" "wc -l" outfile` should behave like: `< infile ls -l | wc -l > outfile`

### bonus part:
**run _`make bonus`_**

+ Handling multiple pipes:

 __`./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`__ should behave like `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`.
+ Supporting << and >> when the first parameter is "here_doc":

 __`./pipex here_doc LIMITER cmd cmd1 file`__ should behave like `cmd << LIMITER | cmd1 >> file`.


