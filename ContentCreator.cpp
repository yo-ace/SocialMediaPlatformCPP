/**
 * @author Irmak İmdat
*/
#include <string>
#include "ContentCreator.h"
using namespace std;

ContentCreator::ContentCreator()
{
    id = 0;
    name = "";
}

ContentCreator::ContentCreator(int newId, string newName)
{
    id = newId;
    name = newName;
}

ContentCreator::~ContentCreator()
{
    // Did not use the Heap, therefore everything 
    // that needs destruction is handled defaultly
}  

// getters 
int ContentCreator::getID()
{
    return id;
}

string ContentCreator::getName()
{
    return name;
}

    // get content through id
int ContentCreator::getContent(int contentId)
{
    return contents.getEntry(contentFindPosition(contentId));
}

void ContentCreator::addContent(int contentID)
{
    // no need to check whether id is added before because i checked that in addContent function of SMP.cpp
    int position = 1;

    if(contents.getLength() > 0)
    {   
        position = contentFindPosition(contentID);
    }
    
    contents.insert(position, contentID); 
}

void ContentCreator::removeContent(int contentId)
{
    contents.remove(contentFindPosition(contentId));
}

void ContentCreator::addFollower(int followerID)
{
    if(followerExist(followerID))
    {
        cout << "Cannot follow. The user is already following the content creator." << endl;
    }
    else
    {
        int position = 1;
        if(followers.getLength() > 0)
        {
            position = followerFindPosition(followerID);
        }

        followers.insert(position, followerID);
        cout << "Regular user with ID " << followerID << " followed content creator with ID " << id << "." << endl;
    }
}

void ContentCreator::removeFollower(int followerID, bool userIsRemoved)
{
    if(userIsRemoved)
    {
        if(followerExist(followerID))
        {
            followers.remove(followerFindPosition(followerID));
        }
    }
    else
    {
        if(followerExist(followerID))
        {
            followers.remove(followerFindPosition(followerID));
            cout << "Regular user with ID " << followerID << " unfollowed content creator with ID " << id << "." << endl;
        }
        else
        {
            cout << "Cannot unfollow. The user is not following the content creator." << endl;
        }
    }
}

int ContentCreator::contentFindPosition(int contentId)
{
    int position = -1;
    bool stop = false;

    for(int i = 1; i <= contents.getLength() && !stop; i++)
    {
        position = i;

        if(contentId <= contents.getEntry(i))
        {
            stop = true;
        }
    }

    if(!stop) 
        position++;

    return position;
}

int ContentCreator::followerFindPosition(int followerId)
{
    int position = -1;
    bool stop = false;

    for(int i = 1; i <= followers.getLength() && !stop; i++)
    {
        position = i;

        if(followerId <= followers.getEntry(i))
        {
            stop = true;
        }
    }

    if(!stop) 
        position++;

    return position;
}

bool ContentCreator::contentExist(int contentId)
{
    bool exist = false;

    for(int i = 1; i < contents.getLength() + 1; i++)
    {
        if(contentId == contents.getEntry(i))
        {
            exist = true;
        }
    }

    return exist;
}

bool ContentCreator::followerExist(int followerId)
{
    bool exist = false;

    for(int i = 1; i < followers.getLength() + 1; i++)
    {
        if(followerId == followers.getEntry(i))
        {
            exist = true;
        }
    }

    return exist;
}

void ContentCreator::displayContents()
{
    cout << "Contents of content creator with ID " << id << ":" << endl;
    if(contents.getLength() > 0)
    {
        for(int i = 1; i <= contents.getLength(); i++)
        {
            cout << contents.getEntry(i) << endl;
        }
    }
    else
    {
        cout << "None" << endl;
    }
}

void ContentCreator::displayFollowers()
{
    if(followers.getLength() > 0)
    {
        for(int i = 1; i < followers.getLength() + 1; i++)
        {
            cout << followers.getEntry(i) << endl;
        }
    }
    else
    {
        cout << "None" << endl;
    }
}

void ContentCreator::display()
{
    cout << id << ", " << name << ", " << followers.getLength() << " follower(s), " << contents.getLength() << " content(s)" << endl;
}