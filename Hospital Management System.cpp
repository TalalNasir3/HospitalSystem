#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
using namespace std;

// a structure for the date 
void fullscreen(void)
{
	{
		keybd_event(VK_MENU,0x38,0,0);
		keybd_event(VK_RETURN,0x1c,0,0);
		keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
		keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);            
	}

}
struct Date
{
	private:	
	
		int Day, Month, Year;
		
	public:
		
		// set the date
		
		void set_date()
		{
			cout << "\n\nEnter the date (DD/MM/YY): ";
			cout << "\n\nDay: \t"; cin >> Day;
			cout << "\n\nMonth: \t"; cin >> Month;
			cout << "\n\nYear: \t"; cin >> Year;
		}
		
		// get the date 
		
		void get_date()
		{
			cout<<"\n\nDATE: \t"<<Day<<"/"<<Month<<"/"<<Year;
		}
};
// a structure for the time

struct Time
{
	private:
		
		int Hour, Min;

	public:
		
		// set the time
		
		void set_time()
		{
			cout<<"\n\nEnter the time (HR : MIN) : ";
			cout << "\n\nHour: \t"; cin >> Hour;
			cout << "\n\nMinute: \t"; cin >> Min;
		}
		
		// get the time
		
		void get_time()
		{	
			cout<<"\nTIME: \t"<<Hour<<":"<<Min;
		}
};

// a structure for date of birth

typedef struct DOB{
	
	private:
		
		int Day, Month, Year;
		
	public:
		
		// set the date of birth
		
		void set_dob()
		{
			cout << "\n\nEnter your date of birth (DD/MM/YY): ";
			cout << "\n\nDay: \t"; cin >> Day;
			cout << "\n\nMonth: \t"; cin >> Month;
			cout << "\n\nYear: \t"; cin >> Year;
		}
		
		// get the date of birth
		
		void get_dob()
		{
			cout<<"\n\nDOB\t\t: \t"<<Day<<"/"<<Month<<"/"<<Year;
		}
		
}dob;

class Staff
{	
	// attributes
	
	protected:
		
		char Name[30], Address[30], Mobile[10], Gender;
		
		int ID;
		
		dob Dob; // instantiation of struct DOB for date of birth
			
	// constructors and member functions
	
	public:
	
		// default constructor
		
		Staff() {}

		// methods for Staff
		
		void take_input(); // take input from the Staff members
		
		virtual void set_data()=0; // pure virtual function for the purpose of individual specialised initialisation
		
		virtual void get_data()
		{
			cout <<"\n\nID\t\t=\t"<< ID;
			cout <<"\n\nName\t\t=\t"<< Name;
			Dob.get_dob(); // date of birth
			cout <<"\n\nGender\t\t=\t"<<Gender; 
			cout <<"\n\nAddress\t\t=\t"<<Address;
			cout <<"\n\nMobile No:\t=\t"<<Mobile;
		}
		
		int get_ID(){	return ID;	}
		
		
};

void Staff :: take_input()
{
	cout<<"\n\n------------------------Employee Input Screen------------------------\n\n";
	cout<<"\tDear Employee,	\n\n";
	cout<<"Enter the following details:	\n\n";
	cout<<"Name: \t"; cin>>Name;		
	
	Dob.set_dob();
	
	cout <<"\n\nID\t\t=\t"; cin >>ID;
	cout <<"\n\nGender\t\t=\t"; cin >> Gender;
	cout <<"\n\nAddress\t\t=\t"; cin >> Address;
	cout <<"\n\nMobile No:\t=\t"; cin >> Mobile;
	
	
}

class Patient{
	
	
	public:
		
		string Name;
		int Age;
		char Gender;
		string Mobile;
		string Address;
		string Medicine[10];
		string Test;
		int Id;
	
	
		void showinfo(){
			
			cout<<"\nID\t:\t"<<Id<<"\nName\t:\t"<<Name<<"\nAge\t:\t"<<Age<<"\nGender\t:\t"<<Gender<<"\nMobile No\t:\t"<<Mobile<<"\nAddress\t:\t"<<Address;
		}	
};

