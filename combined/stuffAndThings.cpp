#include"stuffAndThings.h"
#include <fstream>
#include <string>
#include <sstream>

void modAscii() {
	system("CLS");
	cout << "  __  __           _ _  __       \n";
	cout << " |  \\/  | ___   __| (_)/ _|_   _ \n";
	cout << " | |\\/| |/ _ \\ / _` | | |_| | | |\n";
	cout << " | |  | | (_) | (_| | |  _| |_| |\n";
	cout << " |_|  |_|\\___/ \\__,_|_|_|  \\__, |\n";
	cout << "                           |___/ \n";
	breakLine();
}
void delAscii() {
	system("CLS");
	cout << "  ____       _      _       \n";
	cout << " |  _ \\  ___| | ___| |_ ___ \n";
	cout << " | | | |/ _ \\ |/ _ \\ __/ _ \\\n";
	cout << " | |_| |  __/ |  __/ ||  __/\n";
	cout << " |____/ \\___|_|\\___|\\__\\___|\n";
	breakLine();
}
void insAscii(){
	system("CLS");
	cout << "  ___                     _   \n";
	cout << " |_ _|_ __  ___  ___ _ __| |_ \n";
	cout << "  | || '_ \\/ __|/ _ \\ '__| __|\n";
	cout << "  | || | | \\__ \\  __/ |  | |_ \n";
	cout << " |___|_| |_|___/\\___|_|   \\__|\n";
	cout << "                              \n";
	breakLine();
}
void searchAscii() {
	system("CLS");
	cout << "  ____                      _     \n";
	cout << " / ___|  ___  __ _ _ __ ___| |__  \n";
	cout << " \\___ \\ / _ \\/ _` | '__/ __| '_ \\ \n";
	cout << "  ___) |  __/ (_| | | | (__| | | |\n";
	cout << " |____/ \\___|\\__,_|_|  \\___|_| |_|\n";
	breakLine();
}
void printAscii() {
	system("CLS");
	cout << "  ____       _       _   \n";
	cout << " |  _ \\ _ __(_)_ __ | |_ \n";
	cout << " | |_) | '__| | '_ \\| __|\n";
	cout << " |  __/| |  | | | | | |_ \n";
	cout << " |_|   |_|  |_|_| |_|\\__|\n";
	breakLine();
}

