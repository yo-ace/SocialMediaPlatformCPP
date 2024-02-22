/**
 * @author Irmak İmdat 
*/
#ifndef CONTENTCREATOR_H
#define CONTENTCREATOR_H

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

class ContentCreator
{
    public:
        
        ContentCreator();
        ContentCreator(int newId, string newName);
        ~ContentCreator();      
        int getID();
        string getName();
        int getContent(int contentId);
        void addContent(int contentID);
        void removeContent(int contentId);
        void addFollower(int followerID);
        void removeFollower(int followerID, bool userIsRemoved);
        int contentFindPosition(int contentID);
        int followerFindPosition(int followerId);
        bool contentExist(int contentId);
        bool followerExist(int followerId);
        void displayContents();
        void displayFollowers();
        void display();
        
    private:

        string name;
        int id;
        LinkedList<int> followers;
        LinkedList<int> contents;
    
};

#endif