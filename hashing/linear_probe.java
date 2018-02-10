class DataItem {
	private int key;
	public DataItem(int KeyVal) {
		key = KeyVal;
	}
	public int GetKey() {
		return key;
	}
}
class HashTable {
	private DataItem[] HashArray;
	private int ArraySize;
	private DataItem NonItem;
	public HashTable(int size) {
		HashArray = new DataItem[size];
		ArraySize = size;
		NonItem = new DataItem(-1);
	}
	public void PrintTable() {
		System.out.println("Table:");
		for(int i = 0; i < ArraySize; i++) {
			if(HashArray[i].GetKey() == -1)
				System.out.print("** "); // use '**' to represent empty item
			else
				System.out.print(HashArray[i].GetKey());
		}
		System.out.println("");
	}
	public int HashFunc(int key) {
		return key % ArraySize; // A simple hash function using modulo
	}
	public void insert(DataItem item) {
		int HashVal = HashFunc(item.GetKey());
		while(HashArray[HashVal] != null && 
			 HashArray[HashVal].GetKey() != -1)
			HashVal = (HashVal + 1) % ArraySize; // linear probing
		HashArray[HashVal] = item;
	}
	public DataItem find(int key) {
		int HashVal = HashFunc(key);
		while(HashArray[HashVal] != null) {
			if(HashArray[HashVal].GetKey() == key)
				return HashArray[HashVal];
			HashVal = (HashVal + 1) % ArraySize;
		}
		return null;
	}
	public void delete(int key) {
		int HashVal = HashFunc(key);
		while(HashArray[HashVal] != null) {
			if(HashArray[HashVal].GetKey() == key) {
				HashArray[HashVal] = NonItem;
				return;
			}
			HashVal = (HashVal + 1) % ArraySize;
		}
	}
}
public HashTableApp {
	public static void main(String args[]) {
		DataItem item;
		HashTable table;
		Scanner scan = new Scanner(System.in);
		int size, num, val;
		size = scan.nextInt();
		num = scan.nextInt();
		table = new HashTable(size);
		for(int i = 0; i < num; i++) {
			val = nextInt();
			item = new DataItem(val);
			table.insert(item);
		}
		
	}
}
