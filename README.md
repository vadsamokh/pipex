# pipex

**A project of School 21.**

In this project i had to make a small program, that will be able to execute 2 commands one after another, with a pipe between them.

The program also handles redirections - it takes an infile for input (**<** redirection) and makes an output to another file (**>** redirection).

Installation:

```
$ git clone https://github.com/vadsamokh/pipex && cd pipex && make
```

Launch:

```
$ ./pipex file1 cmd1 cmd2 file2
```

It is equivalent to the following command:

```
$ < file1 cmd1 | cmd2 > file2
```
