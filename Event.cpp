/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Event.h"

const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

struct NodeType{
    NodeType* next;
    string newTitle;
    string descrip;
    int month;
    int day;
    int year;
    int hour;
    int minutes;
    string AmPm;
};

Event::Event(){
    for(int i = 0; i < SIZE; i++){
        table[i] = new NodeType;
        table[i]->next = NULL;
        table[i]->newTitle = "NULL";
        table[i]->descrip = "NULL";
        table[i]->month = 0;
        table[i]->day = 0;
        table[i]->year = 0;
        table[i]->hour = 0;
        table[i]->minutes = 0;
        table[i]->AmPm = "NULL";
    }
}


Event::~Event(){
    NodeType* temp;
    NodeType* head;
    for(int i = 0; i < 12; i++){
        head = table[i];
	while(head != NULL){
		temp = head;
		head = head->next;
		delete temp;
	}
    }
}

/*int Event::hashKey(int month){
    int newKey = month%12;
    return newKey;
}*/

void Event::addEvent(string title, string descript, 
                     int month, int day, int year, 
                     int hour, int minutes, string dayNight){
    int index = month-1;
    if(table[index]->newTitle == "NULL"){
        table[index]->newTitle = title;
        table[index]->descrip = descript;
        table[index]->month = month;
        table[index]->day = day;
        table[index]->year = year;
        table[index]->hour = hour;
        table[index]->minutes = minutes;
        table[index]->AmPm = dayNight;
        
    }else{
        head = table[index];
        NodeType* temp = new NodeType;
        temp->newTitle = title;
        temp->descrip = descript;
        temp->month = month;
        temp->day = day;
        temp->year = year;
        temp->hour = hour;
        temp->minutes = minutes;
        temp->AmPm = dayNight;
        temp->next = NULL;
        while(head->next != NULL){
            head = head->next;
        }
        head->next = temp;   
    }      
}

void Event::removeEvent(string title, int month){
    if(eventExists(title, month) != false){ 
        int index = month-1;
        head = table[index];
        NodeType* temp;
        if(table[index]->newTitle == title){
            table[index] = head->next;
            delete head;
        }else{
            while(head->next != NULL && head->newTitle != title){
                temp = head;
                head = head->next;
            }
            temp->next = head->next;
            delete head;
        }
    }
}

bool Event::eventExists(string title, int month){
    int index = month-1;
    head = table[index];
    NodeType* temp;
    if(table[index]->newTitle == title){
        return true;
    }else{
        while(head->next != NULL){
            if(head->next->newTitle == title)
                return true;
            else
                head = head->next;
        }
    }
    return false;
}

void Event::printMonth(int month){
    int index = month-1;
    head = table[index];
    if(table[index] == NULL)
        cout << "No events were added for " << months[month -1] << endl << endl;
    else{
        if(head->next == NULL){
            cout << "Title: " << head->newTitle << endl;
            cout << "Description: " << head->descrip << endl;
            cout << "Date: " << months[head->month-1] << " " << head->day << ", "<< head->year << endl;
            if(head->minutes == 0)
                cout << "Time: " << head->hour << ":" << "00 " << head->AmPm << endl << endl;
            else
                cout << "Time: " << head->hour << ":" << head->minutes << " " << head->AmPm << endl << endl;
            head = head->next;
        }else{
            while(head != NULL){
                cout << "Title: " << head->newTitle << endl;
                cout << "Description: " << head->descrip << endl;
                cout << "Date: " << months[head->month-1] << " " << head->day << ", "<< head->year << endl;
                if(head->minutes == 0)
                    cout << "Time: " << head->hour << ":" << "00 " << head->AmPm << endl << endl;
                else
                    cout << "Time: " << head->hour << ":" << head->minutes << " " << head->AmPm << endl << endl;
                head = head->next;
            }
        }
    }
}
