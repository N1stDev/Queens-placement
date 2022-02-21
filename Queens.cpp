#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n = 8;
int solutions = 0;

void print_desk(int** desk) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (desk[i][j] > 9) {
				cout << desk[i][j] << "  ";
			}
			else {
				cout << desk[i][j] << "   ";
			}
		}
		cout << endl;
	}
	cout << "\n\n\n\n";
}

void create_desk(int** desk) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			desk[i][j] = 0;
		}
	}
}

bool on_diag(int i, int j, int x, int y) {
	int x_tmp, y_tmp;
	x_tmp = x, y_tmp = y;
	while ((x_tmp < n) && (x_tmp >= 0) && (y_tmp < n) && (y_tmp >= 0)) {
		if ((x_tmp == i) && (y_tmp == j)) {
			return 1;
		}
		x_tmp--;
		y_tmp--;
	}
	x_tmp = x, y_tmp = y;
	while ((x_tmp < n) && (x_tmp >= 0) && (y_tmp < n) && (y_tmp >= 0)) {
		if ((x_tmp == i) && (y_tmp == j)) {
			return 1;
		}
		x_tmp--;
		y_tmp++;
	}
	x_tmp = x, y_tmp = y;
	while ((x_tmp < n) && (x_tmp >= 0) && (y_tmp < n) && (y_tmp >= 0)) {
		if ((x_tmp == i) && (y_tmp == j)) {
			return 1;
		}
		x_tmp++;
		y_tmp--;
	}
	x_tmp = x, y_tmp = y;
	while ((x_tmp < n) && (x_tmp >= 0) && (y_tmp < n) && (y_tmp >= 0)) {
		if ((x_tmp == i) && (y_tmp == j)) {
			return 1;
		}
		x_tmp++;
		y_tmp++;
	}
	return 0;
}

bool check_pos(int** desk, int x, int y) {
	if ((x >= n) || (y >= n)) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == x) && (j == y)) {
				continue;
			}
			else if ((desk[i][j] == 1) && ((x == i) || (y == j) || (on_diag(i, j, x, y) == 1))) {
				return 0;
			}
		}
	}
	return 1;
}

void solution(int** desk, int x, int y) {
	if (x == n) {
		return;
	}
	else if (y == n) {
		print_desk(desk);
		solutions++;
	}
	else if (check_pos(desk, x, y) == 0) {
		solution(desk, x + 1, y);
	}
	else if (check_pos(desk, x, y) == 1) {
		desk[x][y] = 1;
		solution(desk, 0, y + 1);
		desk[x][y] = 0;
		solution(desk, x + 1 , y);
	}
}

void delete_desk(int** desk) {
	for (int i = 0; i < n; i++) {
		delete[] desk[i];
	}
	delete[] desk;
}

int main() {

	int x = 0, y = 0, key = 1;
	int** desk = new int* [n];
	for (int i = 0; i < n; i++) {
		desk[i] = new int[n];
	}

	create_desk(desk);
	solution(desk, x, y);
	delete_desk(desk);
	cout << "Solutions number: " << solutions << endl;

	return 0;
}
