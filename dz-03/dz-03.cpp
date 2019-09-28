#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void task1() {
	double s, p, n;
	cout << "Введите сумму займа S: ";
	cin >> s;
	cout << "Введите процент p: ";
	cin >> p;
	cout << "Введите срок займа n в годах: ";
	cin >> n;
	if ((s <= 0) || (p <= 0) || (n <= 0))
		cout << "\nНеправильный формат входных данных.\n";
	else {
		double r = p / 100.0;
		double m = (s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
		cout << "\nМесячная выплата составляет: " << m << "\n";
	}
}

void task2() {
	double s, m, n;
	double r = 0.5; double rmin = 0.0; double rmax = 1.0;
	cout << "Введите сумму займа S: ";
	cin >> s;
	cout << "Введите размер платежа m: ";
	cin >> m;
	cout << "Введите срок займа n в годах: ";
	cin >> n;
	if ((s <= 0) || (m <= 0) || (n <= 0))
		cout << "\nНеправильный формат входных данных.\n";
	else {
		m = round(m * 100) / 100;
		double mcur = round( ((s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1))) * 100) / 100;
		while (m != mcur) {
			if (mcur < m) {
				rmin = r;
				r = rmin + (rmax - rmin) / 2;
			} else if (mcur > m) {
				rmax = r;
				r = rmin + (rmax - rmin) / 2;
			}
			mcur = round(((s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1))) * 100) / 100;
		}
		double p = round(r * 100.0 * 100.0) / 100.0;
		cout << "\nПроцент по ссуде составляет: " << p << "%\n";
	}
}

void task3() {
	string line;
	ifstream fileOnReading("myfile.bin");
	if (fileOnReading.is_open()) {
		while (!fileOnReading.eof()) {
			getline(fileOnReading, line);
			cout << line << "\n";
		}
		fileOnReading.close();
	} else {
		cout << "Error of file reading";
	}
}

void task4() {
	string line;
	string lineFormatted;
	ifstream fileOnReading("myfile.bin");

	if (fileOnReading.is_open()) {

		while (!fileOnReading.eof()) {
			getline(fileOnReading, line);
			lineFormatted = "";

			for (int i = 0; i < line.size(); i++) {

				if ( (line[i] == ' ') || (line[i] == '.') || (line[i] == '-') || ( ( line[i] >= '0') && (line[i] <= '9') ) ) {
					lineFormatted += line[i];
				}
			}

			if (lineFormatted != "") 
				cout << lineFormatted << "\n";
		}
		fileOnReading.close();
	}
	else {
		cout << "Error of file reading";
	}
}

char unsorted[30];
int task5comparator(const void* a, const void* b) {
	const char* x = (char*)a;
	const char* y = (char*)b;

	if (*x > * y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}
void quickSort(char* letters, int left, int right)
{
	int pivot; 
	int l_hold = left; 
	int r_hold = right; 
	pivot = letters[left];
	while (left < right) 
	{
		while ((letters[right] >= pivot) && (left < right))
			right--; 
		if (left != right) 
		{
			letters[left] = letters[right];
			left++; 
		}
		while ((letters[left] <= pivot) && (left < right))
			left++; 
		if (left != right) 
		{
			letters[right] = letters[left];
			right--; 
		}
	}
	letters[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quickSort(letters, left, pivot - 1);
	if (right > pivot)
		quickSort(letters, pivot + 1, right);
}
void task5() {
	string input = "sutnzoahwefjgasdbjsadhgwxqeirk";
	cout << "Изначальная строка: " << input << "\n";
	//char letters[30];
	for (int i = 0; i < 30; i++) {
		unsorted[i] = input[i];
	}

	quickSort(unsorted, 0, input.size() - 1);
	//qsort(letters, 30, sizeof(char), task5comparator);
	string output = "";
	for (int i = 0; i < 30; i++) {
		output += unsorted[i];
	}
	cout << "Отсортированная строка: " << output << "\n";
}

int main()
{
	setlocale(0, "");
	int n;
	cout << "\nДомашняя работа 3. Введите номер задания (0 - выход): ";
	cin >> n;
	while (n != 0) {
		switch (n) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		}
		cout << "\n========================\n\nДомашняя работа 3. Введите номер задания (0 - выход):";
		cin >> n;
	}
	return 0;
}