string toLower(string temp) {
	//32
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] <= 90) {
			temp[i] = temp[i] + 32;
		}
	}
	return temp;
}
void modRec() {
	system("CLS");
	//TODO Searching inplementation
	int selection;
	string query;
	string demo[15] = { "Mr.","Trump","Donald","Male","1999-9-9","2994 Arbor Court","Mountain View","Washington","99999","United States","2","99999999","donaldtrump@world.com","President","Trump Co." };
	string colName[15] = { "Title","Surname","Given Name","Gender","Birthday","StreetAddress","City","State","ZipCode","Country","Country Code","Telephone Number","Email","Occupation","Company" };
	modAscii();
	cout << "Filter content using: \n";
	for (int i = 0; i < sizeof(colName) / sizeof(colName[0]); i++) {
		cout << i + 1 << ". " << colName[i] << endl;

	}
	breakLine();
	cout << "Select the column you would like to use to filter out record: ";
	cin >> selection;
	modAscii();
	cout << "The column you have chosen to filter by are: " << colName[selection - 1] << endl;
	cout << "Please enter the keywords to be filter on: ";
	cin >> query;
	
	int totalResult = 7;
	int currResult = 0;
	int recOnPage = 0;
	modAscii();
	cout << "Entry(s) found with selected criteria: \n";
	do{
		if (recOnPage != 5 && currResult < totalResult) {
			//&&currResult<totalResult
			cout << "Index: " << currResult+1 << endl;
			cout << "1. Full Name : " << demo[0] << " " << demo[2] << " " << demo[1] << endl;
			//cout << "2. Gender : " << demo[3] << endl;
			//cout << "3. Birthday : " << demo[4] << endl;
			//cout << "4. Full Address : " << demo[5] << "," << demo[6] << "," << demo[7] << "," << demo[9] << endl;
			//cout << "5. ZipCode : " << demo[8] << endl;
			//cout << "6. Telephone Number : " << "(" << demo[10] << ") " << demo[11] << endl;
			//cout << "7. Email : " << demo[12] << endl;
			cout << "2. Occupation : " << demo[13] << " at " << demo[14] << endl;
			breakLine();
			currResult++;
			recOnPage++;
		}
		else {
			cout << "Input 'n' to go to next page,Input 'p' to go to preveous page \n";
			cout << "Input the Index to select that record to modify\n";
			cout << "Input Your Choice: ";
			cin >> query;
			if (query == "n" || query == "N") {
				if (currResult == totalResult) {
					modAscii();
					cout << "You have reach the end,return to last page...\n";
					system("pause");
					currResult = currResult - 5;
				}
				recOnPage = 0;
				modAscii();
				cout << "Entry(s) found with selected criteria: \n";

			}
			else if (query == "p" || query == "P") {
				if (currResult <= 5) {
					modAscii();
					cout << "There are no preveous page avalible, please re-enter your action.\n";
					system("pause");
					currResult = 0;
					recOnPage = 0;
					modAscii();
					cout << "Entry(s) found with selected criteria: \n";

				}
				else if (currResult >= totalResult) {
					currResult = currResult - ((currResult%5)+5);
					recOnPage = 0;
					modAscii();
					cout << "Entry(s) found with selected criteria: \n";
				}else {
					currResult = currResult - 10;
					recOnPage = 0;
					modAscii();
					cout << "Entry(s) found with selected criteria: \n";

				}
			}
			else {
				//TODO logic for moding stuff
				break;
			}
		}
	} while (currResult <= totalResult);

	breakLine();
}
void delRec() {
	delAscii();
	bool errFlag;
	string selection;
	int criteria;
	string query;
	string colName[15] = { "Title","Surname","Given Name","Gender","Birthday","StreetAddress","City","State","ZipCode","Country","Country Code","Telephone Number","Email","Occupation","Company" };
	string demo[15] = { "Mr.","Trump","Donald","Male","1999-9-9","2994 Arbor Court","Mountain View","Washington","99999","United States","2","99999999","donaldtrump@world.com","President","Trump Co." };
	cout << "Filter content using: \n";
	for (int i = 0; i < sizeof(colName) / sizeof(colName[0]); i++) {
		cout << i + 1 << ". " << colName[i] << endl;

	}
	breakLine();
	cout << "Select the column you would like to use to filter out record: ";
	cin >> criteria;
	delAscii();
	cout << "The column you have chosen to filter by are: " << colName[criteria - 1] << endl;
	cout << "Please enter the keywords to be filter on: ";
	cin >> query;

	int totalResult = 7;
	int currResult = 0;
	int recOnPage = 0;
	delAscii();
	cout << "Entry(s) found with selected criteria: \n";
	do {
		if (recOnPage != 5 && currResult < totalResult) {
			//&&currResult<totalResult
			cout << "Index: " << currResult + 1 << endl;
			cout << "1. Full Name : " << demo[0] << " " << demo[2] << " " << demo[1] << endl;
			//cout << "2. Gender : " << demo[3] << endl;
			//cout << "3. Birthday : " << demo[4] << endl;
			//cout << "4. Full Address : " << demo[5] << "," << demo[6] << "," << demo[7] << "," << demo[9] << endl;
			//cout << "5. ZipCode : " << demo[8] << endl;
			//cout << "6. Telephone Number : " << "(" << demo[10] << ") " << demo[11] << endl;
			//cout << "7. Email : " << demo[12] << endl;
			cout << "2. Occupation : " << demo[13] << " at " << demo[14] << endl;
			breakLine();
			currResult++;
			recOnPage++;
		}
		else {
			cout << "Input 'n' to go to next page,Input 'p' to go to preveous page \n";
			cout << "Input the Index to select that record to delete\n";
			cout << "Input Your Choice: ";
			cin >> query;
			if (query == "n" || query == "N") {
				if (currResult == totalResult) {
					modAscii();
					cout << "You have reach the end,return to last page...\n";
					system("pause");
					currResult = currResult - 5;
				}
				recOnPage = 0;
				delAscii();
				cout << "Entry(s) found with selected criteria: \n";

			}
			else if (query == "p" || query == "P") {
				if (currResult <= 5) {
					modAscii();
					cout << "There are no preveous page avalible, please re-enter your action.\n";
					system("pause");
					currResult = 0;
					recOnPage = 0;
					delAscii();
					cout << "Entry(s) found with selected criteria: \n";

				}
				else if (currResult >= totalResult) {
					currResult = currResult - ((currResult % 5) + 5);
					recOnPage = 0;
					delAscii();
					cout << "Entry(s) found with selected criteria: \n";
				}
				else {
					currResult = currResult - 10;
					recOnPage = 0;
					delAscii();
					cout << "Entry(s) found with selected criteria: \n";

				}
			}
			else {
				do {
					errFlag = true;
					delAscii();
					cout << "Current Data: \n";
					cout << "1. Title : " << demo[0] << endl;
					cout << "2. Surname : " << demo[1] << endl;
					cout << "3. GivenName : " << demo[2] << endl;
					cout << "4. DateOfBirth : " << demo[3] << endl;
					cout << "5. Address : " << demo[4] << endl;
					cout << "6. Phone No. : " << demo[5] << endl;
					cout << "7. Email : " << demo[6] << endl;
					cout << "8. Occupation : " << demo[7] << endl;
					cout << "9. Company : " << demo[8] << endl;
					breakLine();
					cout << "Are you sure you need to delete this record?(Y/N) ";
					cin >> selection;
					if (toLower(selection) == "y") {
						cout << "Type DELETE if you confirm the removal of this record ";
						cin >> selection;
						if (toLower(selection) == "delete") {
							delAscii();
							cout << "Delete Complete\n";
							//TODO delete algorithm
						}
						else {
							errFlag = false;
						}
					}
					else if (toLower(selection) == "n") {
						delAscii();
						cout << "returning to Homepage...\n";
					}
					else {
						errFlag = false;
					}
				} while (errFlag == false);
				break;
			}
		}
	} while (currResult <= totalResult);


}
void insertMultiple() {
	insAscii();
	int count = 0;
	string colName[15] = { "Title","Surname","Given Name","Gender","Birthday","StreetAddress","City","State","ZipCode","Country","Country Code","Telephone Number","Email","Occupation","Company" };
	string insertData[15];
	int option;
	cout << "1. Insert multiple data" << endl;
	cout << "2. Insert textfile" << endl;
	cin.ignore();
	cin >> option;

	if (option == 1) {
		system("CLS");
		insAscii();
		cout << "How many data you want to insert? ";
		cin >> count;
		insAscii();
		for (int j = 0; j < count; j++) {
			cout << "Data inserted currently: " << j << endl;
			for (int i = 0; i < 15; i++) {
				cout << i + 1 << ". " << colName[i] << " ";
				cin.ignore();
				getline(cin, insertData[i]);
			}
			//TODO insert Data Algorithm
			cout << "Data inserted\n";
			system("pause");
			insAscii();
		}
		cout << "All data has been inserted, return to main menu\n";
	}
	else if (option == 2) {
		insertTextFile();
	}
}
void insertSingle() {
	int colPtr;
	string colName[15] = { "Title","Surname","Given Name","Gender","Birthday","StreetAddress","City","State","ZipCode","Country","Country Code","Telephone Number","Email","Occupation","Company" };
	string insertData[15];
	do {
		insAscii();
		for (int i = 0; i < 15; i++) {
			cout << i + 1 << ". " << colName[i] << ": " << insertData[i] << endl;
		}
		breakLine();
		cout << "insert column as the format as [(index)(space)(data)] (e.g. 1 Mr. to insert Mr. to title)\n";
		cout << "type 0 to save the record, type 999 to discard the change\n";
		cin >> colPtr;
		if (cin.fail()) {
			cout << "Invalid Input,please re-enter \n";
			system("pause");
			cin.clear();
			cin.sync();
			cin.ignore();
			continue;
		}
		if (colPtr == 999) {
			break;
		}
		else if (colPtr == 0) {
			//TODO insert Algo
			break;
		}
		else {
			getline(cin,insertData[colPtr - 1]);
		}
	} while (true);
}
void search() {
	searchAscii();
	int selection;
	string query;
	string demo[15] = { "Mr.","Trump","Donald","Male","1999-9-9","2994 Arbor Court","Mountain View","Washington","99999","United States","2","99999999","donaldtrump@world.com","President","Trump Co." };
	string colName[15] = { "Title","Surname","Given Name","Gender","Birthday","StreetAddress","City","State","ZipCode","Country","Country Code","Telephone Number","Email","Occupation","Company" };
	cout << "Filter content using: \n";
	for (int i = 0; i < sizeof(colName) / sizeof(colName[0]); i++) {
		cout << i + 1 << ". " << colName[i] << endl;

	}
	breakLine();
	cout << "Select the column you would like to use to filter out record: ";
	cin >> selection;
	searchAscii();
	cout << "The column you have chosen to filter by are: " << colName[selection - 1] << endl;
	cout << "Please enter the keywords to be filter on: ";
	cin.ignore();
	getline(cin, query);

	int totalResult = 12;
	int currResult = 0;
	int recOnPage = 0;
	searchAscii();
	cout << "Entry(s) found with selected criteria: \n";
	do {
		if (recOnPage != 5 && currResult < totalResult) {
			//&&currResult<totalResult
			cout << "Index: " << currResult + 1 << endl;
			cout << "1. Full Name : " << demo[0] << " " << demo[2] << " " << demo[1] << endl;
			//cout << "2. Gender : " << demo[3] << endl;
			//cout << "3. Birthday : " << demo[4] << endl;
			//cout << "4. Full Address : " << demo[5] << "," << demo[6] << "," << demo[7] << "," << demo[9] << endl;
			//cout << "5. ZipCode : " << demo[8] << endl;
			//cout << "6. Telephone Number : " << "(" << demo[10] << ") " << demo[11] << endl;
			//cout << "7. Email : " << demo[12] << endl;
			cout << "2. Occupation : " << demo[13] << " at " << demo[14] << endl;
			breakLine();
			currResult++;
			recOnPage++;
		}
		else {
			cout << "Input 'n' to go to next page,Input 'p' to go to preveous page \n";
			cout << "Input the Index to select that record to view the details\n";
			cout << "Input Your Choice: ";
			cin >> query;
			if (query == "n" || query == "N") {
				if (currResult == totalResult) {
					searchAscii();
					cout << "You have reach the end,return to last page...\n";
					system("pause");

					currResult = currResult - (currResult % 5);
				}
				recOnPage = 0;
				searchAscii();
				cout << "Entry(s) found with selected criteria: \n";

			}
			else if (query == "p" || query == "P") {
				if (currResult <= 5) {
					searchAscii();
					cout << "There are no preveous page avalible, please re-enter your action.\n";
					system("pause");
					currResult = 0;
					recOnPage = 0;
					searchAscii();
					cout << "Entry(s) found with selected criteria: \n";

				}
				else if (currResult >= totalResult) {
					currResult = currResult - ((currResult % 5) + 5);
					recOnPage = 0;
					searchAscii();
					cout << "Entry(s) found with selected criteria: \n";
				}
				else {
					currResult = currResult - 10;
					recOnPage = 0;
					searchAscii();
					cout << "Entry(s) found with selected criteria: \n";

				}
			}
			else {
				//TODO logic for view full details
				break;
			}
		}
	} while (currResult <= totalResult);
}
void printRec() {
	int recOnPage=0;
	int currResult = 0;
	int totalResult = 78;
	string query;
	printAscii();
	string demo[15] = { "Mr.","Trump","Donald","Male","1999-9-9","2994 Arbor Court","Mountain View","Washington","99999","United States","2","99999999","donaldtrump@world.com","President","Trump Co." };
	string colName[15] = { "Title","Surname","Given Name","Gender","Birthday","StreetAddress","City","State","ZipCode","Country","Country Code","Telephone Number","Email","Occupation","Company" };
	do {
		if (recOnPage != 5 && currResult < totalResult) {
			//&&currResult<totalResult
			cout << "Index: " << currResult + 1 << endl;
			cout << "1. Full Name : " << demo[0] << " " << demo[2] << " " << demo[1] << endl;
			//cout << "2. Gender : " << demo[3] << endl;
			//cout << "3. Birthday : " << demo[4] << endl;
			//cout << "4. Full Address : " << demo[5] << "," << demo[6] << "," << demo[7] << "," << demo[9] << endl;
			//cout << "5. ZipCode : " << demo[8] << endl;
			//cout << "6. Telephone Number : " << "(" << demo[10] << ") " << demo[11] << endl;
			//cout << "7. Email : " << demo[12] << endl;
			cout << "2. Occupation : " << demo[13] << " at " << demo[14] << endl;
			breakLine();
			currResult++;
			recOnPage++;
		}
		else {
			cout << "Input 'n' to go to next page,Input 'p' to go to preveous page \n";
			cout << "Input the Index to select that record to view the details\n";
			cout << "Input Your Choice: ";
			cin >> query;
			if (query == "n" || query == "N") {
				if (currResult == totalResult) {
					printAscii();
					cout << "You have reach the end,return to last page...\n";
					system("pause");

					currResult = currResult - (currResult % 5);
				}
				recOnPage = 0;
				printAscii();
				cout << "Entry(s) found with selected criteria: \n";

			}
			else if (query == "p" || query == "P") {
				if (currResult <= 5) {
					printAscii();
					cout << "There are no preveous page avalible, please re-enter your action.\n";
					system("pause");
					currResult = 0;
					recOnPage = 0;
					printAscii();
					cout << "Entry(s) found with selected criteria: \n";

				}
				else if (currResult >= totalResult) {
					currResult = currResult - ((currResult % 5) + 5);
					recOnPage = 0;
					printAscii();
					cout << "Entry(s) found with selected criteria: \n";
				}
				else {
					currResult = currResult - 10;
					recOnPage = 0;
					printAscii();
					cout << "Entry(s) found with selected criteria: \n";

				}
			}
			else {
				//TODO view full details
				break;
			}
		}
	} while (currResult <= totalResult);
}
void insertTextFile() {

	system("CLS");
	insAscii();
	cout << "If you change your mind, you can type 999 to exit to main menu!" << endl;
	string tempString = "";
	string fileName;
	cout << "Please enter the file name: ";
	cin >> fileName;
	ifstream inputFile(fileName);
	// Prompt user again if wrong filename received
	if (fileName == "999") {
		return;
	}
	while (!inputFile.good()) {
		cout << "Wrong file name, input again please: ";
		cin >> fileName;
		inputFile.open(fileName);
		
		if (fileName == "999") {
			return;
		}
	}

	// Append all lines from the file into a long string
	while (!inputFile.eof()) {
		string str, str2;
		getline(inputFile, str);
		istringstream iss(str);
		while (!iss.eof()) {
			getline(iss, str2, '\t');
			cout << str2 << "\t";

		}

	}
}