#include "user.h"

User::User()
{

}

void User::setUserId(int user_id)
{
    this->user_id_ = user_id;
}

void User::setAcessLevel(AcessLevel level)
{
    this->acess_level_ = level;
}

QString User::getUserFullname()
{
    return " ";
}

