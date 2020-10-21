#include <iostream>
#include <Windows.h>
#define QA_NUM 3

using namespace std;

int length(char* buffer) {
	int i = 0;
	while (true) {
		if (buffer[i] == '\00')
			return i;
		i++;
	}
}
void getLine(char* buffer, bool frcint) {
	ZeroMemory(buffer, 128);
	fflush(stdin);
	int i = 0;
	while (true) {
		char x = char(getchar());
		if (x == '\n' || i >= 127)
			break;
		buffer[i] = x;
		i++;

	}
	buffer[i] = 0;
	bool invaild = false;
	if (length(buffer) == 0) {
		cout << "Answer cannot be blank! : ";
		invaild = true;
	}
	else if (frcint == true) {

		if (length(buffer) != 1) {
			cout << "Enter ONLY the number of your answer! : ";
			invaild = true;
		}
		else if (!(buffer[0] >= '1' && buffer[0] <= '4')) {
			cout << "Pick from the answers above! : ";
			invaild = true;
		}
	}
	if (invaild)
		getLine(buffer, frcint);
}

char Qu[][2048] = {
"Ola and Amr .... studied C++ \n 1.had \n 2.is \n 3.was \n 4.should \n ",
"Take these pills. They will ... your pain at once \n 1.please \n 2.ease \n 3.tease \n 4.pease \n",
"She ... for a job at the new project \n 1.worked \n 2.employed \n 3.applied \n 4.wanted \n",
"Oh! I ... my mobile, What can I do? \n 1.broke \n 2.had broken \n 3.was breaking \n 4.have broken \n"
};
char Ans[] = { '1','2','3','4' };

/*char getint() {
	int chr = getchar();

	if (chr >= 49 && chr <= 53)
		return char(chr);

	if (chr == 0x0a || !(chr >= 49 && chr <= 53))
		cout << "Please enter ONLY the number of your answer: ";
	return getint();
}*/


int main()
{
	char name[128];
	char id[128];
	char buffer[128];
	int counter = 0;

	cout << "-----------------------------------";
	cout << "|Welcome to your first online exam|";
	cout << "-----------------------------------" << endl;
	cout << "Please enter your name: ";

	getLine(name, false);
	name[0] = toupper(name[0]);

	cout << "Welcome " << name << ", Please enter your ID: ";
	getLine(id, false);


	cout << "Welcome to your english exam." << endl;
	cout << "Please Choose the correct answer" << endl;


	for (int i = 0; i <= QA_NUM; i++) {
		cout << Qu[i] << "Your answer: ";

		getLine(buffer, true);
		if (buffer[0] == Ans[i]) {

			counter++;
		}

	}


	if ((counter / QA_NUM) * 100 < 0.5)
		cout << "You failed :(" << endl;
	else
		cout << "Congrats you got " << (counter / QA_NUM) * 100 << "%" << endl;

	cout << "Thanks for Trying OwO" << endl;



	system("pause");
}



