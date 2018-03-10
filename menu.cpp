#include "menu.h"
void Menu::start() {
	int choice;

	cout << "\nMENU\n1. Create New Event\n2. Edit Saved Event\n3. Delete Saved Event\n4. Quit\n";
	cin >> choice;

	if (choice == 1) {
		string title, description, dayNight;
		int hour, minute, month, day, year;

		cin.ignore();

		cout << "CREATING NEW EVENT..." << endl;

		cout << "Enter title: ";
		getline(cin, title);
		cout << "\nEnter description: ";
		getline(cin, description);
		cout << "\nEnter hour: ";
		cin >> hour;
		cout << "\nEnter minute: ";
		cin >> minute;
		cout << "\nEnter am/pm: ";
		getline(cin, dayNight);
		cout << "\nEnter month: ";
		cin >> month;
		cout << "\nEnter day: ";
		cin >> day;
		cout << "\nEnter year: ";
		cin >> year;

		Event newEvent;
		newEvent.addEvent(title, description,
			month, day, year,
			hour, minute, dayNight);



		//return 1;
	}
	/*else if (choice == 2) {
		string title4edit;
		Event event4edit;
		int choice2;

		cin.ignore();

		cout << "\nWhat is title of event to edit?\n";
		getline(cin, title4edit);

		event4edit = container.find(title4edit)->second;

		cout << "EVENT FOUND!" << endl;
		event4edit.displayEvent();

		//cin.ignore();

		cout << "1. Edit Title\n2. Edit Description\n3. Edit Date\n";
		cin >> choice2;

		if (choice2 == 1) {
			string newTitle;

			cout << "\nNew Title: ";
			getline(cin, newTitle);

			event4edit.editTitle(newTitle);

			cin.ignore();

			event4edit.displayEvent();

			ofstream fout;

			fout.open("savedEvents.txt");

			for (mmap::iterator it = container.begin(); it != container.end(); ++it)
				(*it).second.displayEvent(fout);
		}
		else if (choice2 == 2) {
			string newDescript;

			cout << "\nNew Description: ";
			getline(cin, newDescript);

			event4edit.editDescript(newDescript);

			cin.ignore();

			ofstream fout;

			fout.open("savedEvents.txt");

			for (mmap::iterator it = container.begin(); it != container.end(); ++it)
				(*it).second.displayEvent(fout);
			cin.ignore();
		}
		else {
			int newHour, newMinute, newMonth, newDay, newYear;

			cout << "\nEnter hour: ";
			cin >> newHour;
			cout << "\nEnter minute: ";
			cin >> newMinute;
			cout << "\nEnter month: ";
			cin >> newMonth;
			cout << "\nEnter day: ";
			cin >> newDay;
			cout << "\nEnter year: ";
			cin >> newYear;

			event4edit.editDate(newDay, MONTH(newMonth), newYear, newHour, newMinute);

			ofstream fout;

			fout.open("savedEvents.txt");

			for (mmap::iterator it = container.begin(); it != container.end(); ++it)
				(*it).second.displayEvent(fout);
		}

		cout << "\nEVENT EDITED AND SAVED" << endl;

		//return 2;
	}*/
	else if (choice == 3) {
		string title;
		int month;
		Event reEvent;

		cout << "\nWhat is title of event to delete?" << endl;
		cin >> title;
		cout << "in what month?" << endl;
		cin >> month;

		reEvent.removeEvent(title, month);

	
	}
	/*else {
		ofstream fout;

		fout.open("savedEvents.txt");

		for (mmap::iterator it = container.begin(); it != container.end(); ++it)
			(*it).second.displayEvent(fout);

		//return 4;
	}*/
}