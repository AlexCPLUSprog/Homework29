#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ������� 2
bool overwrite(string path, string tmp) {
	ofstream out;
	out.open(path, ios::out);
	if (out.is_open()) {			
		out << tmp + '\n'; 
		cout << "������ �������� ������ ���������� �����.\n";
		out.close();
		return true;
	}	
	else {
	cout << "���� �� ����������.\n";
	out.close();
	return false;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int n;

	// ������� 1.
	cout << "������� 1.\n";
	ofstream out;
	
	out.open("file.txt", ios::app);

	if (out.is_open()) {
		string input;
		do {
			cout << "������� ������:\n";
			getline(cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		cout << "������ �������� �����!\n";

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
		cout << "������ �������� �����!\n";

	in.close();
	remove("file.txt");

	// ������� 2.
	cout << "������� 2.\n������� ������ -> ";
	string str;
	cin >> str;
	overwrite("file2.txt", str);


	return 0;
}