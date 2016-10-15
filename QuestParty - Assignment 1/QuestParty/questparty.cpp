//
//  questparty.cpp
//  QuestParty
//
//  Created by Travis Hodge on 1/25/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include "questparty.hpp"
#include <iostream>
using namespace std;



    
void QuestParty::AddAdventurer(AdventureMember member1) // Function declaration for adding an adventurer to the list.
    {
        
        
    
        adventurerlist.push_back(member1); // pushes back the adventurer entered.
   
    
    
        
    }

    AdventureMember* QuestParty::SearchAdventurer(AdventureMember member) // Function to return a pointer to the adventurer being searched for.
    {
        AdventureMember* tempMember = nullptr; // Pointer initialized to Null.
        
            for (int j = 0; j < adventurerlist.size(); j++)
            {
                    if (member.mName == adventurerlist[j].mName && member.mRole == adventurerlist[j].mRole)
                    {
                        
                        cout << "Player has been found. \n";
                        tempMember = &adventurerlist[j]; // If the name and role typed in matches any of the names and roles in the list
                                                         // then the temporary pointer points to the address of the matched adventurer.
                        
                        return tempMember;      // The temporary pointer is then returned by the function and displayed later in Main.
                        break;
                        
                        
                    }
                    
                    if (j == adventurerlist.size()-1)
                    {
                        cout << "Player not Found. Please try again. \n"; // If no match is found an error message is display and finally the temporary NULL
                                                                          // pointer is returned.
                        
                    }
            
        
        
            }
    
        return tempMember;
    }
    
    void QuestParty::DisplayAdventurer() // Function declaration for displaying all adventurers in the list.
    {
        
        for (int i = 0 ; i < adventurerlist.size(); i++)
        {
        
            cout << "Character " << i+1  << ":      "
            << "Name : "
            << adventurerlist[i].mName << "     "
            << "Role : "
            << adventurerlist[i].mRole << "     "
            << "Weapon : "
            << adventurerlist[i].mWeapon << "\n\n";
        }
    
    }
    
    
