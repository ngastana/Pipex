# 🧩 Pipex

**Pipex** recreates the behavior of the Unix pipe (`|`) — that magical little symbol that lets you chain commands together.  
In other words, the program takes the output of one command and feeds it as input to another, just like the shell does.

---

## 🧠 Project Overview

You’ll be building a program that mimics this:

```bash
< infile cmd1 | cmd2 > outfile
```
and you’ll make it work like this: 
```bash
./pipex infile cmd1 cmd2 outfile
```
The program should: 
    Open infile for reading. 
    Execute cmd1 with infile as its input. 
    Pipe the output of cmd1 into cmd2. 
    Redirect the output of cmd2 into outfile. 
So it’s basically a mini version of how the shell handles redirections and pipes — minus all the nice error messages and tab completion. 

🧰 Example Compilation make This will produce the executable pipex. 
Run example:
```bash
./pipex infile "grep something" "wc -l" outfile
```
This is equivalent to:
```bash
< infile grep something | wc -l > outfile
```

⚙️ Allowed Functions 
You’ll mostly be living off the land with: open, close, read, write pipe, dup, dup2 fork, execve wait, waitpid access, perror, strerror malloc, free 

💥 Error Handling 
  If a file doesn’t exist → print an error and exit gracefully. 
  If a command is invalid → print “command not found”. 
  Everything must be free (without leaks).
