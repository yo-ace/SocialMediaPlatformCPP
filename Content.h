/**
 * @author Irmak İmdat 
*/
#ifndef CONTENT_H
#define CONTENT_H

#include <string>
using namespace std;

class Content
{
    private:
        
        int id;
        string title;

    public:
        Content();
        Content(int newID, string newTitle);
        ~Content();
        int getID();
        string getName();
};

#endif