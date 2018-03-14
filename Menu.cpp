
#include "Menu.h"

using namespace std;
void Menu::start(){
    Event eve;
    int choice, choice2, mon, day, yr, hr, min;
    string title, des, ampm;
    
    cout << "\n\tMENU\n1. Create new event\n2. Edit event\n3. Delete event\n4. Show event\n5. Quit\n";
    cin >> choice;
    
    do
    {
        if (choice == 1)
        {
            cout << "\tCREATING EVENT\n";
            cin.ignore();
            cout << "Enter event title:  ";
            getline(cin, title);
            
            cout << "Decription: ";
            getline(cin, des);
            
            cout << "Month: ";
            cin >> mon;
            
            cout << "day: ";
            cin >> day;
            
            cout << "year: ";
            cin >> yr;
            
            cout << "hour: ";
            cin >> hr;
            
            cout << "minute: ";
            cin >> min;
            
            cin.ignore();
            
            cout << "Am/Pm: ";
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
            cin >> mon;
            if(eve.eventExists(title, mon) != false)
            {
                cout << "Event Found what would you like to change\n1. Title\n2.Description\n3. Month\n4.day\n5. hour \n6. minute\n7. ampm\n8. year" << endl;
                cin >> choice2;
                
                
                if(choice2 == 1)
                {
                    cin.ignore();
                    cout << "Title: " << endl;
                    getline(cin, title);
                    eve.editEvent(title, des, mon, day, yr, hr, min, ampm);
                    cout << "Event has been changed" << endl;
                }
                else if(choice2 == 2)
                {
                    cin.ignore();
                    cout << "Desciption: " << endl;
                    getline(cin, des);
                    eve.editEvent(title, des, mon, day, yr, hr, min, ampm);
                    cout << "Event has been changed" << endl;
                }
                else if(choice2 == 3)
                {
                    cin.ignore();
                    cout << "Month: " << endl;
                    cin >> mon;
                    eve.editEvent(title, des, mon, day, yr, hr, min, ampm);
                    cout << "Event has been changed" << endl;
                }
                else if(choice2 == 4)
                {
                    cin.ignore();
                    cout << "Day: " << endl;
                    cin >> day;
                    eve.editEvent(title, des, mon, day, yr, hr, min, ampm);
                    cout << "Event has been changed" << endl;
                }
                else if(choice2 == 5)
                {
                    cin.ignore();
                    cout << "Hour: " << endl;
                    cin >> hr;
                    eve.editEvent(title, des, mon, day, yr, hr, min, ampm);
                    cout << "Event has been changed" << endl;
                }
                else if(choice2 == 6)
                {
                    cin.ignore();
                    cout << "Minute: " << endl;
                    cin >> min;
                    eve.editEvent(title, des, mon, day, yr, hr, min, ampm);
                    cout << "Event has been changed" << endl;
                }
                else if(choice2 == 7)
                {
                    cin.ignore();
                    cout << "ampm: " << endl;
                    getline(cin, ampm);
                    eve.editEvent(title, des, mon, day, yr, hr, min, ampm);
                    cout << "Event has been changed" << endl;
                }
                else if(choice2 == 8)
                {
                    cin.ignore();
                    cout << "Year: " << endl;
                    cin >> yr;
                    eve.editEvent(title, des, mon, day, yr, hr, min, ampm);
                    cout << "Event has been changed" << endl;
                }
                else
                {
                    cout << "invalid option" << endl;
                }
            }
            else
            {
                cout << "Event Not Found" << endl;
            
            }
            cout << "\n\tMENU\n1. Create new event\n2. Edit event\n3. Delete event\n4. Show event\n5. Quit\n";
            
            cin >> choice;
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
