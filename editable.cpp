#include<iostream>      //this header file is included as it contains functions of programs like cin,cout etc
#include <string>       //included to avoid ascii values when string is called 
#include<math.h>
#include<fstream>
#include <windows.h>          //for new interface
#include <conio.h>           //for maths functions
#include <stdlib.h>          //to make input output easy 
#include <string.h>           
#include <time.h>            //for printing current time and date
#include <fstream>           //file handling
#include <cstdio>            
using namespace std;    


float calci()   //calling the function of calci to calculate the gpa according to the grades and credit hours.
                //float is used so this function can return the decimal or integer Value of final GPA.
{
 
	const float A = 4.0;
    const float A_MINUS = 3.67;
	const float B_PLUS = 3.33;
	const float B = 3.0;
	const float B_MINUS = 2.67;
	const float C_PLUS = 2.33;
	const float C = 2.0;
	const float C_MINUS = 1.67;
	const float D = 1.00;
	const float F = 0.0;
	
	string lettergrade;      //string is used to store text
 	float credithours;       
    float hoursintograde = 0;
    float persubject = 0;
    float totalcredithours = 0;
    float finalgpa = 0;
    int option;
  
 	for(;;)        //no condition is given to create a forever loop 
    {           
        cout<<"\nEnter letter grade: ";
        cin>>lettergrade;
        
        cout<<"Enter the course credithours: ";
        cin>>credithours;
    
			   
		if(lettergrade == "a" || lettergrade == "A")
		{
			hoursintograde = credithours * A;
		}
		else if(lettergrade == "a-" || lettergrade == "A-")
		{
			hoursintograde = credithours * A_MINUS;
		}
		else if(lettergrade == "b+" || lettergrade == "B+")
		{
			hoursintograde = credithours * B_PLUS;
		}
		else if(lettergrade == "b" || lettergrade == "B")
		{
			hoursintograde = credithours * B;
		}
		else if(lettergrade == "b-" || lettergrade == "B-")
		{
			hoursintograde = credithours * B_MINUS;
		}
		else if(lettergrade == "c+" || lettergrade == "C+")
		{
			hoursintograde = credithours * C_PLUS;
		}
		else if(lettergrade == "c" || lettergrade == "C")
		{
			hoursintograde = credithours * C;
		}
		else if(lettergrade == "c-" || lettergrade == "C-")
		{
			hoursintograde = credithours * C_MINUS;
		}
		else if(lettergrade == "d" || lettergrade == "D")
		{
			hoursintograde = credithours * D;
		}
		else if(lettergrade == "f" || lettergrade == "F")
		{
			hoursintograde = credithours * F;
		}	   
		else
		{
			cout<<"Invaild Input...";
		}
	
	             
          totalcredithours = totalcredithours + credithours;  //to calculate the total number of credit hours
          persubject = persubject + hoursintograde;               
          
		  cout<<"Do you want to enter another grade (1 - Yes, 2 - no): ";
		  cin>>option;
		  
		  if(option == 1)
		  {
		  	continue;
		  }
		  else
		  {
		  	break;     
		  }      
 	}
                
          finalgpa = persubject/totalcredithours;
          cout<<"Student's GPA: "<<finalgpa<<"\n";

		  
    return finalgpa;    //float calci function returns the final gpa.
}

int cr(int a);  // checks reg no.s

int total=0;    //to avoid garbage values	



class giki_calci{

void enter();     //this function will not return any value
void show();    //the function does not return any value 
void search();        //the function does not return any value
void update();      //function does not return any value

public:
giki_calci(){                                                                                     //constructor.
main_menu();
}                                                          

void main_menu(){
	system("cls");
	cout<<"********** WELCOME TO GIKI CALCI **********";
	int value;

	while(true)

	{

	cout<<"\nPress 1 to enter data"<<endl;

	cout<<"Press 2 to show data"<<endl;

	cout<<"Press 3 to search data"<<endl;

	cout<<"Press 4 to update data"<<endl;

	cout<<"Press 5 to exit data"<<endl;
	
	cin>>value;

	switch(value)         //switch provides easy way to dispatch execution to different parts of code based on the value entered.

	{

		case 1:

			enter();      //the function of enter is called

			break;

		case 2:

			show();       //the function of show is called

			break;

		case 3:

			search();      //the function of search is called

			break;

		case 4:

			update();       //the function of update is called

			break;

		case 5:

			exit(0);        //exit is no function . it returns null value.

			break;

		
		default:             //when any value except 1,2,3,4 and 5 is entered 

			cout<<" Invalid input "<<endl;

			break;

	}

}
}






};


