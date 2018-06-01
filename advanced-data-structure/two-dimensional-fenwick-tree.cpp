#include <iostream>
#include <vector>

using matrix_type = std::vector<std::vector<int>>;

void update(matrix_type &fenwick, int r, int c, int row, int col, int add) {
	for(int i = r; i <= row; i += i & (-i))
		for(int j = c; j <= col; j += j & (-j))
			fenwick[i][j] += add;
}

int get_sum(matrix_type &fenwick, int row, int col) {
	int sum = 0;
	for(int i = row; i > 0; i -= i & (-i)) {
		for(int j = col; j > 0; j -= j & (-j)) {
			sum += fenwick[i][j];
		}
	}
	return sum;
}

matrix_type build_fenwick_tree(matrix_type &matrix, int row, int col) {
	matrix_type fenwick(row+1, std::vector<int>(col+1));
	for(int r = 1; r <= row; r++)
		for(int c = 1; c <= col; c++)
			update(fenwick, r, c, row, col, matrix[r-1][c-1]);
	return fenwick;
}


int get_range_sum(matrix_type &fenwick, int row1, int col1, int row2, int col2) {
	return get_sum(fenwick, row2+1, col2+1)
		- get_sum(fenwick, row1, col2+1)
		- get_sum(fenwick, row2+1, col1)
		+ get_sum(fenwick, row1, col1);
}

int main() {
	int row, col;
	std::cin >> row >> col;
	matrix_type matrix(row, std::vector<int>(col));
	for(int r = 0; r < row; r++) {
		for(int c = 0; c < col; c++) {
			std::cin >> matrix[r][c];
		}
	}
	matrix_type fenwick = build_fenwick_tree(matrix, row, col);
	for(auto vec : fenwick) {
		for(int num : vec) {
			std::cout << num << " ";
		}
		std::cout << "\n";
	}
	int query;
	std::cin >> query;
	while(query--) {
		int cmd;
		std::cin >> cmd;
		switch(cmd) {
			case 0: {
				int row1, col1, row2, col2;
				std::cin >> row1 >> col1 >> row2 >> col2;
				std::cout << get_range_sum(fenwick, row1, col1, row2, col2) << std::endl;
				break;
			}
			case 1: {
				int r, c, add;
				std::cin >> r >> c >> add;
				update(fenwick, r, c, row, col, add);
				break;
			}
			default: {
				std::cerr << "Invalid Input" << std::endl;
				break;
			}
		}
	}
	return 0;
}
