#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class library
{
public:
	string bookname[50], auname[50], ibook[100];
	int bookid[100], iid[100], fine[100];
	int q, B, p;
	int choice;
	string issuedate[100];
	string returndate[100];
	const int studentBookLimit = 3;
	const int staffBookLimit = 5;
	const int teacherBookLimit = 10;
	string sstatus;
	library()
	{
		bookname[0] = "harry potter";
		bookname[1] = "twilight";
		bookname[2] = "diwan-e-ghalib";
		bookname[11] = "for the love of physics";
		bookname[12] = "newtonian";
		bookname[13] = "einstein physics";
		bookname[21] = "calculus v1";
		bookname[22] = "calculus v2";
		auname[0] = "jk rowling";
		auname[1] = "stephenie meyer";
		auname[2] = "mirza ghalib";
		auname[11] = "walter lewin";
		auname[12] = "newton jr";
		auname[13] = "eintsein";
		auname[21] = "sir nadeem";
		auname[22] = "sir shoiab";
		bookid[0] = 1;
		bookid[1] = 2;
		bookid[2] = 3;
		bookid[11] = 12;
		bookid[12] = 13;
		bookid[13] = 14;
		bookid[21] = 22;
		bookid[22] = 23;
		for (int i = 0; i < 100; ++i)
		{
			fine[i] = 0;
		}
	}

	void addFine(int bookID, int amount)
	{
		fine[bookID - 1] += amount;
	}

	int calcFine(int bookID)
	{
		return fine[bookID - 1];
	}

	void removeFine(int bookID)
	{
		fine[bookID - 1] = 0;
	}

	void begin()
	{
		system("cls");
		// system("Color F5");

		cout << "\n\n\t\t     ~~~~~~~~ WElCOME TO THE MAIN MENU ~~~~~~~~";
		cout << "\n\n\n\n\t 1. Student";
		cout << "\n\n\t 2. Librarian";
		cout << "\n\n\t 3. Teacher";
		cout << "\n\n\t 4. Exit program";
		cout << "\n\n\n\t Enter your choice: ";
	}

	void booklist(int i)
	{

		system("cls");

		int b, j, r;

		system("cls");
		b = course(i);
		system("cls");

		if (b == 1)
		{

			r = 0;
			for (j = 0; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t~~" << r++ << "~~\n\n";
				cout << "Book Name: " << bookname[j] << endl;
				cout << "Author Name: " << auname[j] << endl;
				cout << "Book ID: " << bookid[j] << endl;
			}
		}
		else if (b == 2)
		{

			r = 0;
			for (j = 11; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t~~" << r++ << "~~\n\n";
				cout << "Book Name: " << bookname[j] << endl;
				cout << "Author Name: " << auname[j] << endl;
				cout << "Book ID: " << bookid[j] << endl;
			}
		}
		else if (b == 3)
		{

			r = 0;
			for (j = 21; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t~~" << r++ << "~~\n\n";
				cout << "Book Name: " << bookname[j] << endl;
				cout << "Author Name: " << auname[j] << endl;
				cout << "Book ID: " << bookid[j] << endl;
			}
		}

		begin();
	}

	int course(int x)
	{
		int i;
		cout << "\n\t\t>>Please Choose one Branch :-\n";
		cout << "\n\t\t1.Novels\n\n\t\t2.Physics\n\n\t\t3.Calculus\n\n\t\t4.Go to menu\n";
		cout << "\n\t\tEnter your choice : ";
		cin >> i;
		switch (i)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			system("cls");

			if (x == 1)
				begin();
			else
			{
				library::begin();
			}

		default:
			cout << "\n\t\tPlease enter correct option :(";
			getch();

			system("cls");
			course(x);
		}
		return 0;
	}
};

class librarian;

class teacher : public library
{
public:
	int opt;

	void begin()
	{

		system("cls");
		cout << endl;
		cout << "\n\n\t\t\t\t~~~~TEACHER PORTAL~~~~\n\n\n\n";
		cout << "\n\n\t Choose a option ";
		cout << "\n\n\t 1. View all Books";
		cout << "\n\n\t 2. Search a Book";
		cout << "\n\n\t 3. Go to Main Menu";
		cout << "\n\n\t Enter your Option: ";
		cin >> opt;

		if (opt == 1)
		{
			booklist(1);
		}
		else if (opt == 2)
		{
			search(1);
		}
		else if (opt == 3)
		{
			library::begin();
		}
		else
		{
			cout << "\n\n\t\t\t Wrong Choice! ";
			getch();
			begin();
		}
	}

