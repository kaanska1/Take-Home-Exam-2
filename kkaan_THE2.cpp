#include <iostream>
#include <string>
#include "strutils.h"

using namespace std; 

// Functions part
bool isAlpha(string input){
		for (int i = 0; i < input.size(); i++)
	{
		int lowercaseversion = tolower(input[i]); 
		if (lowercaseversion < 'a' || lowercaseversion > 'z') 
		{
			return false;
		}
	}
	
	return true; 

}

bool checktrial(string trials,string& guess2){

	if (trials.find(guess2)==string::npos){
		return false;
	}
	else{
		return true;
	}

}

string hidemessage(string input){
	
	for (int i=0;i<input.length();i++){
		input.at(i)='-';
	}
	return input;
}

void counter(int& counter,string name2){
	if (counter==1){
	cout<<"You have no free guess left."<<endl;
	}

	else if (counter==2){
	cout<<"You have lost a leg!"<<endl;
	}

	else if (counter==3){
	cout<<"You have lost a leg!"<<endl;
	}

	else if (counter==4){
	cout<<"You have lost an arm!"<<endl;
	}

	else if (counter==5){
	cout<<"You have lost an arm!"<<endl;
	}

	else if (counter==6){
	cout<<"You have lost a head! GAME OVER!"<<endl;
	cout<<name2<<" lost the game :(";
	}

}

int main(){

	int inputcheck;
	string name1,name2,input,hiddenversion;
	string trials="";
	string inputnew;
	bool guesscheck;
	


	cout<<"Welcome to the HANGMAN GAME"<<endl;
	cout<<"---------------------------"<<endl;

	cout<<"Player one, please enter your name: ";
	cin>>name1;
	cout<<"Player two, please enter your name: ";
	cin>>name2;

	cout<<"OK "<<name1<<" and "<<name2<<". Let's start the game!"<<endl;;
	
	cout<<name1<<", please input the word you want "<<name2<<" to guess: ";
	cin>>input;

	ToLower(input);

	//Alphabetic control 
	while (isAlpha(input)==false)
	{
		cout << "Invalid word! Try again." << endl;
		cout<<name1<<", please input the word you want "<<name2<<" to guess: ";
		cin>>input;
	}

	//Hiding message
	hiddenversion=hidemessage(input);
	//cout<<hiddenversion<<endl;
	
	cout<<name2<<", you have 1 free guess, after that you will lose limbs!"<<endl;;
	cout<<"The word is: "<<hiddenversion<<endl;


	string choice;
	string guess1;
	string guess2;
	
	int count=0;
	
	while(hiddenversion!=input){
	cout<<name2<<", do you want to guess the word(1) or guess a letter(2)? ";
	cin>>choice;
	
	

	if (choice=="1"){
		cout<<"Your guess: ";
		cin>>guess1;

		ToLower(guess1);
		
		if (isAlpha(guess1)==true){
			if (guess1==input){
				cout<<"The word is: "<<input<<endl;
				cout<<"Congratulations "<<name2<<", you won!"<<endl;
				cout<<name2<<" won the game!";
				hiddenversion==input;
				break;
			}
			else {
			count= count+1;
			counter(count,name2);
				if(count==6){
					return 0;
				}
			cout<<"The word is: "<<hiddenversion<<endl;
			}
		}
		else{
		cout<<"Invalid entry! Try again."<<endl;
		cout<<"The word is: "<<hiddenversion<<endl;
		}
	}
	
	else if(choice=="2"){
		cout<<"Your guess: ";
		cin>>guess2;
		ToLower(guess2);

		if (isAlpha(guess2)==true&&guess2.length()==1){
			

		guesscheck=checktrial(trials,guess2);
			if (guesscheck==true){
				cout<<"Guess entered before! Try again."<<endl;
				cout<<"The word is: "<<hiddenversion<<endl;
				
			}
			trials=(trials+guess2);

			if(input.find(guess2)!=string::npos){
				for (int k=0;k<input.length();k++){
					if(guess2.at(0) == input.at(k)){
						hiddenversion.at(k)=guess2.at(0);
							
					}
				}
				cout<<"The word is: "<<hiddenversion<<endl;
				if (hiddenversion==input){
					cout<<"Congratulations "<<name2<<", you won!"<<endl;
					cout<<name2<<" won the game!";
					return 0;
				}
			}
			else if(input.find(guess2)==string::npos && guesscheck==false){
			count= count+1;
			counter(count,name2);
			if(count!=6){
				cout<<"The word is: "<<hiddenversion<<endl;
			}
				if(count==6){
					break;
				}
			}
			
		}
		else{
		cout<<"Invalid entry! Try again."<<endl;
		cout<<"The word is: "<<hiddenversion<<endl;
		}


	
	
	
	
	
	}//else if iþareti
	else{
		cout<<"Invalid option!"<<endl;
		cout<<"The word is: "<<hiddenversion<<endl;
	}
	
	
}//while iþareti 



return 0;
}