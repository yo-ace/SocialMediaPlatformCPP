/**
 * @author Irmak İmdat 
*/
#include "RegularUser.h"
using namespace std;

RegularUser::RegularUser()
{
    id = 0;
    name = "";
}

RegularUser::RegularUser(int newId, string newName)
{
    id = newId;
    name = newName;
}

int RegularUser::getID()
{
    return id;
}

string RegularUser::getName()
{
    return name;
}

void RegularUser::setName(string newName)
{
    name = newName;
}

void RegularUser::setID(int newID)
{
    id = newID;
}

RegularUser& RegularUser::operator=( const RegularUser& right)
{
    this->id = right.id;
    this->name = right.name;
    return *this;
}

bool RegularUser::followingTheContentCreator(int id)
{
    return true;
}