import java.util.*;

public class catalan {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		int[] dp = new int[num + 1];
		Arrays.fill(dp, 0);
		dp[0] = dp[1] = 1;
		for(int i = 2; i <= num; ++i) {
			for(int j = 0; j < i; ++j) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		System.out.println(dp[num]);
	}
};