class Operation{


	public:
	
		int ID;
		string Name;
		Date date;
		Time time;
	
		void operation_details(){
			
			cout<<"\nId="<<ID<<"\nName="<<Name;
			date.get_date();
			time.get_time();
		}
};

class Doctor:public Staff{



	private:


		string Speciality;
		string Qualification;
	
	
	public:
		
		
		void set_data(){
			
			Staff::take_input();
			cout<<"\n Enter Doctor's Qualification : ";
			cin>>Qualification;
			cout<<"\n Enter Speciallity : ";
			cin>>Speciality;
		}
		
		
		void get_data(){
			
			Staff::get_data();
			cout<<"\nQualification\t=\t"<<Qualification<<"\nSpeciallity\t=\t"<<Speciality;
		}
		
		
		void perscribe_medicine(Patient &p){
			
			int n=0;char ch='n';
			
			do{
				
				cout<<"\nPlease Enter Medicine name:";
				cin>>p.Medicine[n];
				cout<<"\nEnter 'y' to enter more : ";
			
			}while(ch=='y'||ch=='Y');
		
		}


		void perform_operation(Operation &o,Patient &p){
			
			o.ID=p.Id;
			o.Name=p.Name;
			o.date.get_date();
			o.time.get_time();
		}
			

		void perscribe_test(Patient &p){
			
			cout<<"\n Please Enter Test Name with code : ";
			cin>>p.Test;
		}	

};


class Receptionist:public Staff{
	
	
	protected:
		
		string Qualification;
	
	
	public:
	
		void set_data(){
		
			Staff::take_input();
			cout<<"\nEnter Qualification";
			cin>>Qualification;
		}
		
		
		void get_data(){
			Staff::get_data();
			cout<<"\nQualification\t=\t"<<Qualification;
		}
	
	
		void add_patient(Patient &p){
			cout<<"\n Please Enter Id : ";
			cin>>p.Id;
			cout<<"\n Enter Name : ";
			cin>>p.Name;
			cout<<"\n Enter age : ";
			cin>>p.Age;
			cout<<"\n Enter Gender M/F : \n";
			cin>>p.Gender;
			cout<<"\n Enter Mobile No : ";
			cin>>p.Mobile;
			cout<<"\n Enter Address : ";
			cin>>p.Address;	
		}
};


class Test{
	
	public:
		
		int Id;
		string Name;
		string report;
		float result;
		
};


class Labassistant:public Staff{
	
	
	public:
		
		
		Test t;
		
		void set_data(){
			Staff::take_input();
		}
		
		void get_data(){
			Staff::get_data();
		}
		
		void Collect_samples(Patient &p){
			t.Id=p.Id;
			t.Name=p.Name;
			cout<<"\n Test Title : "<<p.Test;
			cout<<"\n Enter Test Report review : ";
			cin>>t.report;
			cout<<"\n Enter result : ";
			cin>>t.result;
		}
		
		void Report_Generation(){
			cout<<"\nID="<<t.Id<<"\nName="<<t.Name;
			cout<<"\n Enter Test Report review : ";
			cin>>t.report;
			cout<<"\n Enter result : ";
			cin>>t.result;
		}
		
};



class Pharmasist:public Staff{


	public:
    
	
		void set_data(){
    		Staff::take_input();
		}
	
		void get_data(){
			Staff::get_data();
		}	 
	
	
	
		void View_Medicine(Patient &p){
		
			int i = 0;
			
			do{
				
				cout<<p.Medicine[i]<<endl;
				i++;
				
			}while(i<10);
		}
		
		
		
		void Medicine_bill(){
			
			int q,p;
			cout<<"\n Enter Quantity : ";cin>>q;
			cout<<"\n Enter Price : ";cin>>p;
			cout<<"\n Total Bill = "<<p*q;	
		}
};

class Admin
{
		// attributes
		
	    private:
	    	
	    	char admin_name[30], admin_username[30], admin_password[15];
	    	
	    	dob admin_dob; // an instatiation of the struct DOB for admin's dob
	    	
	    // constructors & member functions	
	    	
