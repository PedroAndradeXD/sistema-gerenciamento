#include "UserRepository.h"
#include "../domain/User.h"

// Salva ou atualiza um usuário no repositório
void UserRepository::save(const User& user) {
    // Se o usuário já existe, atualiza
    for(auto& existingUser : users) {
        if(existingUser.getId() == user.getId()) {
            existingUser = user;
            return;
        }
    }
    // Se não existir, adiciona novo usuário
    users.push_back(user);
}

// Retorna o usuário com o ID especificado, ou nullopt se não existir
std::optional<User> UserRepository::findById(int id) {
    for(const auto& existingUser : users) {
        if(existingUser.getId() == id) {
            return existingUser;
        }
    }
    return std::nullopt;
}

// Retorna o usuário com o email especificado, ou nullopt se não existir
std::optional<User> UserRepository::findByEmail(const std::string& email) {
    for(const auto& existingUser : users) {
        if(existingUser.getEmail() == email) {
            return existingUser;
        }
    }
    return std::nullopt;
}

// Retorna todos os usuários cadastrados
std::vector<User> UserRepository::findAll() {
    return users;
}
