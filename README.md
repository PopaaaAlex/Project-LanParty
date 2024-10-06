## Project Name: LAN Party

## Running the Program
./checker.sh

## Description:
This program reads team data from the input files and simulates a tournament from a LAN Party.

## Task Solutions:
### Task [1]:
The data about teams is read from the input file in main.c, and all the information is stored in a singly linked list, with elements added at the beginning of the list.

### Task [2]:
Teams with the lowest scores are iteratively eliminated until the number of teams reaches a power of 2. If two teams have the same minimum score, the first team found in the list is eliminated.

### Task [3]:
A queue is created with the remaining teams, and the matches begin. To manage the match results, two stacks are used: one for winning teams and one for losing teams, which are cleared at the end of each round. If two teams have the same score, the team that was entered first is considered the winner. Each team that wins a match increases its score. Once only 8 teams remain, a separate list is created for them.

### Task [4]:
Once only the 8 teams remain, they are used to create a binary search tree (BST). If two teams have the same score, their names are compared to decide the order in the tree.

### Task [5]:
From the previously created tree, it is transformed into an AVL tree (balanced tree), and the elements on the second level of the tree are displayed.
