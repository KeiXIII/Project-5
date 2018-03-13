/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Event.h"

int main(){
    Event eve;
    cout << "***First time insertion (shows one event)" << endl;
    eve.addEvent("Birthday", "Mark turns 5 years old", 3, 22, 2018, 3, 0, "P.M.");
    eve.printMonth(3);
    
    cout << "***Second time insertion (shows two events)" << endl;
    eve.addEvent("Graduation", "Stacey's high school graduation", 3, 30, 2018, 7, 30, "P.M.");
    eve.printMonth(3);
    
    cout << "third time event changed to 10 years old" << endl;
    eve.editEvent("Birthday", "Mark turns 10 years old", 3, 22, 2018, 3, 0, "P.M.");
    eve.printMonth(3);
    
    cout << "editing highschool to middle school for the graduation" << endl;
    eve.editEvent("Graduation", "Stacey's high middle graduation", 3, 30, 2018, 8, 30, "P.M.");
    eve.printMonth(3);
    cout << "***Remove event (shows one event now)" << endl;
    eve.removeEvent("Birthday", 3);
    eve.printMonth(3);
    
    cout << "***Third time insertion (shows one event for both months)" << endl;
    eve.addEvent("Doc Appointment", "Follow up on tests", 1, 27, 2018, 9, 45, "A.M.");
    
    cout << "**For January" << endl;
    eve.printMonth(1);
    
    cout << "**For March" << endl;
    eve.printMonth(3);
    
    cout << "***Deleting last event (shows no events for march)" << endl;
    eve.removeEvent("Graduation", 3);
    eve.printMonth(3);
    
    return 0;
}
