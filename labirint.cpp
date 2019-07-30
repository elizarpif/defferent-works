#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
//#include "stdafx.h"
using namespace std;

class Labir {
private:
	int count;
	vector<string> str;
public:
	Labir() {
		count = 0;
	}
	~Labir() {
		str.clear();
	}
	void insertStr(string s) {
		str.push_back(s);
		count++;
	}
	void labirint();
	void printLabirint() {
		for (int i = 0; i < count; i++) {
			cout << str[i] << endl;
		}
		cout << "count = " << count << endl;
	}
};

void Labir::labirint() {
	int i = 1;
	for (i; i < count; i+=2) {
		//парсим
		int border = str[i].length() - 1;
		for (int j = 1; j < border; j+=2) { //два крайних - стенки
			str[i][j] = '0';

			int dir = rand() % 2;
			
			if ((dir || !(i - 1)) && j + 1 != border) //если вверх нельзя, то только вправо
			{
				//cout << "rand = " << dir << endl;
				str[i][j + 1] = '0';
			}
			else if (i-1)
				str[i - 1][j] = '0';
			
				
		}

	}
}


int main() {
	std::cout << "helllo ";
	ofstream fout("textlab.txt");
	if (fout.is_open()) {
		for (int i = 0; i < 25; i++){
			
			for (int j = 0; j < 25;j++)
				fout << "1";
			fout << endl;
		}

		fout.close();
	}


	ifstream fin("textlab.txt");
	string bf;

	srand(time(NULL));
	if (fin.is_open()) {
		Labir lb;
		while (fin >> bf)
			lb.insertStr(bf);
		fin.close();
		lb.printLabirint();
		lb.labirint();
		lb.printLabirint();
	}
	

	system("pause");
}