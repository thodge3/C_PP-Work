//
//  questparty.hpp
//  QuestParty
//
//  Created by Travis Hodge on 1/25/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#ifndef questparty_hpp
#define questparty_hpp

#include <stdio.h>
#include <string>
#include <vector>

struct AdventureMember{
    
    std::string mName;       // Member variables for the needed Struct of an adventurer.
    std::string mRole;
    std::string mWeapon;
    
};




class QuestParty{
    
    std::vector<AdventureMember> adventurerlist; // A vector is created in order to hold a
                                                 //    list of adventurers each time one is
                                                 //    created.


       
    
public: // In order to access the declaration of the member functions, the
        //     functions must be set to public inside of the QuestParty Class.
    
    
    
    void AddAdventurer(AdventureMember member1);
    
    AdventureMember* SearchAdventurer(AdventureMember member); // returns a pointer to an adventurer if the search is successful. 
    
    void DisplayAdventurer();
    
    
};





#endif /* questparty_hpp */
