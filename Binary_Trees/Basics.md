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

1. PreOrder(Most Easy) : First, push the data of the current node, and pop this current node. Then, push the left and right nodes to the stack.
2. InOrder : 