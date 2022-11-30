#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Задание 2
bool overwrite(string path, string tmp) {
	ofstream out;
	out.open(path, ios::out);
	if (out.is_open()) {			
		out << tmp + '\n'; 
		cout << "Строка заменила старое содержимое файла.\n";
		out.close();
		return true;
	}	
	else {
	cout << "Файл не существует.\n";
	out.close();
	return false;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int n;

	// Задание 1.
	cout << "Задание 1.\n";
	ofstream out;
	
	out.open("file.txt", ios::app);

	if (out.is_open()) {
		string input;
		do {
			cout << "Введите строку:\n";
			getline(cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		cout << "Ошибка открытия файла!\n";

	out.close();

	ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			string str;
			getline(in, str);
			cout << str << endl;
		}

	}
	else
		cout << "Ошибка открытия файла!\n";

	in.close();
	remove("file.txt");

	// Задание 2.
	cout << "Задание 2.\nВведите строку -> ";
	string str;
	cin >> str;
	overwrite("file2.txt", str);


	return 0;
}