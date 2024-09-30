#include <iostream>
using namespace std;

//i = 0, sum = 0
//i = 1, sum = 1,1
//i = 2, sum = 3,52
//i = 3, sum = 7,513
//i = 4, sum = 13,3694
//i = 5, sum = 21,42195
//i = 6, sum = 32,051316
//i = 7, sum = 45,6923357
//i = 8, sum = 62,84104618
//i = 9, sum = 84,062575399
// 
//void Breakpoints()
//{
//    double add = 1.0;
//    double sum = 0.0;
//    for (int i = 0; i < 10; i++)
//    {
//        sum += add * i;
//        add = 1.1;
//    }
//    cout << "Total sum is " << sum << endl;
//}



////i = 777, sum = 3,2624579394327844

//void Breakpoints()
//{
//    double add = 1.0;
//    double sum = 0.0;
//    for (int i = 0; i < 1000; i++)
//    {
//        sum += add * i; // Поставьте условную точку останова здесь
//        if (i % 3 == 0)
//        {
//            add *= 1.1;
//        }
//        else
//        {
//            add /= 3.0;
//        }
//    }
//    cout << "Total sum is " << sum << endl;
//}

//void Breakpoints() 
//{
//	double add = 1.0;
//	double sum = 0.0;
//	for (int i = 0; i < 1000; i++) {
//		sum += add * i;
//		if (i % 3 == 0) 
//		{
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

//  2

//int main() 
//{
//	int array[10] = { 3, 6, -7, 4, 1, 2, -4, -10, 8, 0 };	
//
//	cout << "sourse array: " << endl;
//	for (int i = 0; i < 10; i++) 
//  {
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9 - i; j++) 
//      {
//			if (array[j] > array[j+1]) 
//          {
//				int temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//	cout << "sorted array : " << endl;
//	for (int i = 0; i < 10; i++) 
//  {
//		cout << array[i] << " ";
//	}
//	return 0;
//}

//int main() 
// {
//	float arr[12] = {2.0, 838.0, 798.5, -8.9, -4.4, 1.0002, 999.8, 3.999, 54675.56, -1970, 6.666, 2.33};
//	cout << "sourse array : ";
//	for (int i = 0; i < 12; i++) 
// {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	float s;
//	int k = 0;
//	cout << "enter searching value : " << endl;
//  cin >> s;
//	for (int i = 0; i < 12; i++) 
// {
//		if (arr[i] >= s) 
//		{
//			k++;
//		}
//	}
//	cout << k << "  ellements bigger than  " << s;
//  return 0;
//}

//int main() 
// {
//	char arr[8];
//	cout << "enter an array of 8 characters : " << endl;
//	for (int i = 0; i < 8; i++) 
// {
//		cout << "a[" << i << "] : ";
//		cin >> arr[i];
//	}
//	cout << "your array :" << endl;
//	for (int i = 0; i < 8; i++) 
//  {
//		cout << arr[i] << " ";
//	}
//	cout << endl << "letters from your array : " << endl;
//	for (int i = 0; i < 8; i++) {
//		if (arr[i] >= 'a' && arr[i] <= 'z') 
//      {
//			cout << arr[i] << " ";
//		}
//	}
//}

//   3.1

//double GetPower(double base, int exponent) 
//{
//    double result = 1.0;
//    for (int i = 0; i < exponent; i++) 
//    {
//        result *= base;
//    }
//    return result;
//}
//
//int main() 
//{
//    cout << "2.0 ^ 5 = " << GetPower(2.0, 5) << endl;
//    cout << "3.0 ^ 4 = " << GetPower(3.0, 4) << endl;
//    cout << "-2.0 ^ 5 = " << GetPower(-2.0, 5) << endl;
//}

// 3.2

//void DemoGetPower(double base, int exponent) 
//{
//    double result = GetPower(base, exponent);
//    cout << base << " ^ " << exponent << " = " << result << endl;
//}
//
//int main() 
//{
//    DemoGetPower(2.0, 5);
//    DemoGetPower(3.0, 4);
//    DemoGetPower(-2.0, 5);
//}


//   3.3

//void RoundToTens(int& value) 
//{
//    int remainder = value % 10;
//    if (remainder < 5)
//    {
//        value = (value / 10) * 10;
//    }
//    else 
//    {
//        value = (value / 10 + 1) * 10;
//    }
//}
//
//int main() 
//{
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
//	for (int i = 0; i < 10; i++) 
//  {
//		cout << "Address of b[" << i << "]: " << &b[i] << endl;
//	}
//}

//  4.3

//int main() 
//{
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

//  4.7

