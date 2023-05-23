#include<iostream>      //this header file is included as it contains functions of programs like cin,cout etc
#include <string>       //included to avoid ascii values when string is called 
#include<math.h>
using namespace std;    

string name[60],reg_no[60],faculty[60],semester[60];             
int contact[60],grade[60],grade_2[60] ; //declaring the arrays

int total=0;    //to avoid garbage values

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

void enter()        //this function will not return any value

{             

		int no_students; 

			cout<<" How many students do u want to enter?? "<<endl;cin>>no_students;    // students entered.

			if(total==0)   //to avoid garbage values
			{

			  total=no_students+total;

			 for(int i=0;i<no_students;i++)

			    {

				 cout<<"\nEnter the Data of student "<<i+1<<endl<<endl;

				 cout<<"Enter name ";

				 cin>>name[i];       //the name will be stored in array of names at position i

				 cout<<"Enter Reg no ";

				 cin>>reg_no[i];      //the reg number will be stored in array of reg no at position i

				 cout<<"Enter faculty ";

				 cin>>faculty[i];      //the faculty will be stored in array of faculty at position i

				 cout<<"Enter semester ";

				 cin>>semester[i];      //the semester will be stored in array of semester at position i
 
				 cout<<"Enter contact ";

				 cin>>contact[i];        //the contact will be stored in array of contact at position i
				
				 cout<<"ENTER GRADE 1 ";

				 grade[i]=calci();   //the function claci will run here and will return the value of final gpa which will be stored in array of grade.

				 cout<<"ENTER GRADE 2: ";

				 grade_2[i]=calci();  
				
				 }
	
		    }
			
			
			else   //when total is not zero and this happens when there are multiple entries at same time
			{
              
			for(int i=total;i<no_students+total;i++)
			{

				cout<<"\nEnter the Data of student "<<i+1<<endl<<endl;      

				cout<<"Enter name ";

				cin>>name[i];

				cout<<"Enter Roll no ";

				cin>>reg_no[i];

				cout<<"Enter faculty ";

				cin>>faculty[i];

				cout<<"Enter class ";

				cin>>semester[i];

				cout<<"Enter contact ";

				cin>>contact[i];

				cout<<"ENTER GRADE 1 :";
				grade[i]=calci();

				cout<<"ENTER GRADE 2: ";
				grade_2[i]=calci();  

				
				

			}

			total=no_students+total;  //to calculate the total number of students entered

			}

}
void show()    //the function does not return any value 

{

	if(total==0)   

	{

		cout<<"No data is entered"<<endl;    //when the total of data is zero that means no data has been entered yet.

	}

 else   {                                   //when total is not zero

		  for(int i=0;i<total;i++)

	    	{

	    		cout<<"\nData of Student "<<i+1<<endl<<endl;   //this prints the data of student 1 stored at position 0 of array

	    		cout<<"Name "<<name[i]<<endl;

	    		cout<<"Roll no "<<reg_no[i]<<endl;

	    		cout<<"Course "<<faculty[i]<<endl;

	    		cout<<"Class "<<semester[i]<<endl;

	    		cout<<"Contact "<<contact[i]<<endl;
	    		
	    		cout<<"grade "<<grade[i]<<endl;

				cout<<"grade2"<<endl <<grade_2[i]<<endl;

				cout<<"CGPA"<<((grade[i]+grade_2[i])/2)<<endl;
	    		

	        }

	   	}

}

 

void search()        //the function does not return any value

{

	if(total==0)

	{

		cout<<"No data is entered"<<endl;        //when the total of data is zero that means no data has been entered yet.

	}

	else{

	string rollno;

				cout<<"Enter the roll no of student"<<endl;

				cin>>rollno;

				for(int i=0;i<total;i++)          

				{

					if(rollno==reg_no[i])            //this will compare the entered roll number with the array of reg number and will locate it

					{
                                                      //printing the respective data from respective arrays of the entered roll number.
						cout<<"Name "<<name[i]<<endl;       

	    	        	cout<<"Roll no "<<reg_no[i]<<endl;

	    		        cout<<"Course "<<faculty[i]<<endl;

	    		        cout<<"Class "<<semester[i]<<endl;

	    	        	cout<<"Contact "<<contact[i]<<endl;
	    	        	
	    	        	cout<<"grade "<<grade[i]<<endl;

					}

					else
					{
						cout<<"INVALID INPUT.";

					}

				}

			}

}

void update()          //function does not return any value

{

	if(total==0)

	{

		cout<<"No data is entered"<<endl;

	}

	else{

		string rollno;

				cout<<"Enter the roll no of student which you want to update"<<endl;

				cin>>rollno;

					for(int i=0;i<total;i++)

				{

					if(rollno==reg_no[i])          //this will compare the entered roll number with the array of reg number and will locate it

					{

						cout<<"\nPrevious data"<<endl<<endl;   //the entire previous data of the entered roll number will be printed

						cout<<"Data of Student "<<i+1<<endl;   //this prints the data of student 1 stored at position 0 of array

						cout<<"Name "<<name[i]<<endl;

	    	        	cout<<"Roll no "<<reg_no[i]<<endl;

	    		        cout<<"Faculty "<<faculty[i]<<endl;

	    		        cout<<"Semester "<<semester[i]<<endl;

	    	        	cout<<"Contact "<<contact[i]<<endl;
	    	        	
	    	        	cout<<"grade "<<grade[i]<<endl;

	    	        	cout<<"\nEnter new data"<<endl<<endl;   //new data will replace the old data

				            cout<<"Enter Semester ";

				            cin>>semester[i];
				            
				            cout<<"Enter faculty ";

				            cin>>faculty[i];
				            
				            cout<<"Enter grade ";

				            cin>>grade[i];

				          
				            
				            

					}

				}

			}

		}


main()

{



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
