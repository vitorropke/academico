#include <iostream>

using namespace std;

bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
	// Equação do círculo -> (x - h)² + (y - k)² = r²
	for(int i = y1; i <= y2; i++) {
		for(int j = x1; j <= x2; j++) {
			if((i - y_center) * (i - y_center) + (j - x_center) * (j - x_center) <= radius * radius)
				return true;
		}
	}

	return false;
}

int main() {
	cout << checkOverlap(1, 0, 0, 1, -1, 3, 1) << '\n';

	return 0;
}