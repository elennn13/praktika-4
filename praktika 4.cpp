#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


// заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

// вывод массива консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

//1
template <typename T>
void clear_arr(T arr[], int length, int key) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == key) {
			arr[i] = 0;
		}
	}
}

//2
int index_sum(int array1[], int array2[], int length1, int length2, int index) {
	if (index < 0 || index >= length1 || index >= length2) {
		std::cout << "ERROR\n";
		return 0;
	}
	return array1[index] + array2[index];
}
//3 ТЮ-ТЮ :)



//4
int compar_pare(const int arr[], int length, int num1, int num2) {
	for (int i = 0; i < length - 1; i++) {
		if (arr[i] == num1 && arr[i + 1] == num2) {
			return i;
		}
	}
	return -1;
}



int main() {
	setlocale(LC_ALL, "ru");
	int n, m;

	// Задача 1. Создайте шаблонную функцию clear_arr, которая
	// принимает массив, его длину и ключевое значение.Функция
	// обнуляет все элементы массива, которые равны ключевому
	// значению.
	
	std::cout << "Задача 1.\n";
	const int size = 10;
	int arr[size];
	fill_arr(arr, size, 15, 25);

	std::cout << "Изначальный массив:\n";
	print_arr(arr, size);

	std::cout << "Введите число -> ";
	std::cin >> n;
	clear_arr(arr, size, n);

	std::cout << "Массив с обнуленными элементами:\n";
	print_arr(arr, size);
	std::cout << std::endl;
	

	// Задача 2. Создайте функцию index_sum, которая
	// принимает два массива, их длины и число - индекс.Функция
	// должна возвращать сумму элементов обоих массивов под
	// указанным индексом.
	
	const int size2_1 = 5, size2_2 = 7;
	int arr2_1[size2_1];
	int arr2_2[size2_2];
	fill_arr(arr2_1, size2_1, 15, 25);
	print_arr(arr2_1, size2_1);
	fill_arr(arr2_2, size2_2, 15, 25);
	print_arr(arr2_2, size2_2);
	std::cout << "Изначальный массив:\n";
	std::cout << "Введите индекс:\n";
	std::cin >> n;

	int result = index_sum(arr2_1, arr2_2, size2_1, size2_2, n);
	std::cout << "Сумма элементов массива по индексу " << n << " = " << result << std::endl;
	


	// Задача 3. Создайте перегруженную функцию prime_range,
	// которая принимает два числа, являющиеся началом и концом
	// диапазона.Функция должна вывести все простые числа, которые входят в переданный в неё диапазон(границы
	// диапазона включены).Если функция принимает только одно
	// число, то выводятся все простые числа из диапазона от 1 до
	// переданного числа включительно.




	// Задача 4. Создайте функцию compare_pare, которая
	// принимает массив, его длину и два числа.Если в массиве есть
	// оба этих числа и они стоят рядом друг с другом в том же
	// порядке, в котором они были переданы в функцию, то функция
	// возвращает индекс первого из них.Иначе возвращается - 1.
	
	int arr4[] = { 1,2,3,4 };
	int size4 = sizeof(arr4) / sizeof(arr4[0]);
	std::cout << "Введите первое число -> ";
	std::cin >> n;
	std::cout << "Введите второе число -> ";
	std::cin >> m;

	
	int index = compar_pare(arr4, size4, n, m);

	if (index == -1) {
		std::cout << " Числа не стоят рядом друг с другом или отсутствуют в массиве " << std::endl;
	}
		else {
		std::cout << " Числа " << n << " " << m << " стоят рядом " << std::endl;
		}
		
	return 0;
}
