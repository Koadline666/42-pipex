# 42-pipex
#### *Unix System Programming and Pipelines: A Pipex Project Overview*
This is a project for [42Heilbronn](https://www.42heilbronn.de/en/curriculum/) school's curriculum.

The goal of the project is to write a program that will implement the behavior of the shell `|` and redirections.

## Description
### mandatory part:
**run _`make`_**

The program behaves exactly the same as this shell command:

`$> < file1 cmd1 | cmd2 > file2`

The program will be executed as follows:

__`./pipex file1 cmd1 cmd2 file2`__

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

 __`./pipex here_doc LIMITER cmd cmd1 ... cmdn file`__ should behave like `cmd << LIMITER | cmd1 ... | cmdn >> file`.

## What i learned:
+ how to use __pipes__ to redirect input and output between multiple processes.
+ how to check for unclosed pipes using the __lsof command__.
+ how to use the fork() function to __create child processes__.
+ how to use the execve() function to __execute shell commands in child processes__.
+ how to use __file descriptors__, such as dup() and dup2(), to redirect input and output between processes.
+ how to __handle errors__ and __manage memory__ to avoid issues like memory leaks and unexpected program termination.
+ Bonus: Handling multiple pipes and supporting << and >> for "here_doc" input.

These concepts are fundamental to Unix system programming and pipelines, and are widely used in various applications, such as data processing and networking. 

