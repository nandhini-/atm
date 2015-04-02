#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>

void Menu();
void Deposit();
void Withdraw();
void Balance();
void clr(){cout<<"\n\n\n\n\n"<<endl;}


int main(){

	int code = 1941;

	cout<<"\t\t\tWelcome to City Bank"<<endl;
	cout<<"\t\t\t=================="<<endl;


	cout<<"\n\t\tEnter your code: ";
	cin>>code;

	if(code == 1941){Menu();}

	return 0;
}

void Menu(){

	int select = 0;

	clr();
	cout<<"\t\t\tBank Menu"<<endl;
	cout<<"\t\t\t========="<<endl;

	cout<<"\n\n\t1) Make a Deposit"<<endl;
	cout<<"\n\t2) Make a Withdrawal"<<endl;
	cout<<"\n\t3) Check your Balance"<<endl;
	cout<<"\n\t0) Quit"<<endl;

	cout<<"\n\n\tEnter your selection: ";
	cin>>select;


	if(select == 1){Deposit();}else{
		if(select == 2){Withdraw();}else{
			if(select == 3){Balance();}else{exit(0);}}}

}

void Deposit(){

	float damt;
	float bal;

	clr();
	cout<<"\t\t\tDeposit"<<endl;
	cout<<"\t\t\t======="<<endl;

	cout<<"\n\n\tEnter an amount: $";
	cin>>damt;

	ifstream getinfo("acct.txt");
	getinfo>>bal;
	getinfo.close();

	if(bal < 0){bal = 0;}

	bal = bal + damt;

	ofstream putinfo("acct.txt");//add bal to the file
	putinfo<<bal;
	putinfo.close();


	cout<<"\n\tAmount deposited: $"<<damt<<endl;
	cout<<"\n\tYour balance is now: $"<<bal<<endl;
	cout<<"\n\n\tPress any key to continue..."<<endl;

	getchar();//this allows you to pause at the line above.
	Menu();
}


void Withdraw(){//opens with acct.txt file and subtracts from it

	float wamt;
	float bal;

	clr();
	cout<<"\t\t\tWithdrawal"<<endl;
	cout<<"\t\t\t=========="<<endl;

	cout<<"\n\n\tEnter an amount: $";
	cin>>wamt;

	ifstream getinfo("acct.txt");
	getinfo>>bal;
	getinfo.close();

	if(bal < 0){bal = 0;}

	bal = bal - wamt;

	if(bal > 0){
	ofstream putinfo("acct.txt");
	putinfo<<bal;
	putinfo.close();
	}

	cout<<"\n\tAmount withdrewed: $"<<wamt<<endl;
	if(bal > 0){
		cout<<"\n\tYour balance is now: $"<<bal<<endl;
	}else{
		cout<<"\n\tI'm sorry but your account cannot be minus: $"<<bal<<endl;
	}

	cout<<"\n\n\tPress any key to continue..."<<endl;

	getchar();
	Menu();
}


void Balance(){

	float bal;

	ifstream gbal("acct.txt");
	gbal>>bal;
	gbal.close();

	if(bal < 0){bal = 0;}

	clr();
	cout<<"\t\t\tBalance"<<endl;
	cout<<"\t\t\t======="<<endl;

	cout<<"\n\n\tYour balance is: $"<<bal<<endl;
	cout<<"\n\n\tPress any key to continue.."<<endl;

	getchar();
	Menu();
}





