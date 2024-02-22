/**
 * @author Irmak İmdat 
*/
#ifndef SOCIALMEDIAPLATFORM_H
#define SOCIALMEDIAPLATFORM_H

#include "LinkedList.h"
#include "RegularUser.h"
#include "ContentCreator.h"
#include "Content.h"
#include <iostream>
using namespace std;

class SocialMediaPlatform 
{
    public:

        SocialMediaPlatform();
        ~SocialMediaPlatform();
        void addRegularUser( const int regularUserId, const string name );
        void removeRegularUser( const int regularUserId );
        void addContentCreator( const int contentCreatorId, const string name );
        void removeContentCreator( const int contentCreatorId );
        void addContent( const int contentCreatorId, const int contentId, const string title );
        void removeContent( const int contentCreatorId, const int contentId );
        void followContentCreator( const int regularUserId, const int contentCreatorId );
        void unfollowContentCreator( const int regularUserId, const int contentCreatorId);
        void showFollowersOf( const int contentCreatorId ) const;
        void showContentsOf( const int contentCreatorId ) const;
        void showAllRegularUsers( ) const;
        void showAllContentCreators( ) const;
        void showAllContents() const;
        bool regularUserIDExist(int id);
        bool contentCreatorIDExist(int id) const;
        bool contentIDExist(int id);
        int regularUserFindPosition(int regularUserID);
        int contentCreatorFindPosition(int contentCreatorID) const;
        int contentFindPosition(int contentID);
        int removeFromContCreatorsFollowers(int regularUserId);

    private:

        //lists in here
        LinkedList<RegularUser> regularUsers;
        LinkedList<ContentCreator> contentCreators;
        LinkedList<Content> contents;
};

#endif
