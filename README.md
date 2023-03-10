# 42-pipex
## Introduction
### mandatory part:
**run _`make`_**

The program behaves exactly the same as this shell command:

`$> < file1 cmd1 | cmd2 > file2`

The program will be executed as follows:

__`./pipex file1 cmd1 cmd2 file2`__

It takes 4 arguments:
+ file1 and file2 are file names.
+ cmd1 and cmd2 are shell commands with their parameters.

e.g:
`$> ./pipex infile "ls -l" "wc -l" outfile` should behave like: `< infile ls -l | wc -l > outfile`

### bonus part:
**run _`make bonus`_**

+ handles multiple pipes.

e.g:
__`$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`__ should behave like: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
+ supports « and » when the first parameter is "here_doc".

e.g:
__`$> ./pipex here_doc LIMITER cmd cmd1 file`__ should behave like: `cmd << LIMITER | cmd1 >> file`
## 

