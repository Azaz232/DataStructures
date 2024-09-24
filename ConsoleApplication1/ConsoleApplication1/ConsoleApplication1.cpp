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

//   3.1

//double GetPower(double base, int exponent) {
//    double result = 1.0;
//    for (int i = 0; i < exponent; i++) {
//        result *= base;
//    }
//    return result;
//}
//
//int main() {
//    cout << "2.0 ^ 5 = " << GetPower(2.0, 5) << endl;
//    cout << "3.0 ^ 4 = " << GetPower(3.0, 4) << endl;
//    cout << "-2.0 ^ 5 = " << GetPower(-2.0, 5) << endl;
//    return 0;
//}

// 3.2

//void DemoGetPower(double base, int exponent) {
//    double result = GetPower(base, exponent);
//    cout << base << " ^ " << exponent << " = " << result << endl;
//}
//
//int main() {
//    DemoGetPower(2.0, 5);
//    DemoGetPower(3.0, 4);
//    DemoGetPower(-2.0, 5);
//    return 0;
//}


//   3.3

//void RoundToTens(int& value) {
//    int remainder = value % 10;
//    if (remainder < 5) {
//        value = (value / 10) * 10;
//    }
//    else {
//        value = (value / 10 + 1) * 10;
//    }
//}
//
//int main() {
//    int a = 14;
//    cout << "For " << a << " rounded value is ";
//    RoundToTens(a);
//    cout << a << endl;
//
//    a = 191;
//    std::cout << "For " << a << " rounded value is ";
//    RoundToTens(a);
//    cout << a << endl;
//
//    a = 27;
//    cout << "For " << a << " rounded value is ";
//    RoundToTens(a);
//    cout << a << endl;
//
//    return 0;
//}

// 4.1

//int main()
//{
//	int a = 5;
//	int b = 4;
//	cout << "Address of a: " << &a << endl;
//	cout << "Address of b: " << &b << endl;
//
//	double c = 13.5;
//	cout << "Address of c: " << &c << endl;
//
//	bool d = true;
//	cout << "Address of d: " << &d << endl;
//}

//   4.2

//int main()
//{
//	int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
//	cout << "Size of int type: " << sizeof(int) << endl;
//	for (int i = 0; i < 10; i++)
//	{
//	cout << "Address of a[" << i << "]: " << &a[i] << endl;
//	}
//	
//	cout << endl;
//	cout << "Size of double type: " << sizeof(double) << endl;
//	double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
//	for (int i = 0; i < 10; i++) {
//		cout << "Address of b[" << i << "]: " << &b[i] << endl;
//	}
//}

//  4.3

//int main() {
//    int a = 5;
//    int& b = a;
//
//    cout << "Address of a: " << &a << endl;
//    cout << "Address of b: " << &b << endl;
//    cout << endl;
//
//    b = 7;
//    cout << "Value of a: " << a << endl;
//}

//  4.4

//void Foo(double a)
//{
//    cout << "Address of a in Foo(): " << &a << endl;
//    cout << "Value of a in Foo(): " << a << endl;
//
//    a = 15.0;
//    cout << "New value of a in Foo(): " << a << endl;
//}
//
//int main()
//{
//    double a = 5.0;
//    cout << "Address of a in main(): " << &a << endl;
//    cout << "Value of a in main(): " << a << endl;
//    cout << endl;
//
//    Foo(a);
//
//    cout << endl;
//    cout << "Value of a in main(): " << a << endl;
//
//}

//  4.5


//void Foo(double& a)
//{
//    cout << "Address of a in Foo(): " << &a << endl;
//    cout << "Value of a in Foo(): " << a << endl;
//
//    a = 15.0;
//    cout << "New value of a in Foo(): " << a << endl;
//}
//
//int main()
//{
//    double a = 5.0;
//    cout << "Address of a in main(): " << &a << endl;
//    cout << "Value of a in main(): " << a << endl;
//    cout << endl;
//
//    Foo(a);
//
//    cout << endl;
//    cout << "Value of a in main(): " << a << endl;
//
//}

//  4.6

//int main()
//{
//    int a = 5;
//    int* pointer = &a;
//
//    cout << "Address of a: " << &a << endl;
//    cout << "Address in pointer: " << pointer << endl;
//    cout << "Address of pointer: " << &pointer << endl;
//    cout << endl;
//
//    *pointer = 7;
//    cout << "Value in a: " << a << endl;
//    cout << "Value by pointer address: " << *pointer << endl;
//
//}

//Ответьте на вопрос : как в исходном коде отличить операцию разыменования, объявление
//указателя и операцию умножения ? Все три операции используют символ*, поэтому важно
//уметь отличать их в исходном коде.


