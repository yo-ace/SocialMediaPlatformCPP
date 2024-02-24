/**
 * @author Irmak İmdat 
*/
#include "Content.h"
using namespace std;

/*
 * Default constructor
*/
Content::Content() 
{
    id = 0;
    title = "";
}

/**
 * @param newID is the id for the content
*/
Content::Content(int newID, string newTitle)
{
    id = newID;
    title = newTitle;
}

Content::~Content()
{
    
}

int Content::getID()
{
    return id;
}

string Content::getName()
{
    return title;
}