#include "usecase_login.h"

namespace usecase {

LoginUseCase::LoginUseCase(data::IUserRepository *repo)
    : m_repo(repo)
{
}

bool LoginUseCase::execute(const domain::UserCredentials &credentials)
{
    if (!m_repo)
        return false;
    return m_repo->validateUser(credentials);
}

} // namespace usecase
