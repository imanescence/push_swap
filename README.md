# push_swap
## Sorting a stack with a C program

<p align="center">
  <img src="https://cdn.discuss.boardinfinity.com/original/2X/4/43e224323f50c0fe7ea34b4f126c53659d287e7f.png" alt="Stack of plates" width="300"/>
</p>

**Push_swap** is a sorting algorithm visualizer and optimizer built in C. The goal of the project is to **sort a stack of integers** (stack a) using a very limited set of stack operations (switch a, push b, rotate a, etc.), while minimizing the total number of moves. At the start, stack_a contains a list of unique integers, and stack_b is empty.

The challenge lies in the constrained nature of the allowed operations, which can **only manipulate the top or bottom of the stacks**. For example, you can only swap the first two elements (sa/sb), rotate the stack to move the top element to the bottom (ra/rb), or push elements from one stack to the other (pa/pb). 

To solve this, I implemented an adapted **Radix Sort algorithm using bit shifting**. By examining the binary representation of each number bit by bit (from the least significant to the most significant), I was able to group and sort the numbers efficiently using only the allowed stack operations. This method ensures good performance, especially for large input sizes.

Stacks are implemented using **integer arrays**, which simplifies the internal logic and improves performance during the sorting process.
