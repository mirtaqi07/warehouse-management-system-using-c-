#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<iomanip>

using namespace std;
class WareHouse
{
	public:
		
		void insert();
		void display();
		void search();
		void update();
		void del();
		void out();
		void exit();
		
		struct entryProd
		{
			string prod_name, company;
			string upd_prod_name, upd_company;
			int prod_id, search;
			int quantity, count=0, upd_quantity, out_quantity, left_quantity;
			float unit_price, upd_unit_price;
		}entry;	 
	
};


int main()
{
	WareHouse obj;
	char choice;
	again:
	cout<<"\n\n\t--------->Menu<---------"
		<<"\n\n\t\t1 For Insert\n"
		<<"\t\t2 For Display\n"
		<<"\t\t3 For Search\n"
		<<"\t\t4 For Update\n"
		<<"\t\t5 For Delete\n"
		<<"\t\t6 For Out\n"
		<<"\t\t7 For Exit\n"
		<<"\t\t"
		<<"\n\t\t";
		choice = getch();
	cout<<"\n";
		

		switch(choice)
		{
		
			case '1':
				obj.insert();
				break;
			case '2':
				obj.display();
				break;
			case '3':
				obj.search();
				break;	
			case '4':
				obj.update();
				break;
			case '5':
				obj.del();
				break;
			case '6':
				obj.out();
				break;
			case '7':
				obj.exit();	
			default:
				cout<<"Invalid Operator\n";	
		}
		goto again;
	
	
	return 0;
}

void WareHouse :: insert()
{
back:
	fstream file, file1;
	cout<<"\n\t\tEnter ID of Product : ";	
	cin>>entry.prod_id;
	cin.ignore();
	cout<<"\n\t\tEnter Name of Product : ";
	cin>>entry.prod_name;
	cout<<"\n\t\tEnter Company of Product : ";
	cin>>entry.company;
	cout<<"\n\t\tEnter Quantity of Product : ";
	cin>>entry.quantity;
	cout<<"\n\t\tEnter Price of Product : ";
	cin>>entry.unit_price;
	
	file.open("E://taqi.csv", ios::out |ios::app);
	file<<"Product ID,Product Name,Product Company,Product Quantity,Product Price\n";
	file<<entry.prod_id<<","<<entry.prod_name<<","<<entry.company<<","
		<<entry.quantity<<","<<entry.unit_price<<"\n\n";
	if(entry.prod_id >= 1)
	{
		cout<<"\n\n";
		cout<<setw(40)<<"\tData is saved sucessfully";
		file1.open("E://taqi.txt", ios::out |ios::app);
		
		file1<<setw(30)<<entry.prod_id<<setw(20)<<entry.prod_name<<setw(20)<<entry.company<<setw(20)
		 <<entry.quantity<<setw(20)<<entry.unit_price<<"\n\n";	
	}
	else
	{
		cout<<"\n\n";
		cout<<setw(40)<<"\tProduct ID should be in digits\n\n";
		cout<<setw(40)<<"\tEnter your data again\n\n";
		getch();
		
		goto back;
	}
	

		
	
	
	file.close();
	file1.close();
}
void WareHouse :: display()
{
	fstream file1;
	string in;
	file1.open("E://taqi.txt", ios::in);
	if(!file1)
		{
			cout<<"File Opening Error...";
			exit();
		}
	else
	{	cout<<setw(30)<<"Product ID"<<setw(20)<<"Product Name"<<setw(20)<<"Product Company"
			<<setw(20)<<"Product Quantity"<<setw(20)<<"Product Price\n";
		while(getline(file1,in))
		{
			cout<<in<<endl;
		}
		file1.close();
		
	}
			
}	
void WareHouse :: search()
{
	fstream file1;
	file1.open("E://taqi.txt", ios::in);
	if(!file1)
		{
			cout<<"File Opening Error...";
			exit();
		}
	else
		{
			cout<<"\n\t\tEnter ID of Product : ";
			cin>>entry.search;
			file1>>entry.prod_id>>entry.prod_name>>entry.company>>entry.quantity>>entry.unit_price;
			while(!file1.eof())
			{
				if(entry.search == entry.prod_id)
				{
					cout<<setw(40)<<"Product Name     : "<<entry.prod_name<<endl;
					cout<<setw(40)<<"Product Company  : "<<entry.company<<endl;
					cout<<setw(40)<<"Product Quantity : "<<entry.quantity<<endl;
					cout<<setw(40)<<"Product Price    : "<<entry.unit_price;
					entry.count++;
					break;	
				}
					file1>>entry.prod_id>>entry.prod_name>>entry.company>>entry.quantity>>entry.unit_price;
			}		
			file1.close();
			if(entry.count == 0)
			cout<<"\n\t\tProduct ID Not Found...\n";
				
		}		
	
}
void WareHouse :: update()
{
	fstream file1,file2;
	file2.open("E://taqiUpdate.txt", ios::app | ios::out);
	file1.open("E://taqi.txt", ios::in);
	if(!file1)
		cout<<"\n\t\tFile Opening Error...";
	else
		{
			cout<<"\n"<<setw(30)<<"Enter Book ID : ";
			cin>>entry.search;
			file1>>entry.prod_id>>entry.prod_name>>entry.company>>entry.quantity>>entry.unit_price;
			while(!file1.eof())
			{
				if(entry.search == entry.prod_id)
				{
					cout<<setw(40)<<"\n\t\tNew Product Name     : ";
					cin>>entry.upd_prod_name;
					cout<<setw(40)<<"\n\t\tNew Product Company  : ";
					cin>>entry.upd_company;
					cout<<setw(40)<<"\n\t\tNew Product Quantity : ";
					cin>>entry.upd_quantity;
					cout<<setw(40)<<"\n\t\tNew Product Price    : ";
					cin>>entry.upd_unit_price;
					
					file2<<setw(30)<<entry.search<<setw(20)<<entry.upd_prod_name<<setw(20)<<entry.upd_company<<setw(20)
		 				<<entry.upd_quantity<<setw(20)<<entry.upd_unit_price<<"\n\n";
		 			entry.count++;	
		 			break;
						
				}	
				else
					file2<<setw(30)<<entry.prod_id<<setw(20)<<entry.prod_name<<setw(20)<<entry.company<<setw(20)<<entry.quantity<<setw(20)<<entry.unit_price<<"\n\n";
					
					file1>>entry.prod_id>>entry.prod_name>>entry.company>>entry.quantity>>entry.unit_price;
			}
					if(entry.count == 0)
					cout<<"\t\tProduct ID Not Found...\n";	
		}
					file1.close();
					file2.close();
					remove("E://taqi.txt");
					rename("E://taqiUpdate.txt", "E://taqi.txt");	
}

