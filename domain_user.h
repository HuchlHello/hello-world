#ifndef DOMAIN_USER_H
#define DOMAIN_USER_H

#include <QString>

namespace domain {

struct UserCredentials {
    QString username;
    QString password;
};

} // namespace domain

#endif // DOMAIN_USER_H
