import java.util.*;
public class subset_array {
	static boolean IsSubset(int[] arr1, int[] arr2, int len1, int len2) {
		HashSet<Integer> set = new HashSet<>();
		for(int i = 0; i < len1; i ++)
			if(!set.contains(arr1[i]))
				set.add(arr1[i]);
		for(int i = 0; i < len2; i ++)
			if(!set.contains(arr2[i]))
				return false;
		return true;
	}
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int len1 = scan.nextInt();
		int[] arr1 = new int[len1];
		for(int i = 0; i < len1; i ++)
			arr1[i] = scan.nextInt();
		int len2 = scan.nextInt();
		int[] arr2 = new int[len2];
		for(int i = 0; i < len2; i ++)
			arr2[i] = scan.nextInt();
		if(IsSubset(arr1, arr2, len1, len2))
			System.out.println("arr2 is a subset of arr1");
		else
			System.out.println("arr2 is not a subset of arr1");
	}
}
