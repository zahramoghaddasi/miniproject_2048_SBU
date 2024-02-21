#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<bits/stdc++.h>
#include<string>
#include<windows.h> 
using namespace std;

int adad(int valu) {
	int e = 0;
	while (valu){
		valu /= 10;
		e++;
	}
	if (e == 0)
		e++;
	return e;
}

struct Leaderboard {
		
		string name;
		int score;
	};

int number_Of_win;
bool payan = false;
bool win = false;
int space[4][4];
int g;
//payan the game
int score = 0;
//score the game
Leaderboard player[100];
int gamer = 0;
//the number of player

void Print();	
void Random();
void Stuckgame();
void Wingame();
void Taaviz ();
void Gametime();
void Menu();
	
int main(){
	srand(time(0));
	Menu () ;
}

void Random () {
	int matrix[4] = {2,2,2,4};
	srand(time(0));
	while (1) {
	int i = rand() % 4;
	int j = rand() % 4;
	if (space[i][j] == 0) {
		space[i][j] = matrix[rand() % 4];
		break;
	}
}
}

void Stuckgame()
{
	if (payan) {
		system("cls");
		return;
	}
	system("cls");
	player[gamer].score = score;
	int counter = gamer - 1;
	while (counter >= 1 && player[counter].score < player[counter + 1].score) {
		swap(player[counter], player[counter + 1]);
		counter--;
	}
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hConsole, 47);
    	//47 rang banafsh
	cout << "Oops!you lost the game -_- " <<endl << "your score:" << score << endl;
	cout << "if you want menu please Enter m";
	char key = getch();
	while (key != 'm')
		key = getch();
	Menu ();
}

void Wingame () {
	
	bool k = false;
	for (int i = 0 ; i < 4 ; i++){
		for (int j = 0 ; j < 4 ; j++){
			if (space[i][j] == number_Of_win) {
				k=true;
			}
		}
	}
	if (k == true){
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		SetConsoleTextAttribute(hConsole, 14);
    		//14 rang firouzehi
		cout << "Great!you won*-*";
		int n;
		cin >> n;
		system ("cls");
		Menu () ;
	}
	else {
		Random () ;
	}
}


void uparrow(){
	for(int j = 0 ; j < 4 ; j++){
		for(int i = 0 ; i < 4 ; i++){
			if(space[i][j] == 0){
				continue;
			}	
				else{
					for(int k = (i+1) ; k < 4 ; k++){
						if(space[k][j] == 0){
							continue; 
						}
						else{
							if(space[k][j] == space[i][j]){
								space[i][j] *= 2;
								space[k][j] = 0;
								score += space[i][j]; 
						   }
								break;
						}
					}
				}
		}
	}
		for(int j = 0 ; j < 4 ; j++){
			for( int m = 0 ; m < 3 ; m++){
				for(int i = 0 ; i < 3 ; i++){
					if(space[i][j] == 0){
						swap(space[i][j] , space[i+1][j]); 
			     	}	
				}
			}
		}
}

void downarrow(){
	for(int j = 0 ; j < 4 ; j++){
		for(int i = 3 ; i >= 0 ; i--){
			if(space[i][j] == 0){
				continue;
			 }	
			else{
				for(int k = (i-1) ; k >= 0 ; k--){
					if(space[k][j] == 0){
						continue; 
					}	
					else{
						if(space[i][j] == space[k][j]){
							space[i][j] *= 2;
							space[k][j] = 0;
							score += space[i][j];
						}
						break;
					}
				}
			}
		}
	}
		
		for(int j = 0 ; j <= 3 ; j++){
			for(int m = 0 ; m < 3 ; m++){
				for(int i = 3 ; i > 0 ; i--){
					if(space[i][j] == 0){
						swap(space[i][j] , space[i-1][j]); 
				    }	
				}
			}
		}	
}

