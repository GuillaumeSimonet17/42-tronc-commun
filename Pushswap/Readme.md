![Screenshot from 2023-08-21 10-52-13](https://github.com/GuillaumeSimonet17/42-tronc-commun/assets/84441663/cd03cb2c-cc33-4b3b-83eb-d4d79cdd79ea)

Project to be launched on MacOS

Push_swap is a 42 school algorithm project where we must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

**RULES**

The game consists of 2 stacks named a and b. At the start: ◦ a contains an arbitrary number of positive or negative integers, without duplicates. ◦ b is empty

The aim of the game is to sort in ascending order.

To do this, the following operations are available:

sa :swap a - inverts the first 2 elements at the top of stack a. Does nothing if there is only one or none.
sb :swap b - swaps the first 2 elements at the top of stack b. Does nothing if there is only one or none.
ss :sa and sb at the same time
pa :push a - takes the first element at the top of b and places it on a. Does nothing if b is empty
pb :push b - takes the first element on top of a and sets it to b. Does nothing if a is empty
ra :rotate a - shifts all elements in stack a upwards by one position. The first element becomes the last
rb :rotate b - moves all elements in stack b up one position. The first element becomes the last
rr :ra and rb at the same time
rra :reverse rotate a - shifts all elements in stack a down one position. Last element becomes first
rrb :reverse rotate b - shifts all elements in stack b down one position. Last element becomes first
rrr :rra and rrb at the same time.

**EXECUTION**

$>ARG="4 67 3 87 23"; ./push_swap $ARG
