import java.util.*;

class Matrix {
	public static int minimumMultiplication(int[] array, int num) {
		int[][] dp = new int[num-1][num-1];
		for(int i = 0; i < num - 1; ++i) {
			Arrays.fill(dp[i], Integer.MAX_VALUE);
		}
		for(int i = 0; i < num - 1; ++i)
			dp[i][i] = 0;
		for(int i = 1; i < num - 1; ++i) {
			for(int j = 0; j < num - 1 - i; ++j) {
				for(int k = j; k < i+j; ++k) {
					dp[j][i+j] = Math.min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + 
							array[j] * array[k+1] * array[i+j+1]);
				}
			}
		}
		return dp[0][num - 2];
	}
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int test = scanner.nextInt();
		while(test-- > 0) {
			int num = scanner.nextInt();
			int[] array = new int[num];
			for(int i = 0; i < num; ++i) {
				array[i] = scanner.nextInt();
			}
			System.out.println(minimumMultiplication(array, num));
		}
	}
}
