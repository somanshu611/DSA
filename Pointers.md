queue<*TreeNode> q -> this is wrong

queue<TreeNode*> q-> this is right
q.push(root) -> this is right
q.push(*root) -> wrong 

> So if datatype is not inbuilt of any stl data structure, then this should be followed.