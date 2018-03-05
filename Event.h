/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: B
 *
 * Created on March 4, 2018, 11:47 PM
 */

#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//enum MONTH {January, February, March, April, May, June, July, August, September, October, November, December};
const int SIZE = 12;
struct NodeType;

class Event{
    
private:
	/*string title;
	tm date;
	string description;*/
    NodeType* table[SIZE];
    NodeType* head;
    int numEvents;
public:
	Event();
	~Event();
        int hashKey(string title);
        void addEvent(string title, string descript, 
                     int month, int day, int year, 
                     int hour, int minutes, string dayNight);
        void removeEvent(string title, int month);
        bool eventExists(string title, int month);
        void printMonth(int month);
	
};
