/*
Title - CUSTOMER BILLING SYSTEM (Project Version 1.1) && Submission Date - October 28, 2022
A Project by SRI VISHNU JSB
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<conio.h>
#include<stdlib.h>

using namespace std;

//Custom Function declartions for various functionalities
// void intro();
// void adminMenu();
// void welcome(int a);
// void writeProduct();
// void displayAll();
// void productMenu();
// void modifyProduct();
// void deleteProduct();
// void displaySpecific(int n);


void placeOrder();

// Class for introduction and various functions
class Administration
{
	string creator = "SRI VISHNU JSB";
    public:
    	friend void intro();

        string returnCreator()
        {
        	return creator;
		}
};

// class for handling login, registration and forgot credentials 
class Credentials
{
    private:
        int count=0;
        string user,pass,u,p,a,admin;
    
    public:
        int login();
        void registration(int a);
        void registrationAdvanced(int a);
        void forgot();
};

// class for managing all the customer related information 
class Customer:public Credentials
{
    static int counter;
    char acct_type;
    int entry_number, acct_no, mobile_no;
    string name, street, city, date;
    float oldbalance, newbalance, payment;

	public:		
		void createCustomer();	
		void viewCustomer();
        void cbsAdmin();
        void cbsCustomer();
        void searchAdmin(char ch);
        void searchCustomer(char ch);
};

// class for managing the products and billing related functions
class Product:public Customer
{
    int pno, no, flag = 0, found = 0, c = 0;
    int order_arr[50], quan[50];
    float price, qty, tax, dis, amt, damt, total = 0;
    char ch = 'Y', ch2;
    string name;

    public:
        // Reserved Functions, can be used as member functions if necessary
        void adminMenu();
        void welcome(int a);
        void writeProduct();
        void displayAll();
        void productMenu();
        void modifyProduct();
        void deleteProduct();
        void displaySpecific(int n);

        void createProduct() 
        {
            cout << "\nPlease Enter The Product Number for The Product ";
            cin >> pno;
            cout << "\n\nPlease Enter The Name of The Product ";
            getline(cin>>ws,name);
            cout << "\nPlease Enter The Price of The Product ";
            cin >> price;
            cout << "\nPlease Enter The Discount (%) ";
            cin >> dis;
        }

        void showProduct() 
        {
            cout << "\nThe Product Number of The Product : " << pno;
            cout << "\nThe Name of The Product : "<< name;
            cout << "\nThe Price of The Product : " << price;
            cout << "\nDiscount : " << dis;
        }

        int retpno() 
        {
            return pno;
        }

        float retprice() 
        {
            return price;
        }

        string retname() 
        {
            return name;
        }

        int retdis() 
        {
            return dis;
        }

}; //class ends here

//***************************************************************
// global declaration for stream object, objects
//****************************************************************

int Customer::counter=100;

fstream fs;
Administration ad;
Credentials cs;
Customer cr;
Product pr;

//****************************************************************
// The MAIN fuction which manages rest of CBS fucntions/program
//****************************************************************

int main()
{
    char choice;
    system("cls");
    intro();
    try
    {
        do
        { 
            cout<<"\n=======================================================================\n";
            cout<<"\n\t\t\tCUSTOMER BILLING SYSTEM\n";
            cout<<"\n=======================================================================\n";   
            cout<<"***********************************************************************\n\n";
            cout<<"                       Welcome to CBS Portal                               \n\n";
            cout<<"************************        MENU       ****************************\n\n";
            cout<<"1.ADMINISTRATOR"<<endl;
            cout<<"2.CUSTOMER"<<endl;
            cout<<"3.EXIT"<<endl;
            cout<<"\nPlease select your option (1-3) ";
            cin>>choice;

            if(choice == '1' || choice == '2' || choice == '3')
            {
                switch(choice)
                {
                    case '1':
                        welcome(1);
                    case '2':
                        welcome(2);
                    case '3':
                        cout<<"\nThanks for using this program!!!\n\n";
						cout<<"This program is created by "<<ad.returnCreator()<<"\n";
                        exit(0);
                    default:
                        system("cls");
                        cout<<"\a"<<endl;
                }
            }
            else
            {
                system("cls");
                cout<<"Exception";
                throw(10);
            }
        } while (choice !=3);
    }
    catch(int i)
    {
        cout<<"Please select only correct option provided.";
        main();
    }  
}

//****************************************************************
// function for the management of CBS - Customer Billing System
//****************************************************************

void welcome(int a)
{
	char choice; int status;
	system("cls");
	try
	{	
		cout<<"***********************************************************************\n\n";
      	cout<<"                        Welcome to login page                            \n\n";
        cout<<"************************      MAIN MENU     ***************************\n\n";

		cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTER"<<endl;
        cout<<"3.FORGOT USERNAME or PASSWORD"<<endl;
        cout<<"4.GO BACK"<<endl;
        cout<<"\nA Project by "<<ad.returnCreator();
        cout<<"\n\nSelect an option to continue (1-4) ";
        cin>>choice;
        cout<<endl;
    	
    	if(choice == '1' || choice == '2' || choice == '3' || choice == '4')
	    {
	        switch(choice)
        	{
                case '1':
                  	status=cs.login();
					if(status==10)
					{
						// cr.cbsAdmin();
                        adminMenu();
                        break;
					}
					else if(status==20)
					{
						// cr.cbsCustomer();
                        system("cls");
                        cr.cbsCustomer();
                        placeOrder();
                        getch();
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
                    cout<<"Please select correct option and try again\n"<<endl; 
        	}	
    	}
        else
        {
        	system("cls");
        	cout<<"Exception";
        	throw(10);	
		}
	}
    catch(int i)
    {
    	cout<<"Please select only correct option provided.";
    	welcome(0);
	}
}

//****************************************************************
// function to login into system with registered credentials
//****************************************************************

int Credentials::login()
{
    int count;
    string user,pass,u,p,a,admin;
    system("cls");
    cout<<"Please enter your username and password"<<endl;
    cout<<"USERNAME: ";
    cin>>user;
    cout<<"PASSWORD: ";
    cin>>pass;
    
    ifstream read("login_credentials.txt",ios ::in);
    while(read>>u>>p>>admin)
    {
            if(u==user && p==pass && admin == "Y")
            {
                count=10;
                system("cls");
            }
            
            else if(u==user && p==pass && admin == "N")
            {
                count=20;
                system("cls");
            }
    }
    read.close();
    if(count==10)
    {
        cout<<"\nHello "<<user<<"\nLOGIN SUCCESS\nWe're glad that you're here.\nThanks for logging in!\n";
        // cin.get();
        cout<<"You are an admin with elevated privilges.\n";
        return 10;
    }
    else if(count==20)
    {
        cout<<"You are a customer.\n";
        // cin.get();
        return 20;
    }
    else
    {
            cout<<"\nLOGIN ERROR\nPlease check your username and password.\n";
            cin.get();
            getch();
    }
    welcome(0);
	return 0;               
}

//****************************************************************
// function to register new Administrator and Customers
//****************************************************************

void Credentials::registration(int a)
{  
    string reguser,regpass,ru,rp,admin;
    system("cls");
    cout<<"Enter the username: ";
    cin>>reguser;
    cout<<"\nEnter the password: ";
    cin>>regpass;
    if(a==1)
    {
        cout<<"Please confirm you are an admin user? Y/N ";
        cin>>admin;
        admin="Y";
    }
    else
        admin="N";
    
    ofstream reg("login_credentials.txt",ios ::app);
    reg<<reguser<<' '<<regpass<<' '<<admin<<endl;
    system("cls");
    cout<<"\nRegistration Successful\n";
    welcome(0);           
}

// Aleternative Advanced method for user registration

void Credentials::registrationAdvanced(int a)
{
    string new_username,validate_name,new_password,confirm_password;
    string read_users;
	int minimum_size;
	bool registration_status = false;
	bool status = true;
	system("cls");
    cout << "\n===================================\n";
	cout << "\n   **** Create New Account **** \n";
    cout << "\n===================================\n";
	
    //username Validation
    while(status)
    {
        cout << "Enter Your Username: ";
	    getline(cin>>ws, new_username);
	    minimum_size = new_username.length();
	
	    fstream read("login_credentials.txt",ios ::in);
	    if(minimum_size >= 3)
	    {
	        if(read && registration_status != true && read.is_open())
	        {
	            while(read>>user)
	            {
	                stringstream users(user);
	                users >> validate_name;
	                if(new_username == validate_name)
	                {
	                    cout <<"\n*"<< new_username <<"* username already exists! Please try another username.\n" << endl;
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
	                status = false;
	            }
	        }
	        else
        		status = false;
		}
    }
	
	//password Validation
	while(true)
	{
	    cout << "Enter Your password: ";
	    getline(cin>>ws,new_password);
	    cout << "Confirm Your password: ";
	    getline(cin>>ws,confirm_password);
	    minimum_size = new_password.length();
	
	    if (minimum_size < 3)
		{
	        cout << "\nYour password is weak, Enter at least 3 letters\n \n";
	    }
	    else if(confirm_password == new_password)
		{
	        fstream reg;
	        reg.open("login_credentials.txt",fstream::app);
	        
			if(a==1)
	        {
	            cout<<"Please confirm you are an admin user? Y/N ";
	            cin>>admin;
//	            admin="Y";
	        }
	        else
            	admin="N";
            
	        if(reg.is_open()){
	            reg << new_username +" "+ new_password + " "+admin<< endl;
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
	welcome(0);
}

//****************************************************************
// function to search for retrieve forgotten username / password
//****************************************************************

void Credentials::forgot()
{
    char ch, choice;
    int count;
    string search_user,su,sp;
    string search_pass,su2,sp2;
    
    system("cls");
    try
    {
        cout<<"\nForgotten? We're here for help.\n";
        cout<<"\n1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Go back\n"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        if(choice == '1' || choice == '2' || choice == '3')
        {
            switch(choice)
            {
                case '1':
                {
                    cout<<"\nEnter your last known username: ";
                    cin>>search_user;
                    
                    fstream read("login_credentials.txt",ios ::in);
                    while(read>>su>>sp>>ch)
                    {
                        if(su==search_user)
                        {
                            count=1;
                        }
                    }
                    read.close();
                    if(count==1)
                    {
                        cout<<"\n\nHurrah, account found\n";
                        cout<<"\nYour password is "<<sp;
                        cin.get();
                        cin.get();
                        system("cls");
                        welcome(10);
                    }
                    else
                    {
                        cout<<"\n\nSorry, our userID is not found in our database\n";
                        cout<<"\nPlease contact system administrator for more details \n";
                        cin.get();
                        cin.get();
                        welcome(10);
                    }
                    break;
                }
                
                case '2':
                {
                    cout<<"\nEnter your last known password: ";
                    cin>>search_pass;

					fstream read("login_credentials.txt",ios ::in);
                    while(read>>su2>>sp2>>ch)
                    {
                        if(sp2==search_pass)
                        {
                            count=1;
                        }       
                    }
                    read.close();
                    if(count==1)
                    {
                        cout<<"\nYour password is found in the database.\n";
                        cout<<"\nYour Id is : "<<su2;
                        cin.get();
                        cin.get();
                        system("cls");
                        welcome(0);
                    }
                    else
                    {
                        cout<<"Sorry, We could not find your password in our database!\n";
                        cout<<"\nPlease contact the administrator for more information\n";
                        cin.get();
                        cin.get();
                        welcome(0);
                    }
            
                    break;
                }
                
                case '3':
                {
                    welcome(0);
                    break;
                }
                default:
                    cout<<"Sorry, You selected an incorrect option. Please try again!"<<endl;
                    forgot();
            }
        }
        else
        {
            system("cls");
            cout<<"Exception";
            throw(10);
        }
    }
    catch(int i)
    {
        cout<<"Please select only the correct option provided.";
        forgot();
    }	
}

//****************************************************************
// function to search for create new Customer Information
//****************************************************************

void Customer::createCustomer()	    
{
	counter++;
	cout<<"\n	Serial Number : "<<counter;
//	serial_number=counter;
	cout<<"\n\n\t	Customer Account Number : ";
	cin>>acct_no;
	cout<<"\n\t	Name : ";
	cin>>name;
	cout<<"\n\t	Contact Number : ";
	cin>>mobile_no;
	cout<<"\n\t	Street : ";
	cin>>street;
	cout<<"\n\t	City : ";
	cin>>city;
	cout<<"\n\t	Previous balance : ";
	cin>>oldbalance;
	cout<<"\n\t	Current payment : ";
	cin>>payment;
	cout<<"\n\t	Payment date (mm/dd/yyyy) : ";
	cin>>date;
	cin.get();
	
    fs.open("customers_database.txt", ios ::out | ios ::app);
	system("cls");
    
	if(cr.payment>0)
	{
		cr.acct_type=(cr.payment<cr.oldbalance)? 'O' : 'L';
	}
	else
	{
		cr.acct_type=(cr.oldbalance>0)? 'O' : 'P';
	}

	cr.newbalance=cr.oldbalance - cr.payment;

    fs.write((char * ) & cr, sizeof(Customer));
    fs.close();
    cout << "\n\nThe Customer account has been created.\n";
    cin.get();
	getch(); 
}

//****************************************************************
// function to search for view Customer Information
//****************************************************************

void Customer::viewCustomer()
{
//	cout<<"\n\n\t	Serial Number: "<<serial_number;
	cout<<"\n\n\t\t	Name	       : "<<name;
	cout<<"\n\t		Mobile Number  : "<<mobile_no;
	cout<<"\n\t		Customer Customer Number : "<<acct_no;
	cout<<"\n\t		Street         : "<<street;
	cout<<"\n\t		City           : "<<city;
	cout<<"\n\t		Old balance    : "<<oldbalance;
	cout<<"\n\t		Current payment: "<<payment;
	cout<<"\n\t		New balance    : "<<newbalance;
	cout<<"\n\t		Payment date   : "<<date;
	cout<<"\n\t		Customer status : ";

	switch(acct_type)
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
		 			cout<<"ERROR\n\n";
	  }
}

//****************************************************************
// function to manage customer information in CBS
//****************************************************************

void Customer::cbsAdmin()
{
	int i, n;
	char choice;
	system("cls");
	cout<<"\n==============================================================\n";
	cout<<"\n\t\tCUSTOMER BILLING SYSTEM\n";
	cout<<"\n==============================================================\n\n";
	cout<<"1:\tTo add customer account(s) on system\n";
	cout<<"2:\tTo search customer account(s)\n";
	cout<<"3:\tGo back\n";
	cout<<"\n==============================================================\n";

  	cout<<"\nSelect what do you want to do? (1-3) ";
   	cin>>choice;

	
	switch(choice)
	{
	case '1':
		system("cls");
		cout<<"\nHow many customer accounts? ";
		cin>>n;
		for(i=0;i<n;i++){
			cr.createCustomer();
		}
		system("cls");
		cbsAdmin();
	case '2':
		search:
		system("cls");
		try
		{
	//		do{
		        cout<<"\n\tSelect how do you want to search? ";
				cout<<"\n\t1:\tCustomer Number\n";
				cout<<"\t2:\tCustomer Name\n";
				cout<<"\t3:\tView all\n";
				cout<<"\t4:\tGo back\n";
				cout<<"\n\tPlease enter your choice (1-4) ";
				cin>>choice;
	//		}while(ch<=0 || ch>4);
			if(choice == '1' || choice == '2' || choice == '3' || choice == '4')
		    {
				searchAdmin(choice);
		//		main();
				goto search;
			}
			else
		    {
		    	system("cls");
		    	cout<<"Exception";
		    	throw(10);	
			}
		}
		catch(int i)
	    {
	    	cout<<"Please select only correct option provided.";
	    	goto search;
		}
		
	case '3':
		system("cls");
		adminMenu();
  	}
}

//****************************************************************
// function to search for Customer Records for Customers
//****************************************************************

void Customer::cbsCustomer()
{
	int i, n;
	char choice;
	
	cout<<"\n==============================================================\n";
	cout<<"\n\t\tCUSTOMER BILLING SYSTEM\n";
	cout<<"\n==============================================================\n";
	cout<<"1:\tView Your Account Information\n";
    cout<<"2:\tPlace A New Order\n";
	cout<<"3:\tGo back\n";
	cout<<"\n==============================================================\n";
	
	do{
	   cout<<"\nSelect what do you want to do? (1-2) ";
	   cin>>choice;
	}while(choice<= '0' || choice>'2');
	
	switch(choice){
	case '1':
		search:
		system("cls");
		try
		{
	//		do{
		        cout<<"\n\tEnter your customer account detail: ";
				cout<<"\n\t1:\tCustomer Number\n";
				cout<<"\t2:\tCustomer Name\n";
				cout<<"\t3:\tGo back\n";
				cout<<"\n\tPlease enter your choice (1-3) ";
				cin>>choice;
	//		}while(ch<=0 || ch>3);
			if(choice == '1' || choice == '2' || choice == '3' || choice == '4')
		    {
				cr.searchCustomer(choice); // Calling the function to search the customers_database.txt file
				
                goto search; // Goback to search line again and continue.
	//			main();
			}
			else
		    {
		    	system("cls");
		    	cout<<"Exception";
		    	throw(10);
			}

            // do
            // {
            // cout<<"Would you like to place an order now? Y/N ";
            // cin>>choice;
            // if(choice == 'y' || choice == 'Y')
            //     placeOrder();
            // }while (choice == 'y' || choice == 'Y');

		}
		catch(int i)
	    {
	    	cout<<"Please select only correct option provided.";
	    	goto search;
		}
    case '2':
		placeOrder();
		break;
	case '3':
		welcome(0);
		break;
  }
}

//****************************************************************
// function to search customer records for Admin users
//****************************************************************

void Customer::searchAdmin(char ch)
{
	int n, flag = 0;
	string name;
	system("cls");
	
	if(ch == '1')
	{
		cout<<"\n\tEnter the Customer Number: ";
		cin>>n;
		
		fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        if (cr.acct_no == n)
	        {
	            system("cls");
	            cr.viewCustomer();
	            flag = 1;
        	}
    	}
	    fs.close();
	    if (flag == 0)
	        cout << "\n\nrecord not exist";
	    getch();
	}	
	else if(ch == '2')
	{
		cout<<"\n\tEnter the Customer Name: ";
		getline(cin>>ws,name);
		
		fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        if (cr.name == name)
	        {
	            system("cls");
	            cr.viewCustomer();
	            flag = 1;
	        }
	    }
	    fs.close();
	    if (flag == 0)
	        cout << "\n\nrecord not exist";
	    getch();
	}
	else if(ch == '3')
	{
		system("cls");
	    cout << "\n\n\t\t\tDISPLAY ALL RECORD !!!\n\n";
	    fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        cr.viewCustomer();
            flag = 1;
	        cout <<"\n\t==========================================================\n";
	        getch();
	    }
	    fs.close();
	    getch();
	    if (flag == 0)
	        cout << "\n\nRecord does not exist";
	    getch();
	}
    else if(ch == '4')
    {
        cr.cbsAdmin();
    }
    else
        productMenu();
}

//****************************************************************
// function to search customer records for Admin users
//****************************************************************

void Customer::searchCustomer(char ch)
{
	int n, flag = 0;
	string name;
	system("cls");
	
	if(ch == '1')
	{
		cout<<"\n\tEnter the Customer Number: ";
		cin>>n;
		
		fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        if (cr.acct_no == n)
	        {
	            system("cls");
	            cr.viewCustomer();
	            flag = 1;
        	}
    	}
	    fs.close();
	    if (flag == 0)
	        cout << "\n\nrecord not exist";
	    getch();
	}	
	else if(ch == '2')
	{
		cout<<"\n\tEnter the Customer Name: ";
		getline(cin>>ws,name);
		
		fs.open("customers_database.txt", ios :: in );
	    while (fs.read((char * ) & cr, sizeof(Customer))) 
	    {
	        if (cr.name == name)
	        {
	            system("cls");
	            cr.viewCustomer();
	            flag = 1;
	        }
	    }
	    fs.close();
	    if (flag == 0)
	        cout << "\n\nrecord not exist";
	    getch();
	}
	else if(ch == '3')
		cbsAdmin();
}

//****************************************************************
// function to write in file
//****************************************************************

void Product::writeProduct()
{
    fs.open("shopping_database.txt", ios ::out | ios ::app);
    pr.createProduct();
    fs.write((char * ) & pr, sizeof(Product));
    fs.close();
    cout << "\n\nThe Product Has Been Created ";
    getch();
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
        showProduct();
        cout << "\n\n====================================\n";
        getch();
    }
    fs.close();
    getch();
}

//****************************************************************
// function to read specific record from file
//****************************************************************

void Product::displaySpecific(int n)
{
    fs.open("shopping_database.txt", ios :: in );
    while (fs.read((char * ) & pr, sizeof(Product))) 
    {
        if (pr.retpno() == n) 
        {
            system("cls");
            pr.showProduct();
            flag = 1;
        }
    }
    fs.close();
    if (flag == 0)
        cout << "\n\nrecord not exist";
    getch();
}

//****************************************************************
// function to modify record of file
//****************************************************************

void modifyProduct() 
{
    system("cls");
    cout << "\n\n\tTo Modify ";
    cout << "\n\n\tPlease Enter The Product No. of The Product";
    cin >> no;
    fs.open("shopping_database.txt", ios :: in | ios ::out);
    while (fs.read((char * ) & pr, sizeof(Product)) && found == 0) 
    {
        if (pr.retpno() == no) 
        {
            pr.showProduct();
            cout << "\nPlease Enter The New Details of Product" << endl;
            pr.createProduct();
            long long int pos = -1 * sizeof(pr);
            fs.seekp(pos, ios ::cur);
            fs.write((char * ) & pr, sizeof(Product));
            cout << "\n\n\tRecord Updated";
            found = 1;
        }
    }
    fs.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getch();
}

//****************************************************************
// function to delete record of file
//****************************************************************

void Product::deleteProduct()
{
    system("cls");
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The product number of The Product You Want To Delete";
    cin >> no;
    fs.open("shopping_database.txt", ios :: in | ios ::out);
    fstream fs2;
    fs2.open("temp.txt", ios ::out);
    fs.seekg(0, ios ::beg);
    while (fs.read((char * ) & pr, sizeof(Product))) 
    {
        if (pr.retpno() != no) 
        {
            fs2.write((char * ) & pr, sizeof(Product));
        }
    }
    fs2.close();
    fs.close();
    remove("shopping_database.txt");
    rename("temp.txt", "shopping_database.txt");
    cout << "\n\n\tRecord Deleted ..";
    getch();
}

//****************************************************************
// function to display all products price list
//****************************************************************

void Product::productMenu() 
{
    system("cls");
    fs.open("shopping_database.txt", ios :: in );
    if (!fs) 
    {
        cout << "\n\n\nERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";
        cout << "\n\n\n Program is closing ....";
        getch();
        exit(0);
    }

    cout << "\n\n\t\tProduct MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fs.read((char * ) & pr, sizeof(Product))) 
    {
        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
    }
    fs.close();
}

//****************************************************************
// function to place order and generating bill for Products
//****************************************************************

void Product::placeOrder()
{
    productMenu();
    cout << "\n====================================================";
    cout << "\n\t\t PLACE YOUR ORDER";
    cout << "\n====================================================\n";
    do 
    {
        cout << "\n\nEnter Product Number Of The Product : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product ? (Y/N) ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";
    getch();
    system("cls");
    cout << "\n\n*************************** INVOICE ****************************\n";
    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
    for (int x = 0; x <= c; x++) 
    {
        fs.open("shopping_database.txt", ios :: in );
        fs.read((char * ) & pr, sizeof(Product));
        while (!fs.eof()) 
        {
            if (pr.retpno() == order_arr[x]) 
            {
                amt = pr.retprice() * quan[x];
                damt = amt - (amt * pr.retdis() / 100);
                cout << "\n" << order_arr[x] << "\t" << pr.retname() <<
                    "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
            fs.read((char * ) & pr, sizeof(Product));
        }
        fs.close();
    }
    cout << "\n\n\t\t\t\t\t\tTOTAL = " << total;
    getch();
}

//****************************************************************
// INTRODUCTION FUNCTION
//****************************************************************

void intro() 
{
    system("cls");
    
    cout <<"\n\n\n";
	cout<<"\t  ADVANCED CUSTOMER BILLING SYSTEM by "<<ad.creator;
	cout<<"\n\n\n";
 
//    getch();

}

//****************************************************************
// ADMINSTRATOR MENU FUNCTION
//****************************************************************
void Product::adminMenu() 
{
    system("cls");
    cout << "\n\n\n\tADMIN MENU";
    cout << "\n\n\t1.CREATE PRODUCT";
    cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
    cout << "\n\n\t3.SEARCH";
    cout << "\n\n\t4.MODIFY PRODUCT";
    cout << "\n\n\t5.DELETE PRODUCT";
    cout << "\n\n\t6.PRODUCT MANAGEMENT";
    cout << "\n\n\t7.CUSTOMER MANAGEMENT";
    cout << "\n\n\t8.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-7) ";
	cin>>ch2;

    switch(ch2)
    {
    case '1':
        system("cls");
        writeProduct();
        break;
    case '2':
        displayAll();
        break;
    case '3':
        int num;
        system("cls");
        cout << "\n\n\tPlease Enter The Product Number ";
        cin >> num;
        displaySpecific(num);
        break;
    case '4':
        modifyProduct();
        break;
    case '5':
        deleteProduct();
        break;
    case '6':
        productMenu();
        getch();
    case '7':
        cr.cbsAdmin();
    case '8':
        welcome(0);
        break;
    default:
        cout << "\a";
    }
    adminMenu();
}