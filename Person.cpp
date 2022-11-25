#include "Person.h"


Person::Person()
{
}


Person::Person(const Person &p)
        : first_name(p.first_name),
        middle_name(p.middle_name),
        last_name(p.last_name)
 {
 }


const std::string &
Person::getLastName() const
{
    return last_name;
}


const std::string &
Person::getMiddleName() const
{
    return middle_name;
}


const std::string &
Person::getFirstName() const
{
    return first_name;
}


void
Person::setLastName(const std::string &ln)
{
    last_name = ln;
}


void
Person::setMiddleName(const std::string &mn)
{
    middle_name = mn;
}


void
Person::setFirstName(const std::string &fn)
{
    first_name = fn;
}