//void Foo(double* a)
//{
//    cout << "Address in pointer: " << a << endl;
//    cout << "Address of pointer: " << &a << endl;
//    cout << "Value in pointer address: " << *a << endl;
//
//    *a = 15.0;
//    cout << "New value in pointer address: " << *a << endl;
//}
//
//int main()
//{
//    double value = 5.0;
//    double* pointer = &value;
//
//    cout << "Address of value in main(): " << &value << endl;
//    cout << "Address in pointer in main(): " << pointer << endl;
//    cout << "Address of pointer in main(): " << &pointer << endl;
//    cout << "Value of a in main(): " << value << endl;
//    cout << endl;
//
//    Foo(pointer);
//
//    cout << endl;
//    cout << "Value of a in main(): " << value << endl;
//
//}


// 5.1

//int main()
//{
//    double* array = new double[8];
//
//    array[0] = 1.0;
//    array[1] = 15.0;
//    array[2] = -8.2;
//    array[3] = -3.5;
//    array[4] = 12.6;
//    array[5] = 38.4;
//    array[6] = -0.5;
//    array[7] = 4.5;
//
//    cout << "Array of double:" << endl;
//    for (int i = 0; i < 8; i++) 
//    {
//        cout << array[i] << " ";
//    }
//    cout << endl;
//
//    delete[] array;
//}

//  5.2

//int main()
//{
//    bool* array = new bool[8];
//    array[0] = true;
//    array[1] = false;
//    array[2] = true;
//    array[3] = true;
//    array[4] = false;
//    array[5] = true;
//    array[6] = false;
//    array[7] = false;
//    cout << "Array of bool:" << endl;
//    for (int i = 0; i < 8; i++) 
//    {
//        cout << boolalpha <<array[i] << " "; // ?
//    }
//   cout << endl;
//
//    delete[] array;
//}

//  5.3

//int main() {
//	int n; 
//  cout << "enter n: ";
//  cin >> n;
//	char* arr = new char[n];
//
//	cout << "enter " << n << " characters: " << endl;
//	for (int i = 0; i < n; i++) 
//  {
//		cin >> arr[i];
//	}
//	cout << "array of characters: ";
//	for (int i = 0; i < n; i++) 
//  {
//		cout << arr [i] << " ";
//	}
//	delete[] arr; 
//}

// 5.4

//void sort(double * arr, int size) {
//    for (int i = 0; i < 9; i++) 
//    {
//    	for (int j = 0; j < 9 - i; j++) 
//      {
//    		if (arr[j] > arr[j+1]) 
//          {
//    			int temp = arr[j];
//    			arr[j] = arr[j + 1];
//    			arr[j + 1] = temp;
//    		}
//    	}
//    }
//}
//
//int main()
//{
//    double* arr = new double[10];
//
//    arr[0] = 1.0;
//    arr[1] = 15.0;
//    arr[2] = -8.2;
//    arr[3] = -3.5;
//    arr[4] = 12.6;
//    arr[5] = 38.4;
//    arr[6] = -0.5;
//    arr[7] = 4.5;
//    arr[8] = 39.8;
//    arr[9] = -6.5;
//    
//
//    cout << "Array of double:" << endl;
//    for (int i = 0; i < 10; i++) 
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    cout << "Sorted array: ";
//    sort(arr, 10);
//    for (int i = 0; i < 10; i++) 
//    {
//        cout << arr[i] << " ";
//    }
//
//    delete[] arr;
//}

//  5.5

//int Search(int*arr, int s) 
//{
//	int k = 0;
//	for (int i = 0; i < 10; i++) 
//  {
//		if (arr[i] >= s) 
//      {
//			k++;
//		}
//	}
//	return k;
//}
//
//int main() 
//{
//	int* arr = new int[10];
//	arr[0] = 1;
//	arr[1] = 15;
//	arr[2] = -8;
//	arr[3] = -3;
//	arr[4] = 12;
//	arr[5] = 38;
//	arr[6] = 0;
//	arr[7] = 4;
//	arr[8] = 39;
//	arr[9] = -6;
//
//	cout << "enter searching value: ";
//  int s;
//  cin >> s;
//	int k = Search(arr, s);
//	cout << k;
// delete[] arr;
//
//}

//  5.6

//void letters(char*arr) 
//{
//	for (int i = 0; i < 15; i++)
//  {
//		if (arr[i] >= 'a' && arr[i] <= 'z') 
//      {
//			cout << arr[i] << " ";
//		}
//	}
//}
//
//int main() 
//{
//	char* arr = new char[15];
//	arr[0] = 'd';
//	arr[1] = 'u';
//	arr[2] = 'f';
//	arr[3] = 'a';
//	arr[4] = '9';
//	arr[5] = '4';
//	arr[6] = ';';
//	arr[7] = 't';
//	arr[8] = 'e';
//	arr[9] = 'w';
//	arr[10] = '[';
//	arr[11] = '6';
//	arr[12] = '2';
//	arr[13] = '5';
//	arr[14] = '1';
//	cout << "your array: " << endl;
//	for (int i = 0; i < 15; i++) 
//  {
//		cout << arr[i] << " ";
//	}
//	cout << endl << "letters in the array: " << endl;
//	letters(arr);
//	delete[]arr;
//}

