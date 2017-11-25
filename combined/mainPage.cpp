#include "mainPage.h"
#include "quitScreen.h"
#include "stuffAndThings.h"
void printHeader() {
	cout << " ______                        _     _                   " << endl;
	cout << "|  ____|              /\\      | |   | |                  " << endl;
	cout << "| |__     ______     /  \\   __| | __| |_ __ ___  ___ ___ " << endl;
	cout << "|  __|   |______|   / /\\ \\ / _` |/ _` | '__/ _ \\/ __/ __| " << endl;
	cout << "| |____            / ____ \\ (_| | (_| | | |  __/\\__ \\__ \\ " << endl;
	cout << "|______|          /_/    \\_\\__,_|\\__,_|_|  \\___||___/___/" << endl;
	//cout << "Welcome to the Electronic address book\n";
	breakLine();
}
void breakLine() {
	for (int i = 0; i < 60; i++) {
		cout << "=";
	}
	cout << endl;
}
void showFunction() {
	string functionality[7] = { "Insert Record", "Insert Batch","Modify Record","Delete Record","Search Record","Print Record","Quit Program " };
	cout << "Select the function you like to use: \n\n";
	for (int i = 0; i < sizeof(functionality) / sizeof(functionality[0]); i++) {
		cout << " " << i + 1 << ". " << functionality[i] << endl;
	}
}
void showCurrRecord() {
	cout << "Current No. of Record: " << "100" << endl << endl;
}
void showMain() {
	int selection;
	bool quitFlag = true;
	do {
		system("CLS");
		printHeader();
		showCurrRecord();
		showFunction();
		breakLine();
		cout << "Please select the action: ";
		cin >> selection;
		if (cin.fail()) {
			cout << "Invalid Input,please re-enter \n";
			system("pause");
			cin.clear();
			cin.sync();
			cin.ignore();
			continue;
		}
		switch (selection) {
		case 1:
			insertSingle();
			system("pause");
				break;
		case 2:
			insertMultiple();
			system("pause");
			break;
		case 3:
			modRec();
			system("pause");
			break;
		case 4:
			delRec();
			system("pause");
			break;
		case 5:
			search();
			system("pause");
			break;
		case 6:
			printRec();
			system("pause");
			break;
		case 7:
			quitFlag = false;
			break;

		}
	} while (quitFlag);
	quitScreen();
}