class record{
    public:
char name[25],faculty[25],semester[10];             
int contact,grade,grade_2,reg_no; //declaring the values to be stored

};


void giki_calci:: enter()  {     //this function will not return any value
system("cls");
record recs;
int no_students; 
char X;
ofstream O;         // data type for file management.
char choice_add;

	O.open("record.bin", ios::app | ios::binary);// data will be written at the end of the file.

		do{
			  cout << " STUDENT ACCOUNT REGISTRATION ";
              cout<<endl;

				 cout<<"Enter name ";

				 cin>>recs.name;       //the name will be stored in array of names at position i

				 cout<<"Enter Reg no ";

				 cin>>recs.reg_no;      //the reg number will be stored in array of reg no at position i

				 cout<<"Enter faculty ";

				 cin>>recs.faculty;      //the faculty will be stored in array of faculty at position i

				 cout<<"Enter semester ";

				 cin>>recs.semester;      //the semester will be stored in array of semester at position i
 
				 cout<<"Enter contact ";

				 cin>>recs.contact;        //the contact will be stored in array of contact at position i
				
				 cout<<"ENTER GRADE 1 ";

				 recs.grade=calci();   //the function claci will run here and will return the value of final gpa which will be stored in array of grade.

				 cout<<"ENTER GRADE 2: ";

				 recs.grade_2=calci();  
	
		    

		//write() = for writing binary data
      // reinterpret_cast - casting one pointer data type to another pointer data type
      //This helps to write contents in a class variable in the file and stores it in the variable rec.
      //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

	O.write(reinterpret_cast < char * > ( & recs), sizeof(recs)); //whatever &rec is treat it as char *
	
	
      cout << "STUDENT REGISTRATION SUCCESSFULL";
      total++;
      cout << endl;
      cout << "Do You Want To Add Another Record ? (Y/N) : ";
      cin>>X;
}

    while (choice_add == 'Y' || choice_add == 'y');
    O.close();

   cout << "Press any key to return back to main menu. ";
   char z = getch();
   
   if (z == 13) {
      main_menu();
   }
   
    else
      show();
  }




void giki_calci:: show()    //the function does not return any value 
{system("cls");
     int i=5;
    ifstream V;// to read file
    record rec;

    V.open("record.bin", ios::in | ios::binary); //open file for read only

   cout << " STUDENTS  LIST ";
   cout << endl;


 while (V.read(reinterpret_cast < char * > ( & rec), sizeof(rec))) {

	    		cout<<"Name "<<rec.name<<endl;

	    		cout<<"Roll no "<<rec.reg_no<<endl;

	    		cout<<"Course "<<rec.faculty<<endl;

	    		cout<<"Class "<<rec.semester<<endl;

	    		cout<<"Contact "<<rec.contact<<endl;
	    		
	    		cout<<"grade "<<rec.grade<<endl;

				cout<<"grade2"<<endl <<rec.grade_2<<endl;

				cout<<"CGPA"<<((rec.grade+rec.grade_2)/2)<<endl;
	    		

	        }

   V.close();
   int x;
   cout << "Press [Enter] to return back to main menu. ";
   x = getch();
   if (x == 13) {                            // 13 = '\r' i.e carriage return
      main_menu();
   } else
      show();                                //this is exception handling 
};





void giki_calci:: search()        //the function does not return any value

