## *This project has been created as part of the 42 curriculum by sohuikim.* <br /> <br />


## **Description**
+ ### Overview
  #### The goal of this project is to implement a program that tackes an input file, connects two commands through a pipe, and writes the final result to an output file. <br /> <br />
 

+ ### Objectives  
  #### Through this project, you will learn how pipes work and how to implement them. <bar>
  #### You will learn how to construct a connected data stramd between commands by creating new processes with `fork()` and redirecting standard input and output using `pipe()` and `dup2()`. <br /> <br />


## **Instructions**
+ ### Comilaition
  #### Run 'make' to compile the program and generate the 'pipex' exectable. 
	``` c
	make
	```

+ ### Usage
  #### Run the executable with four arguments in the following order: `infile`, `cmd1`, `cmd2`, and `outfile`.
  	``` c
	./pipex infile.txt "cmd1" "cmd2" outfile.txt
	```
  	``` c
	./pipex in.txt "grep a" "wc -l" out.txt
	```
  ---
<br /><br />


## Useful Concepts

#### The following key functions are used in this project:

  #### **`pipe()`** : 
  #### Creates a unidirectional communication channel and returns two file descriptors: one for reading `(fd[0])` and one for writing `(fd[1])`. <br/> It allows data to flow between processes. <br/><br/>

  **`dup2()`** : 
  #### A system call that duplicates a file descriptor. <br/> If the target descriptor is already open, it is closed and replaced with a duplicate of the original descriptor. <br/> Both descriptors refer to the same underlying kernel object. <br/><br/>
  
  **`fork()`** : 
  #### Create a new process by duplicating the calling process. <br/> After the call, execution continues in both the parent and the child porcess. <br/><br/>

  **`waitpid()`** : 
  #### Suspends execution of the calling process until the specified child process changes state. <br/><br/>

  **`execve()`**: 
  #### Replaces the current process image with a program specified by the given path. <br/> If successufl, if does not return. <br/><br/>

  **`errno`** : 
  #### A global variable set by system calls and some library functions when an error occurs. <br/> It indicates the type of erro encountered. <br/><br/>


## **Resources** <bar>
+ ### References <bar>
  #### - Permitted functions and their concepts:
  (man page) <br/>
  (https://www.geeksforgeeks.org/) <br/>
  (https://www.tutorialspoint.com/) <br/>
  (https://stackoverflow.com/) <br/>
  
   <br/><br/>


+ ### AI Usage  
  #### - AI was used to verify my understanding of concepts learned through blogs and documentation, as wells as related examples. <bar> 
  #### - AI was used to better understand the stream-based input and output mechanisms of data flow through pipes. <bar> 
  #### - AI was also to interpret English documentation, compiler erros, and memory leak reports, as wells as to choose appropriate fuction and variable names. <bar>