	    public:
	    	
	    	//default constructor
	    	
	    	Admin(){}
			
			//parametrized constructor
			
			Admin(char admin_name[], char admin_username[], char admin_password[])
			{	
				// copying the string from the argument data to the object's data
				
				strcpy(this->admin_name, admin_name);
				strcpy(this->admin_username, admin_username);
				strcpy(this->admin_password, admin_password);
			}
			
			// setters for the data, returning reference of objects for the purpose of chained function calling
				
			Admin& set_admin_name(char admin_name[]){	strcpy(this->admin_name, admin_name); return *this;}
			Admin& set_admin_username(char admin_username[]){	strcpy(this->admin_username, admin_username); return *this;}
			Admin& set_admin_password(char admin_password[]){	strcpy(this->admin_password, admin_password); return *this;}
			
			// getters for the data
			
			char* get_admin_name(){	return admin_name;}
			char* get_admin_username(){	return admin_username;}
		
			// methods for Admin 
			
			void sign_up(); // create an accout for the Admin
			void sign_in(); // access the Admin's account
			void main_menu(); // access the main menu
		
			static bool check_if_account_exists(); // a function that returns true or false on the account's existence 
			
};

void Admin :: sign_up()		
{	
	system("CLS");
	
	dob admin_dob; // an instantiation of the DOB structure for the admin's dob
	
	char admin_name[30], admin_username[30], admin_password[15];
	
	bool password_entered = false; // a flag to detect if the password has been entered  or not
	bool password_confirmed = false; // a flag to detect if the password has been confirmed or not
		
	// taking input from Admin
			
	cout<<"\n\n\t\t------------------------Admin Input Screen------------------------\n\n";
	cout<<"\t\tDear Admin,	\n\n";
	cout<<"\tYou need to enter the following details:	\n\n";
	cout<<"\tName: \t"; cin>>admin_name;
	
	admin_dob.set_dob(); // function call to set date of birth
	
	cout<<"\n\n\tUsername: \t"; cin>>admin_username; 		
	
	while(!password_confirmed) // loop breaks only when password has been confirmed
	{
		int i = 0; // a temp integer used as an index for the password char array
		char a; // a temp character used to store user-entered char
		
		cout<<"\n\n\tPassword (Maximum characters allowed: 15): \t"; 
		
		while(!password_entered)	// loop breaks only when password has been entered
		{
			a=getch();	// gets and stores char typed in a
			
			if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))	//checks if a is numeric or an alphabet
			{
				admin_password[i] = a;	//stores a in the password char array
			    ++i; 	// increment the number of characters 
				cout<<"*";
			}
			else if(a=='\b' && i>=1)	//if user typed backspace & the number of characters are greater than 1.
			{
			    cout<<"\b \b";	//delete the character behind the cursor.
			    --i; 	// decrement the number of characters
			}
			else if(a=='\r')	//if enter is pressed
			{
				admin_password[i] = '\0';		//null character for end of string.
			    password_entered = true;		//break the inner loop as password has been entered
			}
		}
		
		if(i>15) // check if the entered password exceeds the character limit
		{
			password_entered = false;	// password needs to be entered again
			cout<<"\n\n\t\tMaximum 15 characters allowed.\n\n\t\tPress any key to try again.";
			getch();
		}
		else{		password_confirmed = 	true;		} // break the outer loop as password has been confirmed
	}
	
	// chain calling the setters for each data member
	 
	set_admin_name(admin_name).set_admin_username(admin_username).set_admin_password(admin_password);
			
	system("CLS");
	
	cout<<"\n\n\t\t\tPlease wait while your account is being created.\n\n";
	cout << "\n\n\t\t\t *";
	
	for(int a=1;a<10;a++) 
	{
		Sleep(400);
		cout << "*";
	}
		
	ofstream write_object("Admin Account.txt"); // creating a file of type txt for Admin Account
	
	if(write_object.is_open()) // check if file is open
	{
		cout<<"\n\n\t\tFile opened for writing account to file.";		
		write_object<<admin_name<<"\n"<<admin_username<<"\n"<<admin_password; // writing data on file
		write_object.close();	// closing the file	
		system("CLS");
		cout<<"\n\n\t\t\tCongratulations!\n\n\t\t\tYour employee account has been successfully created.";
		cout<<"\n\n\t\t\tPress any key to continue.\n\n";
		getch();
	
		// account has been created now to the main menu
		
		main_menu();
	}
	else
	{
		system("CLS");
		cout<<"\n\n\t\tFile could not be opened for writing account to file.\n\n\t\t";
		write_object.close();
	}				
}