void leftarrow(){
	for(int i = 0 ; i <= 3 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			if(space[i][j] == 0){
				continue;	
			}
			else{
				for(int k = (j+1) ; k < 4 ; k++){
					if(space[i][k] == 0){
						continue;
					}
					else{
						if(space[i][j] == space[i][k]){
							space[i][j] *= 2;
							space[i][k] = 0;
							score += space[i][j];
						 }
						break;
					}
				}
			}
		}
	}
	for(int i = 0 ; i <= 3 ; i++){
			for(int m = 0 ; m < 3 ; m++){
				for(int j = 0 ; j < 3 ; j++){
				if(space[i][j] == 0){
					swap(space[i][j] , space[i][j+1]); 
				}	
			}
		}
	}
}

void rightarrow(){
	for(int i = 0 ; i < 4 ; i++){
			for(int j = 3 ; j >= 0 ; j--){
				if(space[i][j] == 0){
					continue; }
				else{
					for(int k = (j-1) ; k >= 0 ; k--){
						if(space[i][k] == 0){
							continue; 
						}	
						else{
							if(space[i][j] == space[i][k]){
								space[i][j] *= 2;
								space[i][k] = 0;
								score += space[i][j];
							}
							break;
						}
					}
				}
			}
		}
		for(int i = 0 ; i <= 3 ; i++){
			for(int m = 0 ; m < 3 ; m++){
				for(int j = 2 ; j >= 0 ; j--){
					if(space[i][j+1] == 0){
						swap(space[i][j] , space[i][j+1]); 
					}	
				}
			}
		}
}

void move(){
	char keyboard = getch();
	
	if(keyboard == 119 || 87 || 72)
	uparrow();
	//119 = w . 87 = W . 72 = upshift
	
	if(keyboard == 83 || 115 ||80)
	downarrow();
	// 83 = S . 115 = s . 80 = downshift
	if(keyboard == 97 || 65 || 75)
	leftarrow();
	// 97 = a . 65 = A . 75 = leftshift
	if(keyboard == 68 || 100 || 77)
	rightarrow();
	// 68 = D . 100 = d . 77 = rightshift
}

void Taaviz () {
	if (payan) {
		system("cls");
		return;
	}
	bool T = false;
		for (int j=0 ; j<4 ; j++) {
			for (int i=0 ; i<4 ; i++) {
				if (space[i][j] == 0)
					T = true;
				else {
					if (i < 3 && space[i][j] == space[i + 1][j])
						T = true;
					if (j < 3 && space[i][j] == space[i][j + 1])
						T = true;
				}
			}
		}
		if (T == false) {
			Stuckgame();
		}
		else {
	      move();
	    }
}
	    

void Gametime() {
	if (payan) {
		system("cls");
		return;
	}
	for (int i=0 ; i<4 ; i++) {
		for (int j=0 ; j<4 ; j++) {
			space[i][j] = 0;
		}
	}
	
	int array[4] = {2,2,2,4};
	srand(time(0));
	int count = 1;
	while (count < 3) {
	int z = rand() % 4;
	int h = rand() % 4;
	if (space[z][h] == 0){
		space[z][h] = array[rand() % 4];
		count++;
	}
	}
	Print();

	while (g == 0) {
	char key = getch();
	Taaviz ();
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (space[i][j] == 0)
				cnt++;
	if (cnt > 0)
		Random();
	system("cls");
	Print();

	}
}

