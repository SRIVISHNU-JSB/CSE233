/*
Title - CUSTOMER BILLING SYSTEM (Project Version 1.2.3) && Submission Date - November 01, 2022
A Project by SRI VISHNU JSB
CBS on GitHub for latest version - https://github.com/SRIVISHNU-JSB/CSE233/tree/main/Projects
*/

/*
HOW TO USE THIS PROGRAM?
0.Ensure to take a look at the wireframe files attached to understand the overall architecture/blocks of this program
1.First we need to create Administrator and Customer Account(s) using Registration functions
2.We will have to add the customer accounts and their various information as necessary
3.We need to create the products using Admin account and verify the list of products created
4.Login using Customer account and confirm the customer details and place an order
5.As an admin account verify the balance sheet/ customer information for new the Bill Outstandings
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<unistd.h> //Required for running this code in Unix like OS systems

using namespace std;

void introduction();

// Class for introduction and various functions
class Administration
{
	string developer = "SRI VISHNU JSB";
    
    int order_array[50], quantity[50];
    int flag, found, counter, status, search_number, account_number;
    float amount, discount_amount, total; string chosen;
    char choice;
    
    public:
    	friend void introduction();
    	
		void welcome(int a);
		void writeCustomer();
		void placeOrder();
		void writeProduct();
		void modifyProduct();
		void deleteProduct();
		void displaySpecific(int a);

        string returnCreator()
        {
        	return developer;
		}
};

// class for handling login, registration and forgot credentials 
class Credentials
{
    private:
        int minimum_size; // For custom length of the username/password
        int count = 0, choice;
        char chosen;
        
        string user, pass, user_2, pass_2;
        string new_user, new_pass, valid_name, confirm_pass;
        string search_user, search_pass, search_user_2,search_pass_2, selection, privilege;
 
        bool check_status = true;
        bool registration_status = false;
    
    public:
        int login();
        void registration(int a);
        void registrationAdvanced(int a);
        void forgot();
};

// struct for storing customer specific information
struct customer
{
	char account_type;
	int account_number, contact_number;
	string name, street, city, date;
	float old_balance, new_balance, payment, bill_dues;
};

// class for managing all the customer related information 
class Customer: public Administration
{
    customer kyc; // Customer object using struct method
    static int counter;
    int i, n, search_number, flag;
	string search_name, chosen;
    char choice;
    
	public:
		friend class Product;
		friend class Administration;
		
		
        void adminPage();
        void customerPage();
        void adminSearch(char chosen);
        void customerSearch(char chosen);
        
        void createCustomer()
        {
            counter++;

            cout<<"\n\n\t\t	Entry Number	: "<<counter;
            cout<<"\n\n\t\t	Name		: "; getline(cin>>ws,kyc.name);
			cout<<"\n\t		Contact Number  : "; cin>>kyc.contact_number;
			cout<<"\n\t		Account Number 	: "; cin>>kyc.account_number;
			cout<<"\n\t		Street         	: "; getline(cin>>ws,kyc.street);
			cout<<"\n\t		City           	: "; getline(cin>>ws,kyc.city);
			cout<<"\n\t		Old balance    	: "; cin>>kyc.old_balance;
			cout<<"\n\t		Current payment	: "; cin>>kyc.payment;
			cout<<"\n\t		Payment date   	: "; cin>>kyc.date;
			cout<<"\n\t		B.Outstandings 	: "; cin>>kyc.bill_dues; //Bill Outstandingss
		  
            if(kyc.payment>0)
            {
                kyc.account_type=(kyc.payment<kyc.old_balance)? 'O' : 'L';
            }
            else
            {
                kyc.account_type=(kyc.old_balance>0)? 'O' : 'P';
            }
            kyc.new_balance=kyc.old_balance - kyc.payment;
        }

		void viewCustomer()
		{
		//	cout<<"\n\n\t	Serial Number: "<<serial_number;
			cout<<"\n\n\t\t	Name		: "<<kyc.name;
			cout<<"\n\t		Contact Number  : "<<kyc.contact_number;
			cout<<"\n\t		Account Number 	: "<<kyc.account_number;
			cout<<"\n\t		Street         	: "<<kyc.street;
			cout<<"\n\t		City           	: "<<kyc.city;
			cout<<"\n\t		Old balance    	: "<<kyc.old_balance;
			cout<<"\n\t		Current payment	: "<<kyc.payment;
			cout<<"\n\t		New balance    	: "<<kyc.new_balance;
			cout<<"\n\t		Payment date   	: "<<kyc.date;
			cout<<"\n\t		B.Outstandings 	: "<<kyc.bill_dues; //Bill Outstandingss
			cout<<"\n\t		Customer status : ";
		
			switch(kyc.account_type)
			{
				case 'L':
						cout<<"LOYAL\n\n";
						break;
				case 'O':
						cout<<"OVERDUES\n\n";
						break;
				case 'P':
						cout<<"PLATINUM\n\n";
						break;
				default:
						cout<<"NO STATUS\n\n";
			}
		}           
};

// class for managing the products and billing related functions
class Product: public Customer
{
    int product_number, account_number, flag = 0, counter = 0;
    int order_array[50], quantity[50];

    float price, tax, discount, amount, discount_amount, total = 0;
    char choice; string product_name, chosen;

    public:
    	friend void welcome(int a);
    	friend void placeOrder();
    	friend class Administration;
    	
        // Reserved Functions, can be used as member functions if necessary
        void adminMenu();
        void placeOrder();
        void productMenu();
		void displayAll();
		
        void createProduct()
        {
            cout << "\n\n\tPlease Enter The Product Number for The Product: "; cin >> product_number;
            cout << "\n\tPlease Enter The Name of The Product: "; getline(cin>>ws,product_name);
            cout << "\n\tPlease Enter The Price of The Product: "; cin >> price;
            cout << "\n\tPlease Enter The Discount(%): "; cin >> discount;
        }

        void showProduct() 
        {
            cout << "\n\tThe Product Number of The Product: " << product_number;
            cout << "\n\tThe Name of The Product: "<< product_name;
            cout << "\n\tThe Price of The Product: " << price;
            cout << "\n\tDiscount : " << discount;
            cout << "\n";
        }

        int retpno() 
        {
            return product_number;
        }

        float retprice() 
        {
            return price;
        }

        string retname() 
        {
            return product_name;
        }

        int retdis() 
        {
            return discount;
        }

}; //class ends here

//***************************************************************
// global declaration for stream object, objects
//****************************************************************

int Customer::counter=100;

fstream fs;
stringstream ss;
Administration ad;
Credentials cs;
Customer cr;
Product pr;

//****************************************************************
// The MAIN fuction which manages rest of CBS fucntions/program
//****************************************************************

int main()
{
    int choice; string selection;
    
    system("cls");
    introduction();
    try
    {
        do
        { 
            cout<<"\n=======================================================================\n";
            cout<<"\n\t\t\tCUSTOMER BILLING SYSTEM\n";
            cout<<"\n=======================================================================\n";   
            cout<<"***********************************************************************\n\n";
            cout<<"                        Welcome to CBS Portal                               \n\n";
            cout<<"*************************        MENU       ***************************\n\n";
            cout<<"1.ADMINISTRATOR"<<endl;
            cout<<"2.CUSTOMER"<<endl;
            cout<<"3.EXIT"<<endl;
            cout<<"\nPlease select your option (1-3) ";
            cin>>selection;
			
			ss << selection; ss >> choice; //Type casting if any other values entered other than numbers.
			ss.clear();
            if(choice == 1)
                ad.welcome(1);
            else if(choice == 2)
                ad.welcome(2);
            else if(choice == 3)
            {
                cout<<"\nThanks for using this program!!!\n\n";
				cout<<"This program is created by "<<ad.returnCreator()<<"\n";
                exit(0);
            }
            else
            {
//              system("cls");
                cout<<"\nException 0\n";
                throw(10);
            }
        } while (choice !=3);
    }
    catch(int i)
    {
        cout<<"\nPlease select only correct option provided.\n\n";
        system("PAUSE");
//        sleep(5);
		exit(0);
    }
//    cin.get();
//    cin.get();
	main();
}

//****************************************************************
// function for the management of CBS - Customer Billing System
//****************************************************************

void Administration::welcome(int a)
{
	system("cls");
	try
	{	
		cout<<"***********************************************************************\n\n";
      	cout<<"                        Welcome to Login Page                            \n\n";
        cout<<"************************      MAIN MENU     ***************************\n\n";

		cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTER"<<endl;
        cout<<"3.FORGOT USERNAME or PASSWORD"<<endl;
        cout<<"4.GO BACK"<<endl;
        cout<<"\nA Project by "<<ad.returnCreator();
        cout<<"\n\nSelect an option to continue (1-4) ";
        cin>>chosen;
        cout<<endl;
        
        ss << chosen; ss >> choice;
    	ss.clear();
    	if(choice == '1' || choice == '2' || choice == '3' || choice == '4')
	    {
	        switch(choice)
        	{
                case '1':
                  	status=cs.login();
					if(status==10)
					{
                        system("cls");
                        pr.adminMenu();
                        break;
					}
					else if(status==20)
					{
                        system("cls");
                        cr.customerPage();
                        break;
					}
                    break;
                case '2':
                    // cs.registration(a);
                    cs.registrationAdvanced(a);
                    welcome(0);
                    break;
                case '3':
                    cs.forgot();
                    break;
                case '4':
                	main();
                	break;
                        
                default:
                    system("cls");
                    cout<<"Please select a correct option and try again\n"<<endl; 
        	}	
    	}
        else
        {
        	cout<<"\nException 1\n";
        	throw(10);
		}
	}
    catch(int i)
    {
    	cout<<"\nPlease select only correct option provided.\n\n";
        system("PAUSE");
//        sleep(5);
		exit(1);
	}
	welcome(0);
}

//****************************************************************
// function to login into system with registered credentials
//****************************************************************

int Credentials::login()
{
    system("cls");
    cout<<"\nPlease enter your username and password"<<endl;
    cout<<"USERNAME: ";
    cin>>user;
    cout<<"PASSWORD: ";
    cin>>pass;
    
    ifstream read("login_database.txt",ios ::in);
    while(read>>user_2>>pass_2>>privilege)
    {
            if(user_2==user && pass_2==pass && privilege == "A")
            {
                count=10;
                system("cls");
            }
            
            else if(user_2==user && pass_2==pass && privilege == "C")
            {
                count=20;
                system("cls");
            }
    }
    read.close();
    if(count==10)
    {
        cout<<"\nHello "<<user<<"\nLOGIN SUCCESS\nWe're glad that you're here.\nThanks for logging in!\n\n";
        cin.get();
        cout<<"You are an admin with elevated privilges.\n";
        cin.get();
        return 10;
    }
    else if(count==20)
    {
        cout<<"You are a customer.\n";
        cin.get();
        return 20;
    }
    else
    {
            cout<<"\nLOGIN ERROR\nPlease check your username and password.\n";
            cin.get();
            cin.get();
    }
    cin.get();
    ad.welcome(0);
	return 0;               
}

//****************************************************************
// function to register new Administrator and Customers
//****************************************************************

void Credentials::registration(int a)
{  
    system("cls");
    cout<<"Enter the username: ";
    cin>>new_user;
    cout<<"\nEnter the password: ";
    cin>>new_pass;
    if(a==1)
    {
        cout<<"Please confirm you are an admin user? Y/N ";
        cin>>chosen;
     	if(chosen == 'Y' ||  chosen == 'y')
	    	privilege='A';
	    else
            privilege='C';
	}
    
    ofstream reg("login_database.txt",ios :: app);
    reg<<new_user<<' '<<new_pass<<' '<<privilege<<endl;
    cout<<"\nRegistration Successful\n";
    system("cls");
    ad.welcome(0);
}

// Aleternative Advanced method for user registration

void Credentials::registrationAdvanced(int a)
{
    bool check_status = true;

	system("cls");
    cout << "\n===================================\n";
	cout << "\n   **** Create New Account **** \n";
    cout << "\n===================================\n";
	
    //username Validation
    while(check_status)
    {
        cout << "Enter Your Username: ";
	    getline(cin>>ws, new_user);
	    minimum_size = new_user.length();
	
	    fstream read("login_database.txt",ios::in);
	    if(minimum_size >= 3)
	    {
	        if(read && registration_status != true && read.is_open())
	        {
	            while(read>>search_user>>search_pass>>chosen)
	            {
	                stringstream users(search_user);
	                users >> valid_name;
	                if(new_user == valid_name)
	                {
	                    cout <<"\n*"<< new_user <<"* username already exists! Please try another username.\n" << endl;
	                    registration_status = true;
	                } 
	            }
	            read.close();
	            if(registration_status)
	            {      
	            	registration_status = false;
	            }
	            else
	            {
	                check_status = false;
	            }
	        }
	        else
        		check_status = false;
		}
    }
	
	//password Validation
	while(true)
	{
	    cout << "Enter Your password: ";
	    getline(cin>>ws,new_pass);
	    cout << "Confirm Your password: ";
	    getline(cin>>ws,confirm_pass);
	    minimum_size = new_pass.length();
	
	    if (minimum_size < 3)
		{
	        cout << "\nYour password is weak, Enter at least 3 letters\n \n";
	    }
	    else if(confirm_pass == new_pass)
		{
	        fstream reg;
	        reg.open("login_database.txt",fstream::app);
	        
			if(a==1)
	        {
	            cout<<"Please confirm you are an admin user? Y/N ";
	            cin>>chosen;
	            if(chosen=='Y' || chosen=='y')
	            	privilege='A';
                else
                    privilege='C';
	        }
	        else
				privilege='C';
            
	        if(reg.is_open()){
	            reg << new_user +" "+ new_pass + " "+privilege<< endl;
	            reg.close();
	        }
	        cout << "\n===================================\n";
	        cout << "\n Successfully created your account! \n";
	        cout << "\n===================================\n";
	    	cin.get();
	        break;
		}
		else
		{
	        cout << "\nPasswords are not matching! Try again. \n" << endl;
	    }
	}
	cin.get();
	ad.welcome(0);
}

//****************************************************************
// function to search for retrieve forgotten username / password
//****************************************************************

void Credentials::forgot()
{
    system("cls");
    try
    {
        cout<<"\nForgotten? We're here for help.\n";
        cout<<"\n1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Go back\n"<<endl;
        cout<<"Enter your choice: ";
        cin>>selection;
        
        ss << selection; ss >> choice;
        ss.clear();
        switch(choice)
        {
            case 1:
            {
                cout<<"\nEnter your last known username: ";
                cin>>search_user;
                
                ifstream read("login_database.txt",ios :: in);
                while(read>>search_user_2>>search_pass_2>>chosen)
                {

                    if(search_user_2==search_user)
                    {
                        count=1;
                        break;
                    }
                }
                read.close();
                if(count==1)
                {
                    cout<<"\n\nHurrah, account found\n";
                    cout<<"\nYour password is "<<search_pass_2;
                    cin.get();
                    cin.get();
                    system("cls");
                    ad.welcome(10);
                }
                else
                {
                    cout<<"\n\nSorry, your userID is not found in the database.\n";
                    cout<<"\nPlease contact system administrator for more details.\n";
                    cin.get();
                    cin.get();
                    ad.welcome(10);
                }
                break;
            }
            
            case 2:
            {
                cout<<"\nEnter your last known password: ";
                cin>>search_pass;

				fstream read("login_database.txt",ios :: in);
                while(read>>search_user_2>>search_pass_2>>chosen)
                {
                	
                    if(search_pass_2==search_pass)
                    {
                        count=1;
                        break;
                    }       
                }
                read.close();
                if(count==1)
                {
                    cout<<"\nYour password is found in the database.\n";
                    cout<<"\nYour Id is : "<<search_user_2;
                    cin.get();
                    cin.get();
                    system("cls");
                    ad.welcome(0);
                }
                else
                {
                    cout<<"Sorry, We could not find your password in our database!\n";
                    cout<<"\nPlease contact the administrator for more information\n";
                    cin.get();
                    cin.get();
                    ad.welcome(0);
                }
        
                break;
            }
            
            case 3:
            {
                ad.welcome(0);
                break;
            }
            default:
	            cout<<"\nException 2";
	            cout<<"\n\nSelect only from the options provided. Please try again!\n"<<endl;
	            cin.get(); cin.get();
	            throw(10);
            }
    	}
    	
    catch(int i)
    {
        cout<<"Please select only the correct option provided.";
        system("PAUSE");
//        sleep(5);
		exit(2);
    }
	forgot();
}

//****************************************************************
// function to search for create new Customer Information
//****************************************************************

void Administration::writeCustomer()	    
{	
	fs.open("customers_database.txt", ios :: out | ios :: app);
    cr.createCustomer();
    fs.write((char * ) & cr, sizeof(Customer));
    fs.close();
    cout << "\n\nThe Customer account has been created.\n";
    cin.get();
	cin.get();
	system("cls");
}

//****************************************************************
// function to manage customer information in CBS
//****************************************************************

void Customer::adminPage()
{
	system("cls");
	cout<<"\n==============================================================\n";
	cout<<"\n\t\tCUSTOMER BILLING SYSTEM\n";
	cout<<"\n==============================================================\n\n";
	cout<<"1:\tTo add customer account(s) on system\n";
	cout<<"2:\tTo search customer account(s)\n";
	cout<<"3:\tGo back\n";
	cout<<"\n==============================================================\n";

  	cout<<"\nSelect what do you want to do? (1-3) ";
   	cin>>chosen;

    ss << chosen; ss >> choice;
    ss.clear();

	switch(choice)
	{
	case '1':
		system("cls");
		cout<<"\nHow many Customer Accounts? ";
		cin>>n;
		
		for(i=0;i<n;i++){
			ad.writeCustomer();
		}
		system("cls");
		adminPage();
	case '2':
		search:
		system("cls");
		try
		{
	//		do{
		        cout<<"\n\tSelect how do you want to search? ";
				cout<<"\n\t1:\tCustomer Account Number\n";
				cout<<"\t2:\tCustomer Name\n";
				cout<<"\t3:\tView all\n";
				cout<<"\t4:\tGo back\n";
				cout<<"\n\tPlease enter your choice (1-4) ";
				cin>>choice;
	//		}while(choice<=0 || choice>4);
			if(choice == '1' || choice == '2' || choice == '3' || choice == '4')
		    {
				adminSearch(choice);
				// main();
				goto search;
			}
			else
		    {
		    	system("cls");
		    	cout<<"Exception 3";
		    	throw(10);	
			}
		}
		catch(int i)
	    {
	    	cout<<"Please select only from the options provided.";
        	system("PAUSE");
    		// sleep(5);
			 exit(3);
//	    	goto search;
		}	
	case '3':
		system("cls");
		pr.adminMenu();
  	}
}

//****************************************************************
// function to search for Customer Records for Customers
//****************************************************************

void Customer::customerPage()
{
	system("cls");
	cout<<"\n==============================================================\n";
	cout<<"\n\t\tCUSTOMER BILLING SYSTEM\n";
	cout<<"\n==============================================================\n";
	cout<<"1:\tVIEW YOUR ACCOUNT INFORMATION\n";
    cout<<"2:\tPLACE A NEW ORDER\n";
	cout<<"3:\tLOGOUT\n";
	cout<<"\n==============================================================\n";
	
	do{
	   cout<<"\nSelect what do you want to do? (1-3) ";
	   cin>>choice;
	}while(choice<= '0' || choice>'3');
	
	switch(choice){
	case '1':
		search:
		system("cls");
		try
		{
	//		do{
		        cout<<"\n\tEnter your Customer Account Information: ";
				cout<<"\n\t1:\tCustomer Number\n";
				cout<<"\t2:\tCustomer Name\n";
				cout<<"\t3:\tGo back\n";
				cout<<"\n\tPlease enter your choice (1-3) ";
				cin>>choice;
	//		}while(choice<=0 || choice>3);
			if(choice == '1' || choice == '2' || choice == '3' || choice == '4')
		    {
				cr.customerSearch(choice); // Calling the function to search the customers_database.txt file
				
                goto search; // Go back to search line again and continue.
			}
			else
		    {
		    	system("cls");
		    	cout<<"Exception 4";
		    	throw(10);
			}
		}
		catch(int i)
	    {
	    	cout<<"Please select only from the options provided.";
        	system("PAUSE");
    		// sleep(5);
			 exit(4);
//	    	goto search;
		}
    case '2':
		ad.placeOrder();
		cr.customerPage();
		break;
	case '3':
		ad.welcome(0);
		break;
  }
}

//****************************************************************
// function to search Customer Records for Admin users
//****************************************************************

void Customer::adminSearch(char option)
{
	system("cls");
	int search_number; string search_name;
	
	if(option == '1')
	{
		cout<<"\n\tEnter the Customer Account Number: ";	
		cin>>search_number;
        cout<<endl;

		fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        if (cr.kyc.account_number == search_number)
	        {
//	        	system("cls");
	            cr.viewCustomer();
	            flag = 1;
	            cin.get();
	            cin.get();
        	}
    	}
		fs.close();
		if (flag == 0)
		{
			cout << "\n\n\tRecord does not exist";
			cin.get();
			cin.get();
		}
	}	
	else if(option == '2')
	{
		cout<<"\n\tEnter the Customer Account Name: ";
		getline(cin>>ws,search_name);

		fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        if (cr.kyc.name == search_name)
	        {
//	            system("cls");
	            cr.viewCustomer();
	            flag = 1;
	            cin.get();
	        }
	    }
	    fs.close();
	    if (flag == 0)
	        cout << "\n\n\tRecord does not exist";
	    cin.get();
	}
	else if(option == '3')
	{
		system("cls");
	    cout << "\n\n\t\t\tDISPLAY ALL RECORD !!!\n\n";
	    fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer)))
	    {
	        cr.viewCustomer();
            flag = 1;
	        cout <<"\n\t==========================================================\n";
	    }
	    fs.close();
	    if (flag == 0)
	        cout << "\n\n\tRecord does not exist";
	    cin.get();
	    cin.get();
	}
    else if(option == '4')
    {
        cr.adminPage();
    }
    else
		cin.get();
}

//****************************************************************
// function to search customer records for Customers
//****************************************************************

void Customer::customerSearch(char option)
{
	system("cls");
	int search_number; string search_name;
	
	if(option == '1')
	{
		cout<<"\n\tEnter the Customer Account Number: ";	
		cin>>search_number;
        cout<<endl;

		fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        if (cr.kyc.account_number == search_number)
	        {
	            cr.viewCustomer();
	            flag = 1;
	            cin.get();
	            cin.get();
        	}
    	}
		fs.close();
		if (flag == 0)
		{
			cout << "\n\n\tRecord does not exist";
			cin.get();
			cin.get();
		}
	}	
	else if(option == '2')
	{
		cout<<"\n\tEnter the Customer Account Name: ";
		getline(cin>>ws,search_name);
		
		fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        if (cr.kyc.name == search_name)
	        {
	            cr.viewCustomer();
	            flag = 1;
	            cin.get();
	        }
	    }
	    fs.close();
	    if (flag == 0)
	        cout << "\n\n\tRecord does not exist";
	    cin.get();
	}
	else if(option == '3')
		customerPage();
}

//****************************************************************
// function to write in file
//****************************************************************

void Administration::writeProduct()
{
    cout<<"\n\tHow many Products to create? ";
	cin>>counter;
		
	for(int i=0;i<counter;i++)
	{		
		fs.open("shopping_database.txt", ios ::out | ios ::app);
    	pr.createProduct();
    	fs.write((char * ) & pr, sizeof(Product));
    	fs.close();
    	cin.get();
	}

    cout << "\n\nThe Product(s) Created Successfully.";
    cin.get();
    // cin.get();
}

//****************************************************************
// function to read all records from file
//****************************************************************

void Product::displayAll()
{
    system("cls");
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fs.open("shopping_database.txt", ios :: in );
    while (fs.read((char * ) & pr, sizeof(Product))) 
    {
        pr.showProduct();
        cout <<"\n==========================================================\n";
    }
    fs.close();
    cin.get();
    cin.get();
}

//****************************************************************
// function to read specific record from file
//****************************************************************

void Administration::displaySpecific(int n)
{
    fs.open("shopping_database.txt", ios :: in );
    while (fs.read((char * ) & pr, sizeof(Product))) 
    {
        if (pr.retpno() == n) 
        {
            pr.showProduct();
            flag = 1;
            cin.get();
        }
    }
    cin.get();
    fs.close();
    if (flag == 0)
        cout << "\n\nRecord does not exist";
//    cin.get();
}

//****************************************************************
// function to modify record of file
//****************************************************************

void Administration::modifyProduct() 
{
    system("cls");
    cout << "\n\n\t\tModify Record";
    cout << "\n\n\tPlease Enter The Product Number of Product: ";
    cin >> search_number;
    fs.open("shopping_database.txt", ios::in | ios::out);
    while (fs.read((char * ) & pr, sizeof(Product)) && found == 0) 
    {
        if (pr.retpno() == search_number)
        {
            pr.showProduct();
            cin.get();
            cout << "\n\n\tPlease Enter The New Details of Product " << endl;
            pr.createProduct();
            long long int pos = -1 * sizeof(pr);
            fs.seekp(pos, ios ::cur);
            fs.write((char * ) & pr, sizeof(Product));
            cout << "\n\n\tRecord Updated";
            found = 1;
            cin.get();
        }
    }
    fs.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    cin.get();
}

//****************************************************************
// function to delete record of file
//****************************************************************

void Administration::deleteProduct()
{
    system("cls");
    cout << "\n\n\n\t\tDelete Record";
    cout << "\n\n\tPlease Enter The Product Number that You Want To Delete: ";
    cin >> search_number;
    fs.open("shopping_database.txt", ios :: in | ios :: out);
    fstream fs2;
    fs2.open("temp.txt", ios ::out);
    fs.seekg(0, ios ::beg);
    while (fs.read((char * ) & pr, sizeof(Product))) 
    {
        if (pr.retpno() != search_number) 
        {
            fs2.write((char * ) & pr, sizeof(Product));
        }
        	
    }
    fs2.close();
    fs.close();
    remove("shopping_database.txt");
    rename("temp.txt", "shopping_database.txt");
    cout << "\n\n\tRecord Deleted.";
    cin.get();
}

//****************************************************************
// function to display all products price list
//****************************************************************

void Product::productMenu() 
{
    system("cls");
    fs.open("shopping_database.txt", ios::in );
    if (!fs) 
    {
        cout << "\n\n\nERROR!!! FILE COULD NOT BE OPENED\n\n\nGo To Admin Menu to Create New File";
        cin.get();
        pr.adminMenu();
    }
    cin.get();

    cout << "\n\n\t\tProduct MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fs.read((char * ) & pr, sizeof(Product))) 
    {
        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
    }
    fs.close();
    cin.get();
}

//****************************************************************
// function to place order and generating bill for Products
//****************************************************************

void Administration::placeOrder()
{
    system("cls");
	cout<<"\nEnter your Customer Account Number: ";
	cin>>search_number;
    pr.productMenu();
    cout << "\n====================================================";
    cout << "\n\t\t PLACE YOUR ORDER";
    cout << "\n====================================================\n";
    do 
    {
        cout << "\n\nEnter Product Number Of The Product: ";
        cin >> order_array[counter];
        cout << "\nQuantity in number : ";
        cin >> quantity[counter];
        counter++;
        cout << "\nDo You Want To Order Another Product? (Y/N) ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    // cin.get();
    cout << "\n\nThank You For Placing The Order";
    cin.get();
    system("cls");
    cout << "\n\n*************************** INVOICE ****************************\n";
    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAfter discount\n";
    for (int x = 0; x <= counter; x++) 
    {
        fs.open("shopping_database.txt", ios:: in );
        fs.read((char * ) & pr, sizeof(Product));
        while (!fs.eof())
        {
            if (pr.retpno() == order_array[x]) 
            {
                amount = pr.retprice() * quantity[x];
                discount_amount = amount - (amount * pr.retdis() / 100);
                cout << "\n" << order_array[x] << "\t" << pr.retname() <<
                    "\t" << quantity[x] << "\t\t" << pr.retprice() << "\t" << amount << "\t\t" << discount_amount;
                total += discount_amount;
            }
            fs.read((char * ) & pr, sizeof(Product));
        }
        fs.close();
	}

    cout << "\n\n\t\t\t\t\t\tTOTAL = " << total;
    
	fs.open("customers_database.txt", ios :: in | ios :: out );
//    fs.read((char * ) & cr, sizeof(Customer));
    while (fs.read((char * ) & cr, sizeof(Customer))) 
	{
	    if(cr.kyc.account_number == search_number)
	    {
    		cr.kyc.bill_dues += total;
    		flag = 1;
    		cout<<"\n\nYour Total Outstanding Bills = "<<cr.kyc.bill_dues;
    		cin.get();
    		fs.write((char * ) & cr, sizeof(Product));
    	}
	}
	if(flag == 0)
		cout<<"\n\nPlease re-check your Customer Account Number and order again!!!";

    fs.close();
    cin.get();
}

//****************************************************************
// INTRODUCTION FUNCTION
//****************************************************************

void introduction()
{
    system("cls");
    
    cout <<"\n\n\n";
	cout<<"\t\t  CUSTOMER BILLING SYSTEM by "<<ad.developer;
	cout<<"\n\n\n";
 
//    cin.get();

}

//****************************************************************
// ADMINSTRATOR MENU FUNCTION
//****************************************************************
void Product::adminMenu() 
{
    system("cls");
    cout<<"************************************************************************\n\n";
    cout<<"                        Welcome to Admin Page                           \n\n";
    cout<<"************************      ADMIN MENU     ***************************\n\n";
    cout << "\n\n\t1.CREATE PRODUCT";
    cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
    cout << "\n\n\t3.SEARCH";
    cout << "\n\n\t4.MODIFY PRODUCT";
    cout << "\n\n\t5.DELETE PRODUCT";
    cout << "\n\n\t6.PRODUCT MANAGEMENT";
    cout << "\n\n\t7.CUSTOMER MANAGEMENT";
    cout << "\n\n\t8.LOGOUT";
    cout << "\n\n\tPlease Enter Your Choice (1-8) ";
	cin>>chosen;

    ss << chosen; ss >> choice;
    ss.clear();

    switch(choice)
    {
    case '1':
        system("cls");
        ad.writeProduct();
        break;
    case '2':
        displayAll();
        break;
    case '3':
        system("cls");
        cout << "\n\n\tPlease Enter The Product Number: ";
        cin >> product_number;
        ad.displaySpecific(product_number);
        break;
    case '4':
        ad.modifyProduct();
        break;
    case '5':
        ad.deleteProduct();
        break;
    case '6':
        productMenu();
        break;
    case '7':
        cr.adminPage();
        break;
    case '8':
        ad.welcome(0);
        break;
    default:
        cout << "\a";
    }
    adminMenu();
}

/*
Thank you!
*/