# Heap
- Heap is a Data structure based on CBT.
- Heap is a CBT(Complete Binary Tree) which comes with a Heap Order Priority(Max Heap,Min Heap). 

- Max Heap -> Root is greater is than it's children.
- Min Heap -> Children are smallter than the root node. 

- **Complete Binary Tree** : 
  - Every level is completely filled except the last level.
  - Nodes always add from the left.  

# Heapify Algorithm 
- *Imp* : Leaf nodes lie from (n/2+1)th index to nth index. 
- So we have to process from 1 to (n/2)th position.
- Start from n/2th position. 
- **If Heapify function is called on ith index, then it will convert everything from ith index to nth index to heap by taking element at ith index to it's correct position.**
- ## Build Heap(using Heapify algo) has O(n) TC 
  - https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/ (Imp but still haven't completely understood this )
  - https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiquImFkpP4AhVAmlYBHezYDzIQFnoECAUQAw&url=https%3A%2F%2Fstackoverflow.com%2Fquestions%2F9755721%2Fhow-can-building-a-heap-be-on-time-complexity%23%3A~%3Atext%3DAt%2520the%25203rd%2520level%2520from%2Care%2520getting%2520O(n)%2520.&usg=AOvVaw0xLaRg04A93Pzny84oPHYl 

# Heap Sort 
- TC = O(NlogN)

# Priority Queue
- stl data structure
- default max heap
- For Min Heap :
```
Syntax : 
priority_queue<int,greater<int>> pq;
```