void Admin :: sign_in()
{
	char admin_login_username[30], admin_login_password[15];

	bool password_entered = false; // a flag to detect if the password has been entered  or not
	bool password_confirmed = false; // a flag to detect if the password has been confiremed or not
	bool details_confirmed = false; // a flag to detect if the details have been confirmed or not
		

	ifstream read_object("Admin Account.txt"); // opening a file of type txt for Admin Account
	
	
	if(read_object.is_open()) // check if file is open
	{
		system("CLS");
		cout<<"\n\n\t\t\tEmployee Account File exists!\n\n";
		cout<<"\n\n\t\t\tPress any key to continue.\n\n\t\t";
	
		getch();
		
		system("CLS");
		cout<<"\n\n\t\t\tEmployee Login Screen.\n\nLogin: ";
		
		while(!details_confirmed)	// loop breaks only when details have been confirmed
		{
			
			cout<<"\n\nUsername: \t"; cin>>admin_login_username;
			
			while(!password_confirmed) // loop breaks only when password has been confirmed
			{
				cout<<"\n\nPassword (Maximum characters allowed: 15): \t"; 
				
				int i = 0; // a temp integer used as an index for the password char array
				char a; // a temp character used to store user-entered char
		
				
				while(!password_entered) // loop breaks only when password has been entered	
				{	
					a=getch();	//gets and stores char typed in a
					
					if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))	//checks  if a is numeric or an alphabet
					{
					    admin_login_password[i]=a;	//stores a in the password char array
					    ++i;	// increment the number of characters
					    cout<<"*";
					}
					if(a=='\b'&&i>=1)	//if user typed backspace   & the number of characters are greater than 1
					{
					    cout<<"\b \b";	//delete the character behind the cursor.
					    --i;	// decrement the number of characters
					}
					if(a=='\r')		//if enter is pressed
					{
						admin_login_password[i]='\0';		//null character for end of string.
					    password_entered = true;		//break the inner loop as password has been entered
					}
				}	    
				if(i>15) // check if the entered password exceeds the character limit
				{
					cout<<"\n\n\t\tMaximum 15 characters allowed.\n\n\t\tPress any key to try again.";
					getch();
					password_entered = false; // password needs to be entered again
				}
				else{		password_confirmed = 	true;		} // break the outer loop as password has been confirmed
			}
				read_object.seekg(0, ios::beg); // read the file with the cursor at the beggining 
				
				read_object>>admin_name>>admin_username>>admin_password; // read the data from file
							
				getch();
				
				// if the username is correct but the password is incorrect
				
				if(strcmp(admin_username, admin_login_username) == 0 &&  strcmp(admin_password, admin_login_password) != 0)
				{
					system("CLS");
					cout<<"\n\n\t\t\tPlease wait while your details are being checked.";
					cout << "\n\n\t\t\t *";
					for(int a=1;a<6;a++) 
					{
						Sleep(500);
						cout << "*";
					}
									
					system("CLS");
					cout<<"\n\n\t\t\tIncorrect password entered !\n\n\t\t\tPress any key to try again!\n\n";
					details_confirmed = false; 	// details need to be entered again
					password_confirmed = false;
					password_entered = false;				
				}
				
				// if the username is incorrect but the password is correct
				
				else if(strcmp(admin_username, admin_login_username) != 0 &&  strcmp(admin_password, admin_login_password) == 0)
				{
					system("CLS");
					cout<<"\n\n\t\t\tPlease wait while your details are being checked.";
					cout << "\n\n\t\t\t *";
					for(int a=1;a<6;a++) 
					{
						Sleep(500);
						cout << "*";
					}
									
					system("CLS");
					cout<<"\n\n\t\t\tIncorrect username entered !\n\n\t\t\tPress any key to try again!\n\n";
					details_confirmed = false; // details need to be entered again
					password_confirmed = false;	
					password_entered = false;		
				}
				
				// if both username and password are incorrect
				
				else if(strcmp(admin_username, admin_login_username) != 0 &&  strcmp(admin_password, admin_login_password) != 0)
				{
					system("CLS");
					cout<<"\n\n\t\t\tPlease wait while your details are being checked.";
					cout << "\n\n\t\t\t *";
					for(int a=1;a<6;a++) // Change 'a<?' to how many * you want
					{
						Sleep(500);
						cout << "*";
					}
									
					system("CLS");
					cout<<"\n\n\t\t\tIncorrect username and password entered !\n\n\t\t\tPress any key to try again!\n\n";
					details_confirmed = false; // details need to be entered again
					password_confirmed = false;	
					password_entered = false;		
					getch();
				}
				
				// if both username and password are correct
				
				else if(strcmp(admin_username, admin_login_username) == 0 &&  strcmp(admin_password, admin_login_password) == 0)
				{
					system("CLS");
								
					cout<<"\n\n\t\t\tPlease wait while your details are being checked.";
					cout << "\n\n\t\t\t *";
					for(int a=1;a<6;a++) // Change 'a<?' to how many * you want
					{
						Sleep(500);
						cout << "*";
					}
									
					system("CLS");
					cout<<"\n\n\t\t\tYou have successfully logged in!\n\n\t\t\tPress any key to continue.\n\n\t\t\t";
					getch();
					main_menu();
					details_confirmed = true; // break the outermost loop as details have been confirmed
				}
				
				// account has been verified now to the main menu
				
		}
		
		read_object.close(); // closing the file								
	}
	else // the file doesn't exist meaning the account has not been created
	{
		system("CLS");
		read_object.close();
		cout<<"\n\n\t\t\tEmployee's Account has not been created yet.\n\n\t\t\tPress any key to create employee's account.\n\n\t\t\t";
		getch();
		sign_up(); // invoke the admin to create his account
	}
		
}	    	

bool Admin :: check_if_account_exists()
{
	ifstream check("Admin Account.txt"); // open an object of ifstream with our previous file
	
	if(check.is_open()){ 	return true;	} else {	return false;	} // if the file is open then the file exists
}
void Admin :: main_menu()
{
	// current date/time based on current system
  	time_t now = time(0);
   	// convert now to string form
  	char* dt = ctime(&now);
  	
	system("CLS");
	
	
	Patient p[500];
	Receptionist r;
	Doctor d;
	Operation O[10];
	Pharmasist ph;
	Labassistant lab;
	Staff *s[500];
	
	
	int i=0,choice,n,z=0,id,b,op=0;
	
		cout <<"\n\n				----------------------------";
		cout <<"\n  				|HOSPITAL MANAGEMENT SYSTEM|";
		cout <<"\n				----------------------------";
		
	menu:
		cout << endl<<endl<<"\t\tThe local date and time is: " << dt;	
		cout<<"\n\n\t\tWelcome to the Hospital Management System\n\n\n\n\t\tChoose your desired operation:\n\n\t\t1-Admin Menu\n\n\t\t2-Receptionist Menu\n\n\t\t3-Doctor Menu\n\n\t\t4-Pharmacy Menu\n\n\t\t5-Laboratory\n\n\t\t6-Exit\n\n";
        cin>>n; 
    
	
	switch(n){
	
		case 1:{
		
			menu1:{
		
				system("cls");
				// current date/time based on current system
  				time_t now = time(0);
   				// convert now to string form
  				char* dt = ctime(&now);
   				cout << endl<<endl<<"\t\tThe local date and time is: " << dt << endl << endl;
				cout<<"\t\t\tWelcome to Admin Menu\n\nInsert your choice :\n1 :Add Doctor\n2 :Add Receptionist Info\n3 :Add Pharmasist\n4 :Add Lab Assistant\n5:Search Staff\n6:Exit";
				cin>>choice;
        		
				char chh='n';		 
		 		
				if(choice==1){
					system("cls");
		 			s[i]=new Doctor();
		 			s[i]->set_data();
					i++;
					goto menu1;
				}
				else if(choice==2){
					system("cls");
					s[i]=new Receptionist();
					s[i]->set_data();
					i++;
					goto menu1;
				}
					
				else if(choice==3){
					system("cls");
					s[i]=new Pharmasist();
					s[i]->set_data();
					i++;
					goto menu1;
				}		
				else if(choice==4){
					system("cls");
					s[i]=new Labassistant();
					s[i]->set_data();
					i++;
					goto menu1;
				}
				else if(choice==5)
				{
					id=0,b=0;
					system("cls");
					cout<<"\n\nPlease Enter Id to Search Staff";cin>>id;
					
					do{
						for(int i=0;i<500;i++){
							
							if(id==s[i]->get_ID()){
			 					s[i]->get_data();
			 					system("pause");
			 					b++;
			 					break;
			 				}
			 			}
					}while(b==0);
				}
				else if(choice==6)
				{
					system("cls");
					goto menu;
				}
				else{
					cout<<"\n Invalid Input";
        			goto menu1;
	    		}
			}
			
        }
		
		
		case 2:{
			
			
			menu2:
			system("cls");
			
			cout<<"\t\tWelcome to Reception\n\nPlease Enter choice\n1-Add Patient\n2-Search Patient\n3-Exit";	
			cin>>n;
			
			if(n==1){
        		system("cls");
        		r.add_patient(p[z]);
				z++;	
		   	}
			   	 
		   	else if(n==2){
				system("pause");
				int id;
				system("cls");
				cout<<"Please Enter Patient id to Search";
				cin>>id;
				int b=0;
			
				do{
				
					for(int a=0;a<500;a++){
						if(id==p[a].Id){
							p[a].showinfo();
							system("pause");
							b++;
							break;
						}
					}
				}while(b==0);
			
				goto menu2;
			}
        	else if(n==3){
        		system("cls");
        		goto menu;
			}
			else{
				cout<<"\nInvalid input";
				goto menu2;
			} 
			
		}
         
		case 3:{
			
			system("cls");
			
			cout<<"\n\t\t\tWelcome to Doctor Menu\n";
			int a;b=0;
			
			do{
				
				cout<<"Please Enter Patient id to continue:";cin>>id;
				
				for(int a=0;a<500;a++){
					
					if(id==p[a].Id){
				    	
						b++;
						
						menu3:
				    		cout<<"\n\n\t\tPlease Insert Your choice\n\n1-View Patient info\n2-Perscribe Medicine\n3-Perform Operation\n4-Perscribe Test\n5-Exit";
				    		cin>>choice;
				    		
							if(choice==1){
						    	system("cls");
				    			p[a].showinfo();
								system("pause");
								goto menu3;
							}
				    		else if(choice==2){
				    			system("cls");
				    			cout<<"\n\t\t"<<p[a].Id<<"\n\t\t"<<p[a].Name<<"\n";
				    			d.perscribe_medicine(p[a]);
				    			system("pause");
				    			goto menu3;
							}
							else if(choice==3){
								system("cls");
								d.perform_operation(O[op],p[a]);
								op++;
								goto menu3;
							}
							else if(choice==4){
								system("cls");
								d.perscribe_test(p[a]);
								goto menu3;
							}
							else if(choice==5){
								system("cls");
								goto menu;
							}
							else{
								cout<<"\n Invalid Input";
								goto menu3;
							}
					}
				}
				
				if(b==0)
					cout<<"\nInvalid ID\n";
			}while(b==0);	
			 
			goto menu;
				
		}
		
		case 4:{
		
			menu4:
		  		system("cls");
		  		cout<<"\n\t\tWelcome to pharmacy Menu\n\nPlease Enter choice\n\n1-View Medicine\n2-Generate bill\n3-Exit";
				cin>>choice;
			
			b=0;
			
			if(choice==1){
			  	cout<<"Please Enter Patient id to view Medicine";
			  	cin>>id;
			  	
				do{
			  		for(int a=0;a<500;a++){
						if(id==p[a].Id){
				   		 	b++;
				    		ph.View_Medicine(p[a]);
				     	} 
				 		if(b==0){
				 			cout<<"Invalid Id";
				 			b++;
				 			break;   
						} 
			 		}
        		}while(b<1);
        	
				goto menu4;
			}
			else if(choice==2){
				system("cls");
		        ph.Medicine_bill();
		        system("pause");
		        goto menu4;
			}
			else if(choice==3){
				system("cls");
				goto menu;
			}
			else {
				cout<<"\nInvalid  Input";
				goto menu4;
			}
		}
			
		case 5:{
			
			system("cls");
			
			menu5:
				cout<<"\t\tWelcome To Labortory\nSelect an option\n1-Collect Samples\n2-Generate Report\n3-Exit";cin>>choice;
			
			if(choice==1){
				
				system("cls");
				
				cout<<"Please Enter Patient id to view Test";
			  	cin>> id;
			  	
				do{
			  		for(int a=0;a<500;a++){
						if(id==p[a].Id){
					    	b++;
							lab.Collect_samples(p[a]);
				     	} 
				 		if(b==0){
				 			cout<<"Invalid Id";
				 			b++;
					 		break; 
						} 
			 		}
        		
				}while(b<1);
				
				goto menu5;
			}
			else if(choice==2){
				system("cls");
				lab.Report_Generation();
			}
			else if(choice==3){
				system("cls");
				goto menu;
			}
			else{
				cout<<"Invalid Choice";
			}	
		}
		
		case 6:{

			exit(1);
			break;
		}

		default:
			cout<<"Invalid Choice";
			goto menu;
	}
}	    
int main()
{
	// current date/time based on current system
  	time_t now = time(0);
   	// convert now to string form
  	char* dt = ctime(&now);
	fullscreen();
	system("COLOR A0");
	
	Admin ADMIN; // The program is solely used by the Admin
	
	if(Admin :: check_if_account_exists()) // check if the admin has already accessed this program
	{
		string admin_name;
		
		ifstream read("Admin Account.txt");	
		read >> admin_name;
		cout <<"\n\n				----------------------------";
		cout <<"\n  				|HOSPITAL MANAGEMENT SYSTEM|";
		cout <<"\n				----------------------------";
   		cout << endl<<endl<<"\t\tThe local date and time is: " << dt;
		cout << "\n\n\n\t\t----------------Welcome back " << admin_name << "!----------------\n\n";
		cout << "\n\n\t Enter 1 to sign in to your account.";
		cout << "\n\n\t Not you ? \n\n\t Choose any of your desired choice from the options below.\n\n";
		cout << "\n\n\t 2) Sign Up \n\n\t 3) Sign In\n\n\t 4) Exit \n\n";
		int a; cin >> a;
		if(a==1)	{	ADMIN.sign_in();	} // account exists
		else if(a==2)	{	ADMIN.sign_up();	} // account doesn't exist
		else if(a==3)	{	ADMIN.sign_in();	} // account doesn't exist
		else if(a==4)	{	exit(1);		}
	}
	else
	{
		cout <<"\n\n				----------------------------";
		cout <<"\n  				|HOSPITAL MANAGEMENT SYSTEM|";
		cout <<"\n				----------------------------";
		cout << endl<<endl<<"\t\tThe local date and time is: " << dt;	
		cout << "\n\n\t\t\tWelcome to the hospital management system. \n\n";
		cout << "\t\tIn order to continue, you need to create an account. Already have one? Choose Sign In.\n\n";
		cout << "\n\n\t1) Sign Up \n\n\t2) Sign In \n\n\t3) Exit\n\n";
		int a; cin >> a;
		if(a==1)	{	ADMIN.sign_up();	}
		else if(a==2)	{	ADMIN.sign_in();	}
		else if(a==3)	{	exit(1);	}
		
	}
    return 0;
}