//  5.7

//#include <cstdlib>
//#include <ctime>
//
//int* MakeRandomArray(int arraySize) 
//{
//    int* arr = new int[arraySize];
//    for (int i = 0; i < arraySize; i++) 
//    {
//        arr[i] = rand() % 101; // numbers from 0 to 100
//    }
//    return arr;
//}
//
//void ShowArray(int* arr, int arraySize) 
//{
//    for (int i = 0; i < arraySize; i++) 
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() 
//{
//    srand(time(0));
//    int* arr5 = MakeRandomArray(5);
//    int* arr8 = MakeRandomArray(8);
//    int* arr13 = MakeRandomArray(13);
//
//    cout << "Random array of 5: ";
//    ShowArray(arr5, 5);
//
//    cout << "Random array of 8: ";
//    ShowArray(arr8, 8);
//
//    cout << "Random array of 13: ";
//    ShowArray(arr13, 13);
//
//    delete[] arr5;
//    delete[] arr8;
//    delete[] arr13;
//}

//  5.8

//int* ReadArray(int count) 
//{
//    int* values = new int[count];
//    for (int i = 0; i < count; i++) 
//    {
//        cin >> values[i];
//    }
//    return values;
//}
//
//int CountPositiveValues(int* values, int count) 
//{
//    int result = 0;
//    for (int i = 0; i < count; i++) 
//    {
//        if (values[i] > 0) 
//        {
//            result++;
//        }
//    }
//    return result;
//}
//
//int main() 
//{
//    int count = 15;
//    int* values = ReadArray(count);
//    cout << "Count is: " << CountPositiveValues(values, count) << endl;
//    delete[] values; // we need to clear the heap 2 times
//
//    count = 20;
//    values = ReadArray(count);
//    cout << "Count is: " << CountPositiveValues(values, count) << endl;
//    delete[] values; 
//
//    return 0;
//}

//   6

//struct Person
//{
//	string FirstName;
//	string LastName;
//	unsigned Age;
//};
//
//void WritePerson(const Person& person)
//{
//	cout << "First Name: " + person.FirstName
//		+ ";  Last Name: " + person.LastName
//		+ ";  Age: ";
//	cout << person.Age << endl;
//}
//const int PeopleCount = 5;
//
//Person** CreatePeopleArray()
//{
//	Person** people = new Person * [PeopleCount];
//	people[0] = new Person();
//	people[0]->FirstName = "Casey";
//	people[0]->LastName = "Aguilar";
//	people[0]->Age = 30;
//
//	people[1] = new Person();
//	people[1]->FirstName = "Brock";
//	people[1]->LastName = "Curtis";
//	people[1]->Age = 19;
//
//	people[2] = new Person();
//	people[2]->FirstName = "Blake";
//	people[2]->LastName = "Diaz";
//	people[2]->Age = 21;
//
//	people[3] = new Person();
//	people[3]->FirstName = "Cristian";
//	people[3]->LastName = "Evans";
//	people[3]->Age = 55;
//
//	people[4] = new Person();
//	people[4]->FirstName = "Les";
//	people[4]->LastName = "Foss";
//	people[4]->Age = 4;
//	
//	return people;
//}
//
//
//void ClearPerson(Person* person)
//{
//	delete person;
//}
//
//void ClearPeople(Person** people, int itemsCount)
//{
//	for (int i = 0; i < itemsCount; i++)
//	{
//		ClearPerson(people[i]);
//	}
//	delete[] people;
//}
//
//int FindPersonByLastName(Person** people, int count, std::string lastName) {
//	for (int i = 0; i < count; i++) {
//		if (people[i]->LastName == lastName) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	Person * *people = CreatePeopleArray();
//	for (int i = 0; i < PeopleCount; i++)
//	{
//		WritePerson(*people[i]);
//	}
//
//	string lastName;
//	cout << "Enter last name: ";
//	cin >> lastName;
//	int foundIndex = FindPersonByLastName(people, PeopleCount, lastName);
//
//	if (foundIndex == -1) {
//		cout << "Could not find a person by last name: " << lastName << endl;
//	}
//	else {
//		cout << "A person's last name " << lastName << " was found. Its index in the array is " << foundIndex << endl;
//	}
//
//	ClearPeople(people, PeopleCount);
//}

