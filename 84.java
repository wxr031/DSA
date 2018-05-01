class Solution {
	public int largestRectangleArea(int[] heights) {
		if(heights == null || heights.length == 0) {
			return 0;
		}
		int result = 0;
		Stack<Integer> stack = new Stack<>();
		for(int right = 0; right < heights.length; right++) {
			while(!stack.isEmpty() && heights[right] < heights[stack.peek()]) {
				int height = heights[stack.pop()];
				int left = (stack.isEmpty()) ? -1 : stack.peek();
				int area = (right - left - 1) * height;
				if(area > result) {
					result = area;
				}
			}
			stack.push(right);
		}
		while(!stack.isEmpty()) {
			int height = heights[stack.pop()];
			int left = (stack.isEmpty()) ? -1 : stack.peek();
			int area = (heights.length - left - 1) * height;
			if(area > result) {
				result = area;
			}
		}
		return result;
	}
}
