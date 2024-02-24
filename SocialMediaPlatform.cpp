/**
 * @author Irmak İmdat 
*/

#include <iostream>
#include "SocialMediaPlatform.h"
using namespace std;

SocialMediaPlatform::SocialMediaPlatform()
{

}

SocialMediaPlatform::~SocialMediaPlatform()
{
    
}

void SocialMediaPlatform::addRegularUser( const int regularUserId, const string name )
{
    if(regularUserIDExist(regularUserId))
    {
        cout << "Cannot add regular user. There is already a regular user with ID " << regularUserId << "." << endl;
    }
    else
    {
        RegularUser* newNode = new RegularUser(regularUserId, name);
        int position = 1;
        if(regularUsers.getLength() > 0) 
        {
            position = regularUserFindPosition(regularUserId);
        }
        
        regularUsers.insert(position, *newNode);
        cout << "Added regular user " << regularUserId << "." << endl;
        delete newNode;
    }
}

void SocialMediaPlatform::removeRegularUser( const int regularUserId )
{
    if(regularUserIDExist(regularUserId))
    {
        int position = regularUserFindPosition(regularUserId);
        
        regularUsers.remove(position);
        cout << "Removed regular user " << regularUserId << "." << endl;

        for(int i = 1; i < contentCreators.getLength() + 1; i++)
        {
            contentCreators.getEntry(i).removeFollower(regularUserId, true);
        }
    }
    else
    {
        cout << "Cannot remove regular user. There is no regular user with ID " << regularUserId << "." << endl;
    }
}

void SocialMediaPlatform::addContentCreator( const int contentCreatorId, const string name )
{
    if(contentCreatorIDExist(contentCreatorId))
    {
        cout << "Cannot add content creator. There is already a content creator with ID " << contentCreatorId << "." << endl;
    }
    else
    {
        ContentCreator* newNode = new ContentCreator(contentCreatorId, name);
        int position = 1;
        if(contentCreators.getLength() > 0) 
        {
            position = contentCreatorFindPosition(contentCreatorId);
        }
        
        contentCreators.insert(position, *newNode);
        cout << "Added content creator " << contentCreatorId << "." << endl;

        delete newNode;
    }
}

void SocialMediaPlatform::removeContentCreator(const int contentCreatorId )
{
    if(contentCreatorIDExist(contentCreatorId))
    {   
        int position = contentCreatorFindPosition(contentCreatorId);
        
        for(int i = 1; i <= contents.getLength(); i++)
        {
            if(contentCreators.getEntry(position).contentExist(contents.getEntry(i).getID()))
            {
                contents.remove(i);
                i--;
            }
        }
        contentCreators.remove(position);
        cout << "Removed content creator " << contentCreatorId << "." << endl;
    }
    else
    {
        cout << "Cannot remove content creator. There is no content creator with ID " << contentCreatorId << "." << endl;
    }
}

void SocialMediaPlatform::addContent( const int contentCreatorId, const int contentId, const string title )
{
    if(contentIDExist(contentId))
    {
        cout << "Cannot add content. There is already a content with ID " << contentId << "." << endl;
    }
    else
    {
        if(contentCreatorIDExist(contentCreatorId))
        {
            // add content to content list
            Content* newEntry = new Content(contentId, title);
            int position = 1;
            if(contents.getLength() > 0) 
            {
                position = contentFindPosition(contentId);
            }

            contents.insert(position, *newEntry);

            // add content to content creators content list
            position = 1;
            if(contentCreators.getLength() > 0) 
            {
                position = contentCreatorFindPosition(contentCreatorId);
            }

            contentCreators.getEntry(position).addContent(contentId);
            cout << "Added content " << contentId << "." << endl;
            
            delete newEntry;
        }
        else
        {
            cout << "Cannot add content. There is no content creator with ID " << contentCreatorId << "." << endl;
        }
    }
}

void SocialMediaPlatform::removeContent( const int contentCreatorId, const int contentId )
{
    if(contentCreatorIDExist(contentCreatorId))
    {
        int contentCreatorPosition = contentCreatorFindPosition(contentCreatorId);
        
        if(contentCreators.getEntry(contentCreatorPosition).contentExist(contentId))
        {
            contentCreators.getEntry(contentCreatorPosition).removeContent(contentId);
            contents.remove(contentFindPosition(contentId));
            cout << "Removed content " << contentId << "." << endl;
        }
        else
        {
            cout << "Cannot remove content. There is no content with ID " << contentId << 
            " shared by content creator with ID " << contentCreatorId << "." << endl;
        }
    }
    else
    {
        cout << "Cannot remove content. There is no content creator with ID " << contentCreatorId << "." << endl;
    }
}