void Menu() {
	system("cls");
	if (payan) {
		return ;
	}
	Leaderboard leaderboard;
	leaderboard.score = score;
	cout <<"    *welcome to 2048*    " << endl;
	cout << "1)New Game" << endl;
	cout << "2)Leaderboard" << endl;
	cout << "3)Exit" << endl;
	system("color 0D");
	char number = getch();
	
	if (number == '1'){
		gamer++;
		system("cls");
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		SetConsoleTextAttribute(hConsole, 15);
    		// 15 = light white
		cout << "Enter your name:" << endl;
		getline (cin , player[gamer].name);
		system("cls");
		Gametime ();
	}
	if (number == '2'){
		system("cls");
		for (int i = gamer; i >= 1; i--){
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		SetConsoleTextAttribute(hConsole, 3);
    		//3 = rang AQUA
			cout << "name : " << player[i].name << "  " << "score : " << player[i].score << endl;
		}
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hConsole, 11);
    	//11 = rang light AQUA
		cout << "if you want menu please Enter m";
		char c = getch();
		while (c != 109)
		//109 = ascii code m
			c = getch();
		Menu ();
	}
	if (number == '3'){
		payan = true;
	}
}


void Print(){
	cout << '\n';
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << "\n\n";
 
	cout << " \u2503  ";
	if(space[0][0] == 0){
		cout <<" ";
	}
	else
	cout << space[0][0];
	for (int i = 1; i <= (4 - adad(space[0][0])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[0][1] == 0){
		cout << " ";
	}
	else
	cout << space[0][1];
	for (int i = 1; i <= (4 - adad(space[0][1])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[0][2] == 0){
		cout << " ";
	}
	else
	cout << space[0][2];
	for (int i = 1; i <= (4 - adad(space[0][2])); i++)
		cout << ' ';
	cout << "\u2503 ";
	cout << " \u2503 ";
	if(space[0][3] == 0){
		cout << " ";
	}
	else
	cout << space[0][3];
	for (int i = 1; i <= (4 - adad(space[0][3])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << "\n\n";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << "\n\n";
 
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << "\n\n";
 
	cout << " \u2503  ";
	if(space[1][0] == 0){
		cout << " ";
	}
	else
	cout << space[1][0];
	for (int i = 1; i <= (4 - adad(space[1][0])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[1][1] == 0){
		cout << " ";
	}
	cout << space[1][1];
	for (int i = 1; i <= (4 - adad(space[1][1])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[1][2] == 0){
		cout << " ";
	}
	else
	cout << space[1][2];
	for (int i = 1; i <= (4 - adad(space[1][2])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[1][3] == 0){
		cout << " ";
	}
	else
	cout << space[1][3];
	for (int i = 1; i <= (4 - adad(space[1][3])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << "\n\n";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << "\n\n";
 
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << "\n\n";
 
	cout << " \u2503 ";
	if(space[2][0] == 0){
		cout << " ";
	}
	else
	cout << space[2][0];
	for (int i = 1; i <= (4 - adad(space[2][0])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[2][1] == 0){
		cout << " ";
	}
	else
	cout << space[2][1];
	for (int i = 1; i <= (4 - adad(space[2][1])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[2][2] == 0){
		cout << " ";
	}
	else
	cout << space[2][2];
	for (int i = 1; i <= (4 - adad(space[2][2])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[2][3] == 0){
		cout << " ";
	}
	else
	cout << space[2][3];
	for (int i = 1; i <= (4 - adad(space[2][3])); i++)
		cout << ' ';
	cout << "\u2503  ";
		cout << "\n\n";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << "\n\n";

 
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
	cout << "\n\n";
 
	cout << " \u2503 ";
	if(space[3][0] == 0){
		cout << " ";
	}
	else
	cout << space[3][0];
	for (int i = 1; i <= (4 - adad(space[4][0])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[3][1] == 0){
		cout << " ";
	}
	else
	cout << space[3][1];
	for (int i = 1; i <= (4 - adad(space[3][1])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[3][2] == 0){
		cout << " ";
	}
	else
	cout << space[3][2];
	for (int i = 1; i <= (4 - adad(space[3][2])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << " \u2503  ";
	if(space[3][3] == 0){
		cout << " ";
	}
	else
	cout << space[3][3];
	for (int i = 1; i <= (4 - adad(space[3][3])); i++)
		cout << ' ';
	cout << "\u2503  ";
	cout << "\n\n";
	
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
	cout << "\n\n";

}