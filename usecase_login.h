#ifndef USECASE_LOGIN_H
#define USECASE_LOGIN_H

#include "domain_user.h"
#include "data_user_repository.h"

namespace usecase {

class LoginUseCase
{
public:
    explicit LoginUseCase(data::IUserRepository *repo);
    bool execute(const domain::UserCredentials &credentials);

private:
    data::IUserRepository *m_repo;
};

} // namespace usecase

#endif // USECASE_LOGIN_H
