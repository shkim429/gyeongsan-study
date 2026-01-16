##### *This project has been created as part of the 42 curriculum by sohuikim.*

---
## **Description**
+ ### Overview
  ##### The goal of this project is to sort the input values in stack A in ascending order using stacks A and B with the fewest possible push_swap instructions.
 
+ ### Objectives  
  ##### Trough this project, you will learn how sorting algorithms work and how they operate step by step. <bar>
  ##### You will also implement them in the most efficient way possible to better understand time complexity. 

## **Instructions**
+ ### Comilaition
  ##### Run 'make' to compile the program and generate the 'push_swap' exectable. 
	``` c
	make
	``` 

+ ### Usage
  ##### Run the executable with a list of integers as arguments.
  	``` c
	./push_swap "1 2 3"
	```
	``` c
	./push_swap "10 -21456" "+33" -1
	```

## Algorithms

##### The following algorithm was used to solve the problem given in this project: <bar>

+ <span style="background-color:#C7C7C7"> **Radix sort <span>**
  ##### The insertion sort is a sorting algroithm that processes elements sequentially from the beginning of the array inserts each element into its correct position. <bar>
  ##### Typically, the second element is chosen as the key and is compared with the previous elements to determine its proper position. <bar>
+ <span style="background-color:#C7C7C7"> **Insertion sort <span>**
  ##### The binary radix sort is a sorting algorithm that orders elements by their digits. <bar>
  ##### It uses buckets for each digit and distributes the elements starting from the least significant digit. <bar>
  ##### Afterward, the elements are gathered from the buckets in order to form the sorted result.

## **Resources** <bar>
+ ### References <bar>
  ##### - Sorting algorithms and time complexity:
  (https://yabmoons.tistory.com/250)

  ##### - Insertion sort: concept and mechanism:
  (https://roytravel.tistory.com/328) <bar>

  ##### - Radix sort: concept and mechanism: <bar>
  (https://babe-dev.tistory.com/44) <bar>
  (https://nomad-programmer.tistory.com/390) <bar>
  (https://www.interviewcake.com/concept/python/radix-sort) <bar>

  ##### - Convertin sorting logic into stack operations

+ ### AI Usage  
  ##### - AI was used to verify my understanding of sorting algroitms studied through blogs and documendtation. <bar> 
  ##### - AI was also used to interpret English documentation, compiler erros, and choose appropriate function and variable names. <bar>
  ##### - AI was used to understand the difference between pointer variables and non-pointer variables when declaring variables and passing arguments between functions, such as using structure variables versus structure pointers. <bar>