#include <iostream>

using namespace std;

//void Breakpoints() {
//	double add = 1.0;
//	double sum = 0.0;
//	for (int i = 0; i < 1000; i++) {
//		sum += add * i;
//		if (i % 3 == 0) {
//			add *= 1.1;
//		}
//		else {
//			add /= 3.0;
//		}
//	}
//	cout << "Total sum is " << sum << endl;
//}
//
//int main() {
//	Breakpoints();
//}
//



//task2

//int main() {
//	int array[10] = { 3, 6, -7, 4, 1, 2, -4, -10, 8, 0 };
//
//	cout << "sourse array: " << endl;
//	for (int i = 0; i < 10; i++) {
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9 - i; j++) {
//			if (array[j] > array[j+1]) {
//				int temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//	cout << "sorted array : " << endl;
//	for (int i = 0; i < 10; i++) {
//		cout << array[i] << " ";
//	}
//	return 0;
//}

//int main() {
//	float arr[12] = {2.0, 838.0, 798.5, -8.9, -4.4, 1.0002, 999.8, 3.999, 54675.56, -1970, 6.666, 2.33};
//	cout << "sourse array : ";
//	for (int i = 0; i < 12; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	float s;
//	int k = 0;
//	cout << "enter searching value : " << endl; cin >> s;
//	for (int i = 0; i < 12; i++) {
//		if (arr[i] >= s) {
//			k++;
//		}
//	}
//	cout << k << "  ellements bigger than  " << s;
//  return 0;
//}

//int main() {
//	char arr[8];
//	cout << "enter an array of 8 characters : " << endl;
//	for (int i = 0; i < 8; i++) {
//		cout << "a[" << i << "] : ";
//		cin >> arr[i];
//	}
//	cout << "your array :" << endl;
//	for (int i = 0; i < 8; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl << "letters from your array : " << endl;
//	for (int i = 0; i < 8; i++) {
//		if (arr[i] >= 'a' && arr[i] <= 'z') {
//			cout << arr[i] << " ";
//		}
//	}
//	return 0;
//}

