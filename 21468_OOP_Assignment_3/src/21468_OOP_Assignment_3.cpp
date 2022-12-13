//============================================================================
// Name        : 21468_OOP_Assignment_3.cpp
// Author      : Om Panchwate
// Version     :
// Copyright   : PICT OOP Assignments
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

// Parent class
class Publication{
	private:
		string title;
		float price;

	public:
		Publication(){
			title = "";
			price = 0;
		}

		void add()
		{
			cout << "\n---Enter the Publication information---" << endl;
			cout << "Enter Title of the Publication : ";
			cin.ignore();
			getline(cin, title);
			cout << "Enter Price of Publication : ";
			cin >> price;
		}

		void display()
		{
			cout<<"Title : "<<title<<endl;
			cout<<"price : Rs. "<<price<<"/-"<<endl;
		}

};


class Book : public Publication{
	private:
		int page_count;

	public:
		Book()
		{
			page_count = 0;
		}

		void add_book()
		{
			try{
				add();  // Calling Base class method of Publication class

				cout<<"Enter the Page Count : ";
				cin>>page_count;

				if(page_count <= 0)
					throw page_count;
			}
			catch(...)
			{
				cout<<"Invalid page count...";
				page_count = 0;
			}
		}

		void book_display()
		{
			display();  // Calling Base class method of Publication class

			cout<<"Page count : "<<page_count<<" pages\n\n";
		}
};

class Tape : public Publication{
	private:
		float play_time;
	public :
		Tape()
		{
			play_time = 0;
		}

		void add_tape()
		{
			try
			{
				add();   // Calling Base class method of Publication class

				cout << "Enter the tape duration (in minutes) : ";
				cin >> play_time;

				if(play_time <= 0)
					throw play_time;
			}
			catch(...)
			{
				cout<<"Invalid play_time...";
				play_time = 0;
			}

		}

		void tape_display()
		{
			display();  // Calling Base class method of Publication class

			cout<<"Total tape duration : "<<play_time<<" min\n\n";
		}
};


int main()
{
//	Publication p;
//	p.addBook();
//	p.display();

	Book b[25];
	Tape t[25];

	int book_count = 0;
	int tape_count = 0;

	int choice;

	bool exit = false;

	while(!exit)
	{
		cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
 		cout << "\n--------------------MENU-----------------------";
		cout << "\n1. Add new Book";
		cout << "\n2. Add new Tape";
		cout << "\n3. Display Books Information";
		cout << "\n4. Display Tapes Information";
		cout << "\n5. Exit";

		cout << "\n\nEnter your choice : ";
		cin >> choice;

		switch(choice){
			case 1 : b[book_count].add_book();
					book_count++;
					break;

			case 2 : t[tape_count].add_tape();
					tape_count++;
					break;

			case 3 : for(int i=0; i < book_count; i++)
					{
						cout<<i+1<<") ";
						b[i].book_display();
					}
					break;

			case 4 : for(int i=0; i < tape_count; i++)
					{
						cout<<i+1<<") ";
						t[i].tape_display();
					}

					break;

			case 5 : cout<<"Exiting...";
					exit = true;
					break;
		}
	}


	return 0;
}























