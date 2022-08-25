<h1 align= "center"> LET'S DO SOME SORTING :) </h1>

![enter image description here](https://raw.githubusercontent.com/ridaelfagrouch/push_swap_42/main/assets/push_swap.png)

Hi ! This project Iis about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed we have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

<h2 align="center">->>  FREE TO USE ANY ALGORITHM AS LONG AS IT DO THE REQUIRED <<-</h2>
---
### The given instructions ...
  
|instructions| Description |
|--|--|
| sa | swap first two elements of stack A |
|  sb|  swap first two elements of stack B |
|ss| sa and sb at the same time |
| pa |  pops the first elememt on B and puts it on top of A|
| pb |  pops the first elememt on A and puts it on top of B|
| ra |rotates stuck A up by one|
| rb | rotates stuck B up by one |
| rr |rotates both A and B up by one|
| rra | rotates stuck A down by one|
| rrb | rotates stuck B down by one
| rrr|rotates both A and B down by one|
| rrr | rotates both A and B down by one |
---
### How to compile it ? 

For **Mandatory** part :
	 
--> `make`

--> `./push_swap [set of random numbers]`

ex : 

    $>./push_swap 2 1 3 6 5 8`
    sa
    pb
    pb
    pb
    sa
    pa
    pa
    pa
-   You have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
-   The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
-   Instructions must be separaed by a ’\n’ and nothing else.
-   The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operation tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.
-   In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.

For **Bonus** part : 

--> `make bonus`

--> `./checker [set of random numbers]`

  ex :
	  
    $>./checker 3 2 1 0
    rra
    pb
    sa
    rra
    pa
    OK
    $>./checker 3 2 1 0
    sa
    rra
    pb
    KO
    $>./checker 3 2 one 0
    Error
-   You have to write a program named checker, which will get as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given checker stops and displays nothing.
-   Checker will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, checker will execute them on the stack received as an argument.
-   If after executing those instructions, stack a is actually sorted and b is empty, then checker must display "OK" followed by a ’\n’ on the standard output. In every other case, checker must display "KO" followed by a ’\n’ on the standard output.
-   In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction don’t exist and/or is incorrectly formatted.
#### U can find the project's subject here , for more details : [Push_swap subject](https://cdn.intra.42.fr/pdf/pdf/56146/en.subject.pdf)
#### PS : If you see any error to fix , please dont hesitate to repport it, and u find my project interesting star it. feel free !! `*_*`
