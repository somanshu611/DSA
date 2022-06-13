
// Brute Force Solution.
// With power set bit manipulation technique, our TC = O((2^N)*N).
// 2^N for all possibilites and multiplication with 'N' for checking every bit. 
// We can optimise further and avoid this extra O(N)

// Optimal Approach : 
// This is simple pick not pick Binary choice recursive tree structure. 
// At the end, i.e. on leat nodes, we'll get our sums, and then we inset those sums
// into array and sort is later. The size of the array would be 2^n.
// So TC = O( (2*N) + (2^N)*log(2^N) ) = O((2^N)*N)