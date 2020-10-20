#include <iostream>
#define QA_NUM 3

using namespace std;

char Qu[][2048] = {
"Ola and Amr .... studied C++ \n 1.had \n 2.is \n 3.was \n 4.should \n",
"Take these pills. They will ... your pain at once \n 1.please \n 2.ease \n 3.tease \n 4.pease \n",
"She ... for a job at the new project \n 1.worked \n 2.employed \n 3.applied \n 4.wanted ",
"Oh! I ... my mobile, What can I do? \n 1.broke \n 2.had broken \n 3.was breaking \n 4.have broken \n"
};
char Ans[] = { '1','2','3','4'};

char getint() {
	int chr = getchar();

	if (chr >= 49 && chr <= 53)
		return char(chr);

	if (chr == 0x0a || !(chr >= 49 && chr <= 53))
		cout << "Please enter ONLY the number of your answer: ";
	return getint();
}


int main()
{
	string name = "Default User";
	int counter = 0; 
	int id      = 0;

	cout << "-----------------------------------";
	cout << "|Welcome to your first online exam|";
	cout << "-----------------------------------" << endl;
	cout << "Please enter your name: ";

	cin >> name;
	name[0] = toupper(name[0]);

	cout << "Welcome " << name << ", Please enter your ID: ";

	cin >> id;

	cout << "Welcome to your english exam." << endl;
	cout << "Please Choose the correct answer" << endl;
	
	for (int i = 0; i <= QA_NUM; i++) {
		cout << Qu[i];
		if (getint() == Ans[i]) {
			counter++;
		}
	}

	if ((counter /QA_NUM) * 100 < 0.5)
		cout << "You failed :(" << endl;
	else 
		cout << "Congrats you got " << (counter / QA_NUM) * 100 << "%" << endl;
	
	cout << "Thanks for Trying OwO" << endl;
		


 system("pause");
}

