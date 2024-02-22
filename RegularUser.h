/**
 * @author Irmak İmdat 
*/
#ifndef REGULARUSER_H
#define REGULARUSER_H

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

class RegularUser
{
    public: 
        RegularUser();
        RegularUser(int newId, string newName);
        int getID();
        string getName();
        void setName(string newName);
        void setID(int newID);
        RegularUser& operator=( const RegularUser&); 
        bool followingTheContentCreator(int id); 

    private:
        
        string name;
        int id; 
};

#endif