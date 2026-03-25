#ifndef DATA_USER_REPOSITORY_H
#define DATA_USER_REPOSITORY_H

#include "domain_user.h"

namespace data {

class IUserRepository
{
public:
    virtual ~IUserRepository() = default;
    virtual bool validateUser(const domain::UserCredentials &credentials) = 0;
};

class InMemoryUserRepository : public IUserRepository
{
public:
    InMemoryUserRepository();
    bool validateUser(const domain::UserCredentials &credentials) override;

private:
    QString m_validUsername;
    QString m_validPassword;
};

} // namespace data

#endif // DATA_USER_REPOSITORY_H