void WareHouse :: del()
{
	fstream file1, file2;
	file2.open("E://taqiUpdate.txt", ios::app | ios::out);
	file1.open("E://taqi.txt", ios::in);
	if(!file1)
		cout<<"\n\t\tFile Opening Error...";
	else
	{
		cout<<"\n\t\tEnter Product ID : ";
		cin>>entry.search;
		file1>>entry.prod_id>>entry.prod_name>>entry.company>>entry.quantity>>entry.unit_price;
		while(!file1.eof())
		{
			if(entry.search == entry.prod_id)
			{
				cout<<"\n\t\tProduct is deleted successfully...!";
				entry.count++;	
			}
			else
				file2<<setw(30)<<entry.prod_id<<setw(20)<<entry.prod_name<<setw(20)<<entry.company<<setw(20)<<entry.quantity<<setw(20)<<entry.unit_price<<"\n\n";
					
				file1>>entry.prod_id>>entry.prod_name>>entry.company>>entry.quantity>>entry.unit_price;
		}
		if(entry.count == 0)
		{
			cout<<"\t\tProduct ID Not Found...\n";
		}
		
	}
		file1.close();
		file2.close();
		remove("E://taqi.txt");
		rename("E://taqiUpdate.txt", "E://taqi.txt");	
}
void WareHouse :: out()
{
	
	fstream file1,file2;
	file2.open("E://taqiUpdate.txt", ios::app | ios::out);
	file1.open("E://taqi.txt", ios::in);
	if(!file1)
		cout<<"\n\t\tFile Opening Error...";
	else
	{
		cout<<setw(30)<<"Enter Product ID : ";
		cin>>entry.search;
		file1>>entry.prod_id>>entry.prod_name>>entry.company>>entry.quantity>>entry.unit_price;
		while(!file1.eof())
		{
			if(entry.search == entry.prod_id)
			{
				cout<<"\n\n"<<setw(30)<<"\n\t\tName of Product is : "<<entry.prod_name<<endl;
				cout<<setw(30)<<"\n\t\tName of Company is : "<<entry.company<<endl;
				cout<<setw(30)<<"\n\t\tQuantity of Product is : "<<entry.quantity<<endl;
				cout<<setw(30)<<"\n\t\tPrice of Product is : "<<entry.unit_price<<endl;
				
				cout<<"\n\n"<<setw(30)<<"Sell Product Out of "<<entry.quantity<<" : ";
				cin>>entry.out_quantity;
				
				entry.left_quantity = entry.quantity - entry.out_quantity;
				cout<<"\n"<<setw(30)<<"\n\t\tRemaining Product Quantity is : "
					<<entry.left_quantity<<endl;
		 		
				file2<<setw(30)<<entry.prod_id<<setw(20)<<entry.prod_name<<setw(20)<<entry.company<<setw(20)
					<<entry.left_quantity<<setw(20)<<entry.unit_price<<"\n\n";	
				entry.count++;
			}
			else
				file2<<setw(30)<<entry.prod_id<<setw(20)<<entry.prod_name<<setw(20)<<entry.company<<setw(20)<<entry.quantity<<setw(20)<<entry.unit_price<<"\n\n";
				
				file1>>entry.prod_id>>entry.prod_name>>entry.company>>entry.quantity>>entry.unit_price;
		}
		if(entry.count == 0)
			cout<<"\n\t\tProduct ID Not Found...";
		
		file1.close();
		file2.close();
		remove("E://taqi.txt");
		rename("E://taqiUpdate.txt", "E://taqi.txt");
		
	}
	
	
}
void WareHouse :: exit()
{
	exit();
	
}