	void booklist(int i)
	{
		system("cls");

		int b, j, r;

		system("cls");
		b = course(i);
		system("cls");

		if (b == 1)
		{
			r = 1;
			for (j = 0; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}
		else if (b == 2)
		{
			r = 1;
			for (j = 11; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}
		else if (b == 3)
		{
			r = 1;
			for (j = 21; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}
		getch();
		if (i == 1)
		{
			begin();
		}
		else
		{
			library::begin();
		}
	}

	int course(int x)
	{
		int i;
		system("cls");

		cout << "\n\n\t\t>>Please Choose one Branch :-\n";
		cout << "\n\t\t1.Novels\n\n\t\t2.Physics\n\n\t\t3.Calculus\n\n\t\t4.Go to menu\n";
		cout << "\n\t\tEnter your choice : ";
		cin >> i;

		switch (i)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			system("cls");
			if (x == 1)
			{
				begin();
			}
			else
			{
				library::begin();
			}

		default:
			cout << "\n\t\tPlease enter correct option :(";
			getch();
			system("cls");
			course(x);
		}
		return 0;
	}

	int search(int x)
	{
		int i, j, b;
		string ch;

		system("cls");
		b = course(x);

		system("cls");

		cout << "\n\n\t\t\tPlease Choose one option for below: \n";
		cout << "\n\n\n\t\t\t1.Search By Name";
		cout << "\n\n\t\t\t2.Search By Book's ID\n";
		cout << "\n\t\t\tEnter Your Choice : ";
		cin >> i;

		if (i == 1)
		{
			cout << "\n\n\t\t\nEnter the Book's Name: ";
			getchar();
			getline(cin, ch);
			system("cls");

			cout << "\n\n\n\n\n\t\t\t";

			for (j = 0; j <= 101; j++)
			{

				if (bookname[j] == ch)
				{
					cout << "Book Name: " << bookname[j] << endl;
					cout << "\n\n\t\t\tAuthor Name: " << auname[j] << endl;
					cout << "\n\n\t\t\tBook ID: " << bookid[j] << endl;
					break;
				}
				else if (j > 100)
				{
					cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
					getch();
					begin();
				}
			}
		}
		else if (i == 2)
		{
			cout << "\n\t\t\tEnter the Book's ID: ";
			cin >> j;
			system("cls");

			cout << "\n\n\n\n\n\t\t\t";

			for (i = 0; i <= 101; i++)
			{

				if (bookid[i] == j)
				{
					cout << "Book Name: " << bookname[i] << endl;
					cout << "\n\n\t\t\tAuthor Name: " << auname[i] << endl;
					cout << "\n\n\t\t\tBook ID: " << bookid[i] << endl;
					break;
				}
				else if (i > 100)
				{
					cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
					getch();
					begin();
				}
			}
		}
		else
		{
			cout << "\n\n\t\t\t Wrong Choice! ";
			getch();
			course(x);
		}

		cout << "\n\n\n\n\t\t\tPress any key to continue";
		getch();

		if (x == 1)
		{
			begin();
		}
		else
		{
			library::begin();
		}
		return 0;
	}

	friend class librarian;
};

class librarian;

class student : public library
{
public:
	int opt;

	void begin()
	{

		system("cls");
		cout << endl;
		cout << "\n\n\t\t\t\t~~~~STUDENT PORTAL~~~~\n\n\n\n";
		cout << "\n\n\t Choose a option ";
		cout << "\n\n\t 1. View all Books";
		cout << "\n\n\t 2. Search a Book";
		cout << "\n\n\t 3. Go to Main Menu";
		cout << "\n\n\t Enter your Option: ";
		cin >> opt;

		if (opt == 1)
		{
			booklist(1);
		}
		else if (opt == 2)
		{
			search(1);
		}
		else if (opt == 3)
		{
			library::begin();
		}
		else if (opt == 3)
		{
			library::begin();
		}
		else
		{
			cout << "\n\n\t\t\t Wrong Choice! ";
			getch();
			begin();
		}
	}

	void booklist(int i)
	{
		system("cls");

		int b, j, r;

		system("cls");
		b = course(i);
		system("cls");

		if (b == 1)
		{
			r = 1;
			for (j = 0; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}
		else if (b == 2)
		{
			r = 1;
			for (j = 11; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}
		else if (b == 3)
		{
			r = 1;
			for (j = 21; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}
		getch();
		if (i == 1)
		{
			begin();
		}
		else
		{
			library::begin();
		}
	}

	int course(int x)
	{
		int i;
		system("cls");

		cout << "\n\n\t\t>>Please Choose one Branch :-\n";
		cout << "\n\t\t1.Novels\n\n\t\t2.Physics\n\n\t\t3.Calculus\n\n\t\t4.Go to menu\n";
		cout << "\n\t\tEnter your choice : ";
		cin >> i;

		switch (i)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			system("cls");
			if (x == 1)
			{
				begin();
			}
			else
			{
				library::begin();
			}

		default:
			cout << "\n\t\tPlease enter correct option :(";
			getch();
			system("cls");
			course(x);
		}
		return 0;
	}

	int search(int x)
	{
		int i, j, b;
		string ch;

		system("cls");
		b = course(x);

		system("cls");

		cout << "\n\n\t\t\tPlease Choose one option for below: \n";
		cout << "\n\n\n\t\t\t1.Search By Name";
		cout << "\n\n\t\t\t2.Search By Book's ID\n";
		cout << "\n\t\t\tEnter Your Choice : ";
		cin >> i;

		if (i == 1)
		{
			cout << "\n\n\t\t\nEnter the Book's Name: ";
			getchar();
			getline(cin, ch);
			system("cls");

			cout << "\n\n\n\n\n\t\t\t";

			for (j = 0; j <= 101; j++)
			{

				if (bookname[j] == ch)
				{
					cout << "Book Name: " << bookname[j] << endl;
					cout << "\n\n\t\t\tAuthor Name: " << auname[j] << endl;
					cout << "\n\n\t\t\tBook ID: " << bookid[j] << endl;
					break;
				}
				else if (j > 100)
				{
					cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
					getch();
					begin();
				}
			}
		}
		else if (i == 2)
		{
			cout << "\n\t\t\tEnter the Book's ID: ";
			cin >> j;
			system("cls");

			cout << "\n\n\n\n\n\t\t\t";

			for (i = 0; i <= 101; i++)
			{

				if (bookid[i] == j)
				{
					cout << "Book Name: " << bookname[i] << endl;
					cout << "\n\n\t\t\tAuthor Name: " << auname[i] << endl;
					cout << "\n\n\t\t\tBook ID: " << bookid[i] << endl;
					break;
				}
				else if (i > 100)
				{
					cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
					getch();
					begin();
				}
			}
		}
		else
		{
			cout << "\n\n\t\t\t Wrong Choice! ";
			getch();
			course(x);
		}

		cout << "\n\n\n\n\t\t\tPress any key to continue";
		getch();

		if (x == 1)
		{
			begin();
		}
		else
		{
			library::begin();
		}
		return 0;
	}

	friend class librarian;
};

class librarian : public library
{
public:
	student s;
	string sname, isname[100];
	int sid, isid[100];

	void pass()
	{
		int i = 0;
		char ch, st[21], ch1[21] = {"pass"};

		cout << "\n\t Enter Password : ";

		while (1)
		{
			ch = getch();
			if (ch == 13)
			{
				st[i] = '\0';
				break;
			}
			else if (ch == 8 && i > 0)
			{
				i--;
				cout << "\b \b";
			}
			else
			{
				cout << "*";
				st[i] = ch;
				i++;
			}
		}
		
		for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
			;

		if (st[i] == '\0' && ch1[i] == '\0')
		{
			system("cls");
			begin();
		}
		else
		{
			cout << "\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
			getch();
			system("cls");
			pass();
		}
	}

	void begin()
	{
		system("cls");

		int i;

		cout << "\n\t\t~~~ WELCOME LIBRARIAN ~~~\n";
		cout << "\n\n\t\t>>Choose One Option:\n";
		cout << "\n\t\t1. View All Books";
		cout << "\n\n\t\t2. Search a Book";
		cout << "\n\n\t\t3. Modify/Add/Delete Book";
		cout << "\n\n\t\t4. Issue Book";
		cout << "\n\n\t\t5. Go to main menu";
		cout << "\n\n\t\t6. Close Application\n";
		cout << "\n\t\tEnter your choice: ";
		cin >> i;

		switch (i)
		{
		case 1:
			booklist(1);
			break;
		case 2:
			search(1);
			break;
		case 3:
			modify();
			break;
		case 4:
			issue();
			break;
		case 5:
			library::begin();
			break;
		case 6:
			exit(0);
		default:
			cout << "\n\t\tPlease enter correct option :(";
			getch();
			system("cls");
			begin();
		}
	}

	int booklist(int i)
	{
		system("cls");

		int b, j, r;

		system("cls");
		b = course(i);
		system("cls");

		if (b == 1)
		{

			r = 1;
			for (j = 0; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}
		else if (b == 2)
		{

			r = 1;
			for (j = 11; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}
		else if (b == 3)
		{

			r = 1;
			for (j = 21; bookid[j] != 0 && bookid[j] <= 100; j++)
			{
				cout << "\n\n\t\t~~" << r++ << "~~\n\n";
				cout << "\t\tBook Name: " << bookname[j] << endl;
				cout << "\t\tAuthor Name: " << auname[j] << endl;
				cout << "\t\tBook ID: " << bookid[j] << endl;
			}
		}

		getch();
		system("cls");

		if (i == 1)
		{
			begin();
		}
		return 0;
	}

	void search(int x)
	{
		int i, j, b;
		string ch;

		system("cls");
		b = course(x);

		system("cls");
		cout << "\n\n\t\t\tPlease Choose one option for below: \n";
		cout << "\n\n\n\t\t\t1.Search By Name";
		cout << "\n\n\t\t\t2.Search By Book's ID\n";
		cout << "\n\t\t\tEnter Your Choice : ";
		cin >> i;

		if (i == 1)
		{
			cout << "\n\n\t\t\nEnter the Book's Name: ";
			getchar();
			getline(cin, ch);
			system("cls");

			cout << "\n\n\n\n\n\t\t\t";
			for (j = 0; j <= 101; j++)
			{
				if (bookname[j] == ch)
				{
					cout << "Book Name: " << bookname[j] << endl;
					cout << "\n\n\t\t\tAuthor Name: " << auname[j] << endl;
					cout << "\n\n\t\t\tBook ID: " << bookid[j] << endl;
					break;
				}
				else if (j > 100)
				{
					cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
					getch();
					begin();
				}
			}
		}
		else if (i == 2)
		{
			cout << "\n\t\t\tEnter the Book's ID: ";
			cin >> j;
			system("cls");

			cout << "\n\n\n\n\n\t\t\t";

			for (i = 0; i <= 101; i++)
			{

				if (bookid[i] == j)
				{
					cout << "\n\n\t\t\tBook Name: " << bookname[i] << endl;
					cout << "\n\n\t\t\tAuthor Name: " << auname[i] << endl;
					cout << "\n\n\t\t\tBook ID: " << bookid[i] << endl;
					break;
				}
				else if (i > 100)
				{
					cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
					getch();
					begin();
				}
			}
		}
		else
		{
			cout << "\n\n\t\t\t Wrong Choice! ";
			getch();
			begin();
		}

		cout << "\n\n\tPress any key to continue";
		getch();
		system("cls");

		if (x == 1)
		{
			begin();
		}
	}

	void modify()
	{

		string ch;
		int i = 0, b, cont = 0, j;
		system("cls");

		cout << "\n\t\t>>Please Choose one option :-\n\n";
		cout << "\n\t\t1. Modification In Current Books";
		cout << "\n\n\t\t2. Add New Book";
		cout << "\n\n\t\t3. Delete A Book";
		cout << "\n\n\t\t4.Go back\n";
		cout << "\n\n\t\tEnter your choice : ";
		cin >> i;

		if (i == 1)
		{
			system("cls");
			cout << "\n\t\tPlease Choose One Option :-\n\n";
			cout << "\n\t\t1.Search By Book Name";
			cout << "\n\n\t\t2.Search By Book's ID\n";
			cout << "\n\t\tEnter Your Choice : ";
			cin >> j;

			if (j == 1)
			{
				system("cls");
				cout << "\n\n\n\t\t\t~~~~ Search ~~~~\n";
				cout << "\n\n\t\tEnter the Book's Name: ";
				getchar();
				getline(cin, ch);

				for (j = 0; j <= 101; j++)
				{

					if (bookname[j] == ch)
					{
						cout << "\n\n\n\t\tEnter the new name: ";
						getline(cin, bookname[j]);
						cout << "\n\t\tEnter the new Author Name: ";
						getline(cin, auname[j]);
						cout << "\n\t\tEnter the new Book ID: ";
						cin >> bookid[j];

						s.bookname[j] = bookname[j];
						s.auname[j] = auname[j];
						s.bookid[j] = bookid[j];

						cout << "\n\t\tUpdate Successful.\n";
						getch();
						modify();
						break;
					}
					else if (j == 101)
					{
						cout << "\n\n\t\tBook Not Found! ";
						getch();
						modify();
					}
				}
			}
			else if (j == 2)
			{
				system("cls");

				cout << "\n\n\n\t\t\t~~~~ Search ~~~~\n";
				cout << "\n\n\t\tEnter the Book's ID: ";
				cin >> j;

				for (i = 0; i <= 101; i++)
				{

					if (bookid[i] == j)
					{
						cout << "\n\n\n\t\tEnter the new name: ";
						getchar();
						getline(cin, bookname[i]);
						cout << "\n\t\tEnter the new Author Name: ";
						getline(cin, auname[i]);
						cout << "\n\t\tEnter the new Book ID: ";
						cin >> bookid[i];

						s.bookname[i] = bookname[i];
						s.auname[i] = auname[i];
						s.bookid[i] = bookid[i];

						cout << "\n\t\tUpdate Successful.\n";
						getch();
						system("cls");
						modify();
					}
					else if (i > 100)
					{
						cout << "\n\n\t\tBook Not Found! ";
						getch();
						modify();
					}
				}
			}
			else
			{
				cout << "\n\n\t\t\t Wrong Choice! ";
				getch();
				modify();
			}
		}
		else if (i == 2)
		{
			system("cls");

			int cc, q;

			cout << "\n\n\n\t\tHow many books you want to add?(3-4): ";
			cin >> cc;
			cout << "\n\n\t\tIn which category you want to add the books: 1-Novel  2-Physics  3-Calculus: ";
			cin >> q;
			cout << endl;

			if (q == 1)
			{
				cout << "\n\n\n\t\tEnter the details of the new Novel Books" << endl
					 << endl;
				for (j = 3; j < 3 + cc; j++)
				{
					cout << "\n\n\t\tEnter the new name of the book: " << j << " ";
					getchar();
					getline(cin, bookname[j]);
					cout << "\n\t\tEnter the Author Name: ";
					getline(cin, auname[j]);
					cout << "\n\t\tEnter the new Book ID: ";
					cin >> bookid[j];
					cout << endl
						 << endl;

					s.bookname[j] = bookname[j];
					s.auname[j] = auname[j];
					s.bookid[j] = bookid[j];
				}

				cout << "\n\n\t\tBook Successfully Added! ";
				getch();
				modify();
			}
			else if (q == 2)
			{
				cout << "\n\n\n\t\tEnter the details of the new Novel Books" << endl
					 << endl;
				for (j = 14; j < 14 + cc; j++)
				{
					cout << "\n\n\t\tEnter the new name of the book: " << j << " ";
					getchar();
					getline(cin, bookname[j]);
					cout << "\n\t\tEnter the Author Name: ";
					getline(cin, auname[j]);
					cout << "\n\t\tEnter the new Book ID: ";
					cin >> bookid[j];
					cout << endl;
					cout<<endl;	 

					s.bookname[j] = bookname[j];
					s.auname[j] = auname[j];
					s.bookid[j] = bookid[j];
				}

				cout << "\n\n\t\tBook Successfully Added! ";
				getch();
				modify();
			}
			else if (q == 3)
			{

				cout << "\n\n\n\t\tEnter the details of the new Novel Books" << endl
					 << endl;

				for (j = 23; j < 23 + cc; j++)
				{
					cout << "\n\n\t\tEnter the new name of the book: " << j << " ";
					getchar();
					getline(cin, bookname[j]);
					cout << "\n\t\tEnter the Author Name: ";
					getline(cin, auname[j]);
					cout << "\n\t\tEnter the new Book ID: ";
					cin >> bookid[j];
					cout << endl;
					cout<<endl;	 

					s.bookname[j] = bookname[j];
					s.auname[j] = auname[j];
					s.bookid[j] = bookid[j];
				}

				cout << "\n\n\t\tBook Successfully Added! ";
				getch();
				modify();
			}
		}
		else if (i == 3)
		{

			int i, j, b;
			string ch;

			system("cls");
			cout << "\n\n\n\t\t\t Enter the Book's ID: ";
			cin >> j;

			for (i = 0; i <= 101; i++)
			{

				if (bookid[i] == j)
				{
					bookname[i] = '\0';
					auname[i] = '\0';
					bookid[i] = bookid[i];

					s.bookname[i] = '\0';
					s.auname[i] = '\0';
					s.bookid[i] = bookid[i];

					cout << "\n\n\t\t\t Delete Successful! ";
					break;
				}
				else if (i > 100)
				{
					cout << "\n\n\t\t\t Book Not Found! ";
					getch();
					modify();
				}
			}

			cout << "\n\n\t\t\t Press any key to continue";
			getch();
			system("cls");
			modify();
		}
		else if (i == 4)
		{
			system("cls");
			librarian::begin();
		}
		else
		{
			cout << "\n\n\t\t\t Wrong Choice! ";
			getch();
			modify();
		}
	}

	void issue()
	{
		system("cls");

		string name, line;
		int i, id, j;

		cout << "\n\t\t->Please Choose one option :-\n";
		cout << "\n\t\t1.Issue Book Student";
		cout << "\n\n\t\t2.Issue Book Teacher";
		cout << "\n\n\t\t3.View Issued Book Student";
		cout << "\n\n\t\t4.View Issued Book Teacher";
		cout << "\n\n\t\t5.Return Book Student";
		cout << "\n\n\t\t6.Return Book Teacher";
		cout << "\n\n\t\t7.Calculate Fine";
		cout << "\n\n\t\t8.Add Fine";
		cout << "\n\n\t\t9.Remove Fine";
		cout << "\n\n\t\t10.Display Fine";
		cout << "\n\n\t\t11.Go back to menu";
		cout << "\n\n\t\tEnter Your Choice: ";
		cin >> i;

		if (i == 1)
		{
			system("cls");
			cout << "\n\n\n\tPress 1 if you like to view the book list else press 0: ";
			cin >> j;
			if (j == 1)
			{
				booklist(1);
			}
			else
			{
				cout << "\n\n\t\t Enter the name of book: ";
				getchar();
				getline(cin, name);
				cout << "\n\t\t Enter the ID of Book: ";
				cin >> id;

				for (j = 0; j <= 100; j++)
				{

					if (bookname[j] == name)
					{
						if (bookid[j] == id)
						{
							cout << "\n\n\t\t Enter your name: ";
							getchar();
							getline(cin, sname);
							cout << "\n\t\t Enter your ID: ";
							cin >> sid;
							cout << "\n\nISSUE SUCCESSFUL!!";
							ibook[id - 1] = name;
							iid[id - 1] = id;
							isname[id - 1] = sname;
							isid[id - 1] = sid;

							// Set issuance date
							time_t now = time(0);
							tm *ltm = localtime(&now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
							issuedate[id - 1] = buffer;

							fstream issuee;
							issuee.open("issue.txt", ios::app);
							if (!issuee)
							{
								cout << "\n\n File not created!.";
							}
							else
							{
								issuee << "Student Name: " << sname << endl;
								issuee << "Student's ID: " << sid << endl;
								issuee << "Book Name: " << name << endl;
								issuee << "Book ID: " << id << endl
									   << endl
									   << endl;
								issuee.close();
							}

							cout << "\n\n Press any key to continue.";
							getch();
							issue();
						}
						else
						{
							cout << "\n\n Book not found!";
							getch();
							issue();
						}
					}
				}
			}
			if (sstatus == "Student")
			{
				// Check if the student has reached the book limit
				int issuedBooksCount = countIssuedBooksByStudent(sid);
				if (issuedBooksCount >= studentBookLimit)
				{
					cout << "\n\n\t\tYou have reached the maximum limit for issued books ("
						 << studentBookLimit << "). Return some books before issuing more.";
					getch();
					issue();
				}
			}
			else if (sstatus == "Staff")
			{
				// Check if the staff has reached the book limit
				int issuedBooksCount = countIssuedBooksByStaff(sid);
				if (issuedBooksCount >= staffBookLimit)
				{
					cout << "\n\n\t\tYou have reached the maximum limit for issued books ("
						 << staffBookLimit << "). Return some books before issuing more.";
					getch();
					issue();
				}
			}
		}
		else if (i == 2)
		{
			system("cls");
			cout << "\n\n\n\tPress 1 if you like to view the book list else press 0: ";
			cin >> j;
			if (j == 1)
			{
				booklist(1);
			}
			else
			{
				cout << "\n\n\t\t Enter the name of book: ";
				getchar();
				getline(cin, name);
				cout << "\n\t\t Enter the ID of Book: ";
				cin >> id;

				for (j = 0; j <= 100; j++)
				{

					if (bookname[j] == name)
					{
						if (bookid[j] == id)
						{
							cout << "\n\n\t\t Enter your name: ";
							getchar();
							getline(cin, sname);
							cout << "\n\t\t Enter your ID: ";
							cin >> sid;
							cout << "\n\nISSUE SUCCESSFUL!!";
							ibook[id - 1] = name;
							iid[id - 1] = id;
							isname[id - 1] = sname;
							isid[id - 1] = sid;

							// Set issuance date
							time_t now = time(0);
							tm *ltm = localtime(&now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
							issuedate[id - 1] = buffer;

							fstream issuee;
							issuee.open("issueTeacher.txt", ios::app);
							if (!issuee)
							{
								cout << "\n\n File not created!.";
							}
							else
							{
								issuee << "Teacher Name: " << sname << endl;
								issuee << "Teacher's ID: " << sid << endl;
								issuee << "Book Name: " << name << endl;
								issuee << "Book ID: " << id << endl
									   << endl
									   << endl;
								issuee.close();
							}

							cout << "\n\n Press any key to continue.";
							getch();
							issue();
						}
						else
						{
							cout << "\n\n Book not found!";
							getch();
							issue();
						}
					}
				}
			}
			if (sstatus == "teacher")
			{
				// Check if the student has reached the book limit
				int issuedBooksCount = countIssuedBooksByTeacher(sid);
				if (issuedBooksCount >= teacherBookLimit)
				{
					cout << "\n\n\t\tYou have reached the maximum limit for issued books ("
						 << teacherBookLimit << "). Return some books before issuing more.";
					getch();
					issue();
				}
			}
		}

		else if (i == 3)
		{
			system("cls");

			cout << "\n\n\t\t\t ~~~~ List of issued Books ~~~~\n\n\n";
			string ch;
			int k = 1, l = 2;

			for (j = 0; iid[j] != 0 && iid[j] <= 100; j++)
			{
				fstream issuee;
				issuee.open("issue.txt", ios::in);
				if (!issuee)
				{
					cout << "\n\n File not created!.";
				}
				else
				{
					cout << "\n\n\n\t\t\t\t  ~~~" << 1 << "~~~\n\n";
					while (issuee)
					{
						if (k == 6)
						{
							cout << "\n\n\n\t\t\t\t  ~~~" << l++ << "~~~\n";
							k = 0;
						}
						getline(issuee, ch);
						cout << "\t\t\t" << ch << endl;
						k++;
					}
					issuee.close();
				}
			}

			cout << "\n\t Press any key to continue!";
			getch();
			issue();
		}
		else if (i == 4)
		{
			system("cls");

			cout << "\n\n\t\t\t ~~~~ List of issued Books ~~~~\n\n\n";
			string ch;
			int k = 1, l = 2;

			for (j = 0; iid[j] != 0 && iid[j] <= 100; j++)
			{
				fstream issuee;
				issuee.open("issueTeacher.txt", ios::in);
				if (!issuee)
				{
					cout << "\n\n File not created!.";
				}
				else
				{
					cout << "\n\n\n\t\t\t\t  ~~~" << 1 << "~~~\n\n";
					while (issuee)
					{
						if (k == 6)
						{
							cout << "\n\n\n\t\t\t\t  ~~~" << l++ << "~~~\n";
							k = 0;
						}
						getline(issuee, ch);
						cout << "\t\t\t" << ch << endl;
						k++;
					}
					issuee.close();
				}
			}

			cout << "\n\t Press any key to continue!";
			getch();
			issue();
		}

		else if (i == 5)
		{
			system("cls");
			cout << "\n\n \t\t~~~Return Book~~~\n";

			cout << "\n\n\t Enter your Name: ";
			getchar();
			getline(cin, sname);
			cout << "\n\n\t Enter your ID: ";
			cin >> sid;
			cout << "\n\n\t Enter Book Name: ";
			getchar();
			getline(cin, name);
			cout << "\n\n\t Enter Book ID: ";
			cin >> id;

			for (j = 0; j <= 101; j++)
			{
				if (sname == isname[j])
				{
					if (sid == isid[j])
					{
						if (id == iid[j])
						{
							cout << "\n\n\t\t Enter return date: ";
							getchar();
							getline(cin, returndate[id - 1]);

							// Calculate fine
							int fineAmount = calcFine(id);

							// Display fine
							cout << "\n\n\t\t Fine for Book ID " << id << ": $" << fineAmount << endl;

							// Remove book details from arrays
							ibook[id - 1] = "";
							iid[id - 1] = 0;
							isname[id - 1] = "";
							isid[id - 1] = 0;

							fstream ret;
							ret.open("return.txt", ios::app);
							if (ret)
							{
								ret << "Student Name: " << sname << endl;
								ret << "Student's ID: " << sid << endl;
								ret << "Book Name: " << name << endl;
								ret << "Book ID: " << id << endl;
								ret << "Return Date: " << returndate[id - 1] << endl
									<< endl;
								ret.close();
							}

							cout << "\n\n Book Returned Successfully!";
							getch();
							issue();
						}
					}
				}
			}

			for (j = 0; j <= 101; j++)
			{
				if (sname == isname[j])
				{
					if (sid == isid[j])
					{
						if (id == iid[id - 1])
						{
							ibook[id - 1] = '\0';
							isname[j] = '\0';
							isid[j] = '\0';
							cout << "\n\n\n\t\tRETURN SUCCESSFUL! ";
							getch();
							issue();
						}
						else if (j == 101)
						{
							cout << "\n\n\n\t\t DATA NOT FOUND! ";
							getch();
							issue();
						}
					}
					else if (j == 101)
					{
						cout << "\n\n\n\t\t DATA NOT FOUND! ";
						getch();
						issue();
					}
				}
				else if (j == 101)
				{
					cout << "\n\n\n\t\t DATA NOT FOUND! ";
					getch();
					issue();
				}
			}
		}
		else if (i == 6)
		{
			system("cls");
			cout << "\n\n \t\t~~~Return Book~~~\n";

			cout << "\n\n\t Enter your Name: ";
			getchar();
			getline(cin, sname);
			cout << "\n\n\t Enter your ID: ";
			cin >> sid;
			cout << "\n\n\t Enter Book Name: ";
			getchar();
			getline(cin, name);
			cout << "\n\n\t Enter Book ID: ";
			cin >> id;

			for (j = 0; j <= 101; j++)
			{
				if (sname == isname[j])
				{
					if (sid == isid[j])
					{
						if (id == iid[j])
						{
							cout << "\n\n\t\t Enter return date: ";
							getchar();
							getline(cin, returndate[id - 1]);

							// Calculate fine
							int fineAmount = calcFine(id);

							// Display fine
							cout << "\n\n\t\t Fine for Book ID " << id << ": $" << fineAmount << endl;

							// Remove book details from arrays
							ibook[id - 1] = "";
							iid[id - 1] = 0;
							isname[id - 1] = "";
							isid[id - 1] = 0;

							fstream ret;
							ret.open("returnTeacher.txt", ios::app);
							if (ret)
							{
								ret << "Teacher Name: " << sname << endl;
								ret << "Teacher's ID: " << sid << endl;
								ret << "Book Name: " << name << endl;
								ret << "Book ID: " << id << endl;
								ret << "Return Date: " << returndate[id - 1] << endl
									<< endl;
								ret.close();
							}

							cout << "\n\n Book Returned Successfully!";
							getch();
							issue();
						}
					}
				}
			}

			for (j = 0; j <= 101; j++)
			{
				if (sname == isname[j])
				{
					if (sid == isid[j])
					{
						if (id == iid[id - 1])
						{
							ibook[id - 1] = '\0';
							isname[j] = '\0';
							isid[j] = '\0';
							cout << "\n\n\n\t\tRETURN SUCCESSFUL! ";
							getch();
							issue();
						}
						else if (j == 101)
						{
							cout << "\n\n\n\t\t DATA NOT FOUND! ";
							getch();
							issue();
						}
					}
					else if (j == 101)
					{
						cout << "\n\n\n\t\t DATA NOT FOUND! ";
						getch();
						issue();
					}
				}
				else if (j == 101)
				{
					cout << "\n\n\n\t\t DATA NOT FOUND! ";
					getch();
					issue();
				}
			}
		}
		else if (i == 7)
		{
			int bookID; // Assuming you get the book ID from the user
			cout << "Enter Book ID:\n";
			cin >> bookID;
			int fineAmount = calcFine(bookID);
			if (fineAmount > 0)
			{
				cout << "\n\t Fine Amount: $" << fineAmount << endl;
			}
		}

		else if (i == 8)
		{
			int bookID, amount;
			cout << "Enter Book ID:\n";
			cin >> bookID;
			cout << "Enter Fine Amount:\n";
			cin >> amount;
			addFine(bookID, amount);
		}

		else if (i == 9)
		{
			int bookID; // Assuming you get the book ID from the user
			cout << "Enter Book ID:\n";
			cin >> bookID;
			removeFine(bookID);
		}

		else if (i == 10)
		{
			for (int i = 0; i < 10; i++)
			{
				cout << fine[i] << endl;
			}
		}

		else if (i == 11)
		{
			begin();
		}
		else
		{
			cout << "\n\n\t\t\t Wrong Choice! ";
			getch();
			issue();
		}
	}
	// Helper function to count the number of books issued by a student
	int countIssuedBooksByStudent(int studentID)
	{
		int count = 0;
		for (int j = 0; j <= 100; j++)
		{
			if (isid[j] == studentID)
			{
				count++;
			}
		}
		return count;
	}

	// Helper function to count the number of books issued by a teacher
	int countIssuedBooksByTeacher(int teacherID)
	{
		int count = 0;
		for (int j = 0; j <= 100; j++)
		{
			if (isid[j] == teacherID)
			{
				count++;
			}
		}
		return count;
	}

	// Helper function to count the number of books issued by a staff member
	int countIssuedBooksByStaff(int staffID)
	{
		int count = 0;
		for (int j = 0; j <= 100; j++)
		{
			if (isid[j] == staffID)
			{
				count++;
			}
		}
		return count;
	}
};

int main()
{

	int i = 0;
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t";

	system("cls");

	library lib;
	librarian l;
	student s;
	teacher t;
	lib.choice = 1;
	lib.begin();

	for (i = 1; i > 0; i++)
	{
		cin >> lib.choice;
		if (lib.choice == 1)
		{

			s.begin();
		}
		else if (lib.choice == 2)
		{
			l.pass();
		}
		else if (lib.choice == 3)
		{
			t.begin();
		}
		else if (lib.choice == 4)
		{
			exit(0);
		}
	}
	return 0;
}