void SocialMediaPlatform::followContentCreator( const int regularUserId, const int contentCreatorId )
{
    if(contentCreatorIDExist(contentCreatorId) && regularUserIDExist(regularUserId))
    {
        int posOfContentCreator = contentCreatorFindPosition(contentCreatorId);
        contentCreators.getEntry(posOfContentCreator).addFollower(regularUserId);
    }
    else
    {
        cout << "Cannot follow. Regular user and/or content creator ID does not exist." << endl;
    }
}

void SocialMediaPlatform::unfollowContentCreator( const int regularUserId, const int contentCreatorId)
{
    if(contentCreatorIDExist(contentCreatorId) && regularUserIDExist(regularUserId))
    {
        int posOfContentCreator = contentCreatorFindPosition(contentCreatorId);
        contentCreators.getEntry(posOfContentCreator).removeFollower(regularUserId, false);
    }
    else
    {
        cout << "Cannot unfollow. Regular user and/or content creator ID does not exist." << endl;
    }
}

void SocialMediaPlatform::showContentsOf( const int contentCreatorId ) const
{
    if(contentCreatorIDExist(contentCreatorId))
    {
        int position = contentCreatorFindPosition(contentCreatorId);
        contentCreators.getEntry(position).displayContents();
    }
    else
    {
        cout << "Cannot show. There is no content creator with ID " << contentCreatorId << "." << endl;

    }
}

void SocialMediaPlatform::showFollowersOf( const int contentCreatorId ) const
{   
    if(contentCreatorIDExist(contentCreatorId))
    {
        cout << "Regular users following content creator with ID " << contentCreatorId << ":" << endl;

        int position = contentCreatorFindPosition(contentCreatorId);
        contentCreators.getEntry(position).displayFollowers();
    }
    else
    {
        cout << "Cannot show. There is no content creator with ID " << contentCreatorId << "." << endl;
    }
}

void SocialMediaPlatform::showAllRegularUsers() const
{
    cout << "Regular users in the social media platform:" << endl;

    if(regularUsers.getLength() > 0)
    {
        for(int i = 1; i < regularUsers.getLength() + 1; i++)
        {
            cout << regularUsers.getEntry(i).getID() << ", " << regularUsers.getEntry(i).getName() << endl;
        }
    }
    else
    {
        cout << "None" << endl;
    }
}

void SocialMediaPlatform::showAllContents() const
{
    if(!contents.isEmpty())
    {
        for(int i = 1; i < contents.getLength() + 1; i++)
        {
            cout << contents.getEntry(i).getID() << endl;
        }
    }
    else
    {
        cout << "None" << endl;
    }
}


void SocialMediaPlatform::showAllContentCreators() const
{
    cout << "Content creators in the social media platform:" << endl;

    if(contentCreators.getLength() > 0)
    {
        for(int i = 1; i < contentCreators.getLength() + 1; i++)
        {
            contentCreators.getEntry(i).display();
        }
    }
    else
    {
        cout << "None" << endl;
    }
}

bool SocialMediaPlatform::regularUserIDExist(int id)
{
    bool exist = false;

    for(int i = 1; i < regularUsers.getLength() + 1; i++)
    {
        if(id == regularUsers.getEntry(i).getID())
        {
            exist = true;
        }
    }

    return exist;
}

bool SocialMediaPlatform::contentCreatorIDExist(int id) const
{
    bool exist = false;

    for(int i = 1; i < contentCreators.getLength() + 1; i++)
    {
        if(id == contentCreators.getEntry(i).getID())
        {
            exist = true;
        }
    }

    return exist;
}

bool SocialMediaPlatform::contentIDExist(int id)
{
    bool exist = false;

    for(int i = 1; i < contents.getLength() + 1; i++)
    {
        if(id == contents.getEntry(i).getID())
        {
            exist = true;
        }
    }

    return exist;
}

int SocialMediaPlatform::regularUserFindPosition(int regularUserID)
{
    int position = -1;
    bool stop = false;

    for(int i = 1; i <= regularUsers.getLength() && !stop; i++)
    {
        position = i;

        if(regularUserID <= regularUsers.getEntry(i).getID()) 
        {
            stop = true;
        }
    }

    if(!stop) // it is bigger than all values
        position++;

    return position;
}

int SocialMediaPlatform::contentCreatorFindPosition(int contentCreatorID) const
{
    int position = -1;
    bool stop = false;

    for(int i = 1; i <= contentCreators.getLength() && !stop; i++)
    {
        position = i;

        if(contentCreatorID <= contentCreators.getEntry(i).getID())
        {
            stop = true;
        }
    }

    if(!stop) // it is bigger than all values
        position++;

    return position;
}

int SocialMediaPlatform::contentFindPosition(int contentID)
{
    int position = -1;
    bool stop = false;

    for(int i = 1; i <= contents.getLength() && !stop; i++)
    {
        position = i;

        if(contentID <= contents.getEntry(i).getID())
        {
            stop = true;
        }
    }

    if(!stop) // it is bigger than all values
        position++;

    return position;
}