#include <iostream>
#include <string>
using namespace std;

// User class
class User {
    string username;
	string password;
   

public:
    void signup() {
        cout << "--- Signup ---"<<endl;
		cout<<"Enter new username: "<<endl;
        cin.ignore(); getline(cin, username);
        cout << "Enter new password: "<<endl;
        getline(cin, password);
        cout << "---Signup successful!---"<<endl;
    }

    int login() {
        string inputUser, inputPass;
        cout << "--- Login ---"<<endl;
		cout<<"Enter username: "<<endl;
        cin.ignore(); getline(cin, inputUser);
        cout << "Enter password: "<<endl;
        getline(cin, inputPass);

        if (inputUser == username && inputPass == password)
		 {
            cout << "Login successful!"<<endl;
            return 1;
        } else {
            cout << "Wrong username or password\n";
            return 0;
        }
    }
};

// Base class: Person
class Person{
   protected:
    string name;
    int age;

public:
    Person(string n = "unknown", int a = 0) 
	 {
		name = n;
		age = a;
	 }

     void show() 
	  {
        cout << "NAME : " << name << endl;
        cout << "AGE : " << age << endl;
      }

  
};

// Derived class: Donor
class Donor : public Person {
          string bloodgroup;
          string location, contact, checkup;
        
        public:
    		Donor(string n = "unknown", int a = 0, string bg = "unknown",
          			string loc = "unknown", string con = "unknown", string ch = "unknown")
		        {
		         name = n;
		         age = a;
		         bloodgroup = bg;
		         location = loc;
		         contact = con;
		         checkup=ch;
				}

    void display() 
	 {
        show();
        cout << "BLOOD GROUP  : " << bloodgroup << endl;
        cout << "LOCATION : " << location << endl;
        cout << "CONTACT : " << contact << endl;
        cout << "CHECKUP : " << checkup << endl;
    }

     friend string BloodGroup(Donor); 
    
};

//
string BloodGroup(Donor ss)
  { 
	return ss.bloodgroup;
  }
 

//  Blood Group Selection Men
//we cannnot user inline function because function contaning switch statement
string chooseBloodGroup() 
{
    int choice;
    string bg;

    cout << "Choose Blood Group:"<<endl ;
    cout << "1. A+"<<endl;;
    cout << "2. B+"<<endl;
    cout << "3. AB+"<<endl;
    cout << "4. O+"<<endl;
    cout << "5. A-"<<endl;
    cout << "6. B-"<<endl;
    cout << "7. AB-"<<endl;
    cout << "8. O-"<<endl;
    cout << "Enter your choice (1-8): "<<endl;
    cin >> choice;

    switch (choice) 
	{
        case 1: 
				bg = "A+"; 
				break;
        case 2: 
				bg = "B+"; 
				break;
        case 3: 
				bg = "AB+"; 
				break;
        case 4: 
				bg = "O+"; 
				break;
        case 5: 
				bg = "A-"; 
				break;
        case 6: 
				bg = "B-"; 
				break;
        case 7: 
				bg = "AB-"; 
				break;
        case 8: 
				bg = "O-"; 
				break;
        default:
            	cout << "Invalid choice. Defaulting to 'Unknown'.\n";
            	bg = "Unknown";
    }

    return bg;
}

// Main function
int main() {
    User u1;
    Donor donors[100];
    int Count = 0;
   
    int mainChoice;
    string name, loc, con, ch;
    int age;
    string bg;

    do {
        cout << "--- Smart Blood Finder Portal ---"<<endl;
        cout << "1. Login"<<endl;
        cout << "2. signup"<<endl;
        cout << "3. exit"<<endl;
        cin >> mainChoice;

        if (mainChoice == 1)
		{
            if (u1.login())
			 {
                int subChoice;
               	  do{
                    cout << "--- Donor Menu ---"<<endl;
                    cout << "1. Add Donor"<<endl;;
				    cout << "2. Search by Blood Group"<<endl;
					cout << "3. Display All Donors"<<endl;
					cout << "4. Exit"<<endl;
					cout << "Enter your choice: "<<endl;
                    cin >> subChoice;

                    if (subChoice == 1)
					   {
                        		cout << "Enter name : "<<endl;
		                        cin.ignore(); getline(cin, name);
		                        cout << "Enter age: "<<endl;
		                        cin >> age;
		                         if (age >= 18 )
									{
										if(age<=50)
											{
											    cout << "Donor are eligible. " << endl;
										    }
									        else
									        {
						   			        	cout<<"doner are not eligible Age must be between 18 and 50."<<endl;
									        	continue;
											}
		                            }
								  else
								    {
								    	cout<<"doner are not eligible  Age must be between 18 and 50."<<endl;
									    continue;	
							        }
					    
                        

		                        bg = chooseBloodGroup();
		                        cout << "Enter location: "<<endl;
		                        cin.ignore(); getline(cin, loc);
		                        cout << "Enter contact: "<<endl;
		                        getline(cin, con);
		                        cout << "Recent blood checkup? (yes/no): "<<endl;
		                        getline(cin, ch);
		                        
		                        donors[Count++] = Donor(name, age, bg ,loc, con, ch);
		                        cout << "Donor added successfully"<<endl;
                        }

                    else if (subChoice == 2)
					   {
	                         bg = chooseBloodGroup();
	                        int found=0;
	                        for (int i = 0; i < Count; i++)
							   {
	                           	 if (BloodGroup(donors[i]) == bg) 
									{
		                                donors[i].display();
		                                
		                                
		                                found++;
		                            }
		                        
	                        }
	    
	                        if(found==0)
							  {
								   cout << "No donors found with blood group code " << bg << endl;
								  
	                          }
                        }

                    else if (subChoice == 3)
					   {
                           if (Count == 0)
                           {
						       cout << "No donors added yet."<<endl;
						       break;
							}
                          else
						   {
                             for (int i = 0; i < Count; i++)
                               {
                                  donors[i].display();
                                }
                           }
                        }
                        else if (subChoice == 4)
							{
	                        	cout << "Exiting donor menu."<<endl;
	                        }
	
	                          else 
							{
	                             cout << "Invalid choice."<<endl;
	                        }

                } while (subChoice != 4);
            }
        }
		else if (mainChoice == 2)
		   {
		        u1.signup();
		    }
		
		else if (mainChoice == 3) 
		   {
		        cout << "Exiting program."<<endl;
		}

    else
       {
           cout << "Invalid choice. Try again."<<endl;
       }

} while (mainChoice != 3);

    return 0;
}
