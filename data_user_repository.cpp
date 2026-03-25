#include "data_user_repository.h"

namespace data {

InMemoryUserRepository::InMemoryUserRepository()
    : m_validUsername("admin"), m_validPassword("password")
{
}

bool InMemoryUserRepository::validateUser(const domain::UserCredentials &credentials)
{
    return credentials.username == m_validUsername && credentials.password == m_validPassword;
}

} // namespace data
