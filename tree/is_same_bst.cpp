bool seqExist(int[] array, int num, int &curr, int &check) {
	if(!root) {
		return false;
	}
	if(inorder(root->left))
		return true;
	
	if(check) {
		if(curr == num) {
			return true;
		}
		if(array[curr] != curr->data) {
			curr = 0;
			check = 0;
		}
	}
	else if(array[0] == curr->data) {
			check = 1;
			++curr;
		}
	}

	return inorder(root->right);
}

URL: https://ide.geeksforgeeks.org/WFZ2TqObbr
