#include <iostream>

constexpr int MAXN = 1024;
int tree[MAXN];
int lazy[MAXN];


void updateRangeUtil(int num, int start, int end, int left, int right, int pos, int diff) {
	if(lazy[pos]) {
		tree[pos] += (right - left + 1) * lazy[pos];
		if(left != right) {
			int lchild = pos * 2 + 1, rchild = lchild + 1;
			lazy[lchild] += lazy[pos];
			lazy[rchild] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(left >= start && right <= end) {
		tree[pos] += (right - left + 1) * diff;
		if(left != right) {
			lazy[2 * pos + 1] += diff;
			lazy[2 * pos + 2] += diff;
		}
		return;
	}
	if(left > end || right < start)
		return;
	int mid = left + (right - left) / 2;
	int lchild = pos * 2 + 1, rchild = lchild + 1;
	updateRangeUtil(num, start, end, left, mid, lchild, diff);
	updateRangeUtil(num, start, end, mid + 1, right, rchild, diff);
	tree[pos] = tree[lchild] + tree[rchild];
}

void updateRange(int num, int start, int end, int diff) {
	updateRangeUtil(num, start, end, 0, num - 1, 0, diff);
}

int getSumUtil(int num, int start, int end, int left, int right, int pos) {
	if(lazy[pos]) {
		tree[pos] += (right - left + 1) * lazy[pos];
		if(left != right) {
			int lchild = pos * 2 + 1, rchild = lchild + 1;
			lazy[lchild] += lazy[pos];
			lazy[rchild] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(left >= start && right <= end)
		return tree[pos];
	if(left > end || right < start)
		return 0;
	int mid = left + (right - left) / 2;
	return getSumUtil(num, start, end, left, mid, 2 * pos + 1)
		+ getSumUtil(num, start, end, mid + 1, right, 2 * pos + 2);
}
int getSum(int num, int start, int end) {
	return getSumUtil(num, start, end, 0, num - 1, 0);
}




void constructSTUtil(int arr[], int ss, int se, int si) {
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;
 
    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
 
    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
 
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}
 
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
void constructST(int arr[], int n) {
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, 0);
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    constructST(arr, n);
 
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
           getSum(n, 0, 8));
 
    // Add 10 to all nodes at indexes from 1 to 5.
    updateRange(n, 3, 6, 5);
 
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
            getSum(n, 0, 8));
 
    return 0;
}
