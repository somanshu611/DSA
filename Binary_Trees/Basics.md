## Traversals : 

1. BFS
   - Level Order Traversal(Iterative only,use of queue)
2. DFS
   - PreOrder(DLR)
   - InOrder(LDR)
   - PostOrder(LRD)

## DFS : 
Recursive approaches are intuitive for dfs, iterative ones are not. 
Use stack for all of them.

1. PreOrder(Most Easy) : First, push the data of the current node to the answer, and pop this current node. Then, push the right and left node to the stack.
2. InOrder : For Inorder, we require a extra node to traverse the tree.
3. PostOrder : There are two ways to do this : 
   1. Using 2 Stack : This is basically reverse engineering of recursive approach.