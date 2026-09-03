#724-pivot index problem

problem link :- https://leetcode.com/problems/find-pivot-index/

## What is the Problem?

We are given an integer array.

We need to find the pivot index where:

- Sum of all elements on the left = sum of all elements on the right.
- If the pivot is at index 0, the left sum is considered 0.
- If there is no such index, return -1.

## Example

Input:
[1, 7, 3, 6, 5, 6]

Output:
3

Because:

Left side = 1 + 7 + 3 = 11
Right side = 5 + 6 = 11

So index 3 is the pivot index.
## Approach 1 — Simple Logic

* I keep `leftsum` to store the sum of elements on the left side.
* For every index `i`, I calculate the right-side sum using another loop.
* The right-side loop starts from `i + 1` because the current element is not included in the right side.
* Then I compare `leftsum` and `rightsum`.
* If both are equal, I found the pivot index.
* If they are not equal, I add `arr[i]` to `leftsum` because after moving to the next index, the current element becomes part of the left side.

### Code

```c
// paste your Approach 1 code here
```

---

## Approach 2 — Optimized Logic

* Instead of calculating the right sum again for every index, I first calculate the **total sum** of the array.
* I keep this total in `rightsum`.
* For the current index, `rightsum - arr[i]` gives me the sum of the elements on the right.
* I compare `leftsum` with `rightsum - arr[i]`.
* If they are equal, I found the pivot index.
* If not, I move to the next index:

  * Add `arr[i]` to `leftsum`.
  * Subtract `arr[i]` from `rightsum`.
* This way, I don't need a nested loop.

### Code

```c
// paste your Approach 2 code here
```

### Complexity

Approach 1:

* Time: `O(n²)`
* Space: `O(1)`

Approach 2:

* Time: `O(n)`
* Space: `O(1)`

### What I Learned

My first approach worked, but it repeatedly calculated the right-side sum.

In the second approach, I calculated the total sum once and updated the left and right sums while moving through the array.

So I improved the time complexity from `O(n²)` to `O(n)`.



