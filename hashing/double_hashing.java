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
	public int HashFunc1(int key) {
		return key % ArraySize; // A simple modulo hash function
	}
	public int HashFunc2(int key) {
		return 7 - key % 7;
	}
	public void insert(DataItem item) {
		int HashVal = HashFunc1(item.GetKey());
		int StepVal = HashFunc2(item.GetKey());
		while(HashArray[HashVal] != null && 
			 HashArray[HashVal].GetKey() != -1)
			HashVal = (HashVal + StepVal) % ArraySize; // linear probing
		HashArray[HashVal] = item;
	}
	public DataItem find(int key) {
		int HashVal = HashFunc1(key);
		int StepVal = HashFunc2(key);
		while(HashArray[HashVal] != null) {
			if(HashArray[HashVal].GetKey() == key)
				return HashArray[HashVal];
			HashVal = (HashVal + StepVal) % ArraySize;
		}
		return null;
	}
	public void delete(int key) {
		int HashVal = HashFunc1(key);
		int StepVal = HashFunc2(key);
		while(HashArray[HashVal] != null) {
			if(HashArray[HashVal].GetKey() == key) {
				HashArray[HashVal] = NonItem;
				return;
			}
			HashVal = (HashVal + StepVal) % ArraySize;
		}
	}
}
