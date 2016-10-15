//
//  HodgeProg1.cpp
//  QuestParty
//
//  Created by Travis Hodge on 1/25/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//
// Compiled and run with Xcode on Mac.
//



#include <iostream>
#include <string>
#include "questparty.hpp"
using namespace std;


int main() {
    
    QuestParty party; // Instance of the QuestParty class is needed to access all member functions and the member struct.
    
    int menuItem;
    string characterName, characterRole, characterWeapon;
    string searchName,searchRole;
    
    AdventureMember initial; // Instance of an Adventurer to store the name, role, and weapon from input.
    AdventureMember* returned; // return pointer used from the search function, if used.
    
    do
    {
        
        
        cout << "1. Add Adventurer to quest party.\n"
             << "2. Search for adventurer.\n"
             << "3. Display all adventurer.\n"
             << "4. Exit menu. \n";
        cin >> menuItem;
        
        
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "error.";
        }
        
        switch (menuItem) {
                
                
            case 1:
                
                cout << "Please enter a name \n";
                cin >> characterName;
                
                cout<< "Please enter a character role \n";
                cin >> characterRole;
                
                cout << "Please enter a weapon choice \n";
                cin >> characterWeapon;
                
                initial.mName = characterName;
                initial.mRole = characterRole;
                initial.mWeapon = characterWeapon;
            
            party.AddAdventurer(initial); // calls the add adventurer using the initial instance of an adventurer.
                
                break;
                
            case 2:
                
                
               
                
                cout << "Please Enter the name of the Character to search: \n";
                cin  >> searchName;
                cout << "Please Enter the role of the Character to search: \n";
                cin  >> searchRole;

                initial.mName = searchName;
                initial.mRole = searchRole;
                returned = party.SearchAdventurer(initial); // if a match is found during search the returned pointer is set.
                
                cout << "Character Name: " << returned->mName
                     << "\n Characeter Role: " << returned->mRole
                     << "\n" << "Character Weapon: "
                     << returned->mWeapon << "\n";
                
                
                
                break;
                
            case 3:
                
                party.DisplayAdventurer(); // calls the display function
                cout << " \n";
                
                break;
                
            case 4:
                
                return 0; // ends the program if the user exits.
                
                break;
                
            default:
                break;
        }
        
        
        
        
        
    }while(!cin.fail());
    
    
    
    
        return 0;
}
