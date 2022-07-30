# Queue Implementation Using Arrays

## Data members 
- int cnt = count/size of current queue
- pointer front,rear
- int n = max number of elements allowed

Initially, front and rear pointer will be pointing to 0th position. 

We will use circular array property here. 


## Member Functions : 


### push(x)
- if(cnt==n) return -1 cout(Queue is full)
- if(cnt<n) arr[rear%n] = x;rear++
- cnt++

### pop()
- if(cnt==0) return -1;
- arr[front%n]=-1(dummy number); front++;
- cnt--

### front() 
- if(cnt==0) return -1;
- arr[front%n]

### print()
```
for(int i=front;i<rear;i++) 
print(arr[i%n])
```


  