{system("cls");
record recs;

ifstream S;

char nam[30];

cout << " SEARCH STUDENT  ";
cout<<endl;

   cout << "Enter Your Full Name To Search : ";
   cin >> nam;
int b;

  S.open("record.bin", ios::in | ios::binary);
   
   while (S.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
      b = 0;
      strupr(recs.name);
      strupr(nam);
      if (strcmp(recs.name, nam) == 0) {                        ///==1;


/*

The function strupr() is used to convert the characters in a string to uppercase.
 In this code, strupr(recs.name) is converting all the characters in the string recs.name to uppercase.
Similarly, strupr(nam) is converting all the characters in the string nam to uppercase.

The function strcmp() is used to compare two strings and returns an integer value based on their lexicographical order.
 If the strings are equal, it returns 0.
In this code, strcmp(recs.name, nam) == 0 is checking if the string recs.name is equal to the string nam (after converting both to uppercase). 
If they are equal, the condition evaluates to true and the code inside the if statement will be executed.*/


    //printing the respective data from respective arrays of the entered roll number.
						cout<<"Name "<<recs.name<<endl;       

	    	        	cout<<"Roll no "<<recs.reg_no<<endl;

	    		        cout<<"Course "<<recs.faculty<<endl;

	    		        cout<<"Class "<<recs.semester<<endl;

	    	        	cout<<"Contact "<<recs.contact<<endl;
	    	        	
	    	        	cout<<"grade "<<recs.grade<<endl;
break;
					}

					else
					{
						b=1;
					}
				}
        S.close();

         if (b == 1) {
   	
   		system("cls");
     

cout << "Account Doesn't Exist. ";
cout<<endl;
   }

  cout<<endl;
   cout << "Press [ENTER] to return back to main menu. ";
   char z = getch();
   if (z == 13)
      main_menu();
   else
      search();

			}










void giki_calci:: update()          //function does not return any value

{system("cls");

   record rec;
   ifstream f1;
   ofstream f2;
   int a;
   int c;

cout << " EDIT STUDENT ACCOUNT ";
cout<<endl;
   cout << "Enter Your Resgistration Number To Edit : ";
   cin>>a;
    

      if (cr(a) == 1) {
      f1.open("record.bin", ios::in | ios::binary); //read
      f2.open("new.bin", ios::app | ios::binary); //write


      while (f1.read(reinterpret_cast < char * > ( & rec), sizeof(rec))) {


         if (rec.reg_no != a)
            f2.write(reinterpret_cast < char * > ( & rec), sizeof(rec));


         else if (rec.reg_no == a) {
                  cout << "Account Number Matched"<<endl;

						cout<<"\nPrevious data"<<endl<<endl;   //the entire previous data of the entered roll number will be printed
						cout<<"Name "<<rec.name<<endl;

	    	        	cout<<"Roll no "<<rec.reg_no<<endl;

	    		        cout<<"Faculty "<<rec.faculty<<endl;

	    		        cout<<"Semester "<<rec.semester<<endl;

	    	        	cout<<"Contact "<<rec.contact<<endl;
	    	        	
	    	        	cout<<"grade "<<rec.grade<<endl;


	    	        	cout<<"\nEnter new data"<<endl<<endl;   //new data will replace the old data

				            cout<<"Enter Semester ";

				            cin>>rec.semester;
				            
				            cout<<"Enter faculty ";

				            cin>>rec.faculty;
				            
				            cout<<"Enter grade ";

				            cin>>rec.grade;
 f2.write(reinterpret_cast < char * > ( & rec), sizeof(rec));
					}
      }

      f1.close();
      f2.close();
				}


  if (cr(a) == 0) {
    

      cout << "Account Doesn't Exist. ";
      cout<<endl;
    update();
   }


   remove("record.bin");
   rename("new.bin", "record.bin");

   cout << "STUDENT ACCOUNT UPDATE SUCCESSFULL";
cout<<endl;
   cout << "Press any key to return back to main menu . ";
   getch();
   main_menu();
	}

		



//module to check whether the entered reg is in the database or not
int cr(int a) {
   record rec;
   //read binary
   ifstream f;
   f.open("record.bin", ios::in | ios::binary);
   while (!f.eof()) {
      f.read(reinterpret_cast < char * > ( & rec), sizeof(rec)); //whatever &rec is treat it as char *
      //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

      if (a == rec.reg_no) {
         f.close();
         return 1;
      }
   }
   f.close();
   return 0;
}



main(){

cout << "\033[36m" ;// set color to red

   
   giki_calci g;
   return 0;
   
   
    /*In this example, the escape sequence "\033[31m" sets the text color to red, and "\033[0m" resets the color to the default. 
  Note that not all terminals support these escape sequences, so it's a good idea to test your code in different environments.*/





}
