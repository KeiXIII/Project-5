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
};

Event::Event(){
    for(int i = 0; i < SIZE; i++){
        table[i] = new NodeType;
        table[i]->next = NULL;
        table[i]->newTitle = "NULL";
        table[i]->descrip = "NULL";
        table[i]->month = NULL;
        table[i]->day = NULL;
        table[i]->year = NULL;
        table[i]->hour = NULL;
        table[i]->minutes = NULL;
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
    delete table[];
}

/*int Event::hashKey(int month){
    int newKey = month%12;
    return newKey;
}*/

void Event::addEvent(string title, string descript, 
                     int month, int day, int year, 
                     int hour, int minutes){
    int index = month;
    if(table[index]->newTitle == "NULL"){
        table[index]->newTitle = title;
        table[index]->descrip = descript;
        table[index]->month = month;
        table[index]->day = day;
        table[index]->year = year;
        table[index]->hour = hour;
        table[index]->minutes = minutes;
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
        temp->next = NULL;
        while(head->next != NULL){
            head = head->next;
        }
        head->next = temp;   
    }      
}

void Event::removeEvent(string title, int month){
    int index = month;
    head = table[index];
    NodeType* temp;
    if(table[index]->newTitle == title){
        temp = head;
        head = head->next;
        delete temp;
    }else{
        while(head->next != NULL && head->newTitle != title){
            temp = head;
            head = head->next;
        }
        temp->next = head->next;
        delete head;
    }
}

bool 

void Event::printEventMonth(int month){
    
}

/*void Event::editTitle(string string title){
    
}

void Event::editDescript(string de){
    
}

void Event::editDate(string mon, int day, int year, int hr, int min){
    
}*/

Event::Event(string newTitle, int day, MONTH month, int year, int hour, int minutes, string descript) {
	title = newTitle;
	date.tm_mday = day;
	date.tm_mon = month;
	date.tm_year = year;
	date.tm_hour = hour;
	date.tm_min = minutes;
	description = descript;
}

void Event::displayEvent(ofstream &fout) {
	fout << title << endl;
	fout << description << endl;
	fout << date.tm_hour << endl;
	fout << date.tm_min << endl;
	fout << MONTH(date.tm_mon) << endl;
	fout << date.tm_mday << endl;
	fout << date.tm_year << endl;
}

void Event::editTitle(string newTitle) {
	title = newTitle;
}

void Event::editDate(int day, MONTH month, int year, int hour, int minutes) {
	date.tm_mday = day;
	date.tm_mon = month;
	date.tm_year = year;
	date.tm_hour = hour;
	date.tm_min = minutes;
}

void Event::editDescript(string descript) {
	description = descript;
}

string Event::getTitle() {
	return title;
}

string Event::getDescription() {
	return description;
}

tm Event::getDate() {
	return date;
}