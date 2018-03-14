
#include "Menu.h"

using namespace std;
void Menu::start(){
	Event eve;
	int choice;

	cout << "\n\tMENU\n1. Create new event\n2. Edit event\n3. Delete event\n4. Show event\n5. Quit\n";
	cin >> choice;

	do
	{
		if (choice == 1)
		{
			cout << "\tCREATING EVENT\n";
			cin.ignore();
			cout << "Enter event title:  ";
			string title;
			getline(cin, title);

			cout << "Decription: ";
			string des;
			getline(cin, des);

			cout << "Month: ";
			int mon;
			cin >> mon;

			cout << "day: ";
			int day;
			cin >> day;

			cout << "year: ";
			int yr;
			cin >> yr;

			cout << "hour: ";
			int hr;
			cin >> hr;

			cout << "minute: ";
			int min;
			cin >> min;

			cin.ignore();

			cout << "Am/Pm: ";
			string ampm;
			getline(cin, ampm);

			eve.addEvent(title, des, mon, day, yr, hr, min, ampm);

			cout << "\n\tMENU\n1. Create new event\n2. Edit event\n3. Delete event\n4. Show event\n5. Quit\n";

			cin >> choice;
		}
		else if (choice == 2)
		{
			cin.ignore();
			cout << "Title: ";
			string title;
			getline(cin, title);
			cout << "Month: ";
			int mon;
			cin >> mon;
		}
		
		else if (choice == 3)
		{
			cout << "\tDELETING EVENT\n";
			cin.ignore();
			cout << "Title: ";
			string title;
			getline(cin, title);
			cout << "Month: ";
			int mon;
			cin >> mon;

			if (eve.eventExists(title, mon) == false)
			{
				cout << "Event not found!" << endl;
			}
			else
			{
				cout << "Event " << title << "is deleted" << endl;
				eve.removeEvent(title, mon);
			}
			cout << "\n\tMENU\n1. Create new event\n2. Edit event\n3. Delete event\n4. Show event\n5. Quit\n";

			cin >> choice;
		}

		else if (choice == 4)
		{
			cout << "SHOWING EVENT OF MONTH" << endl;
			cout << "Month: ";
			int mon;
			cin >> mon;
			eve.printMonth(mon);
			cout << "\n\tMENU\n1. Create new event\n2. Edit event\n3. Delete event\n4. Show event\n5. Quit\n";

			cin >> choice;

		}
	} while (choice != 5);

}
