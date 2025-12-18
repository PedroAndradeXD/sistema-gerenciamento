#include "UserService.h"
#include "../repository/UserRepository.h"

#include <algorithm>

// Gera o próximo ID disponível para um novo usuário
int UserService::generateNextId() {
    // Obtém todos os usuários cadastrados
    std::vector<User> users = userRepository.findAll();

    // Se não houver usuários, começa com ID 1
    if (users.empty()) {
        return 1;
    }

    // Encontra o maior ID existente
    int maxId = 0;
    for (const auto& user : users) {
        if (user.getId() > maxId)
            maxId = user.getId();
    }

    // Retorna o próximo ID
    return maxId + 1;
}

// Cria um novo usuário se o email não estiver em uso
bool UserService::createUser(const std::string& name, const std::string& email) {
    // Verifica se o email já está em uso
    if (userRepository.findByEmail(email)) {
        return false;
    }

    // Gera o próximo ID e cria o usuário
    int id = generateNextId();
    User user(id, name, email);

    // Salva o usuário no repositório
    userRepository.save(user);

    return true;
}

// Atualiza o nome e/ou email de um usuário existente
 UpdateUserResult UserService::updateUser(int id, const std::string& newName, const std::string& newEmail) {
    // Busca usuário pelo ID
    auto userOpt = userRepository.findById(id);
    if (!userOpt) {
        return UpdateUserResult::ID_NOT_FOUND;
    }

    // Cria uma cópia mutável do usuário
    User user = userOpt.value();

    // Atualiza o email se necessário e verifica duplicidade
    if (newEmail != user.getEmail()) {
        if (userRepository.findByEmail(newEmail)) {
            return UpdateUserResult::EMAIL_ALREADY_EXISTS;
        }
        user.setEmail(newEmail);
    }

    // Atualiza o nome se necessário
    if (newName != user.getName()) {
        user.setName(newName);
    }

    // Salva alterações no repositório
    userRepository.save(user);

    return UpdateUserResult::SUCCESS;
}

 // Torna o usuário inativo (aplica regra de negócios)
void UserService::disableUser(int id) {
    // Busca usuário pelo ID
    auto userOpt = userRepository.findById(id);
    if (!userOpt) {
        return;
    }

    // Cria uma cópia mutável do usuário
    User user = userOpt.value();

    // Desativa o usuário (altera o estado interno do objeto)
    user.disable();

    // Salva a alteração no repositório
    userRepository.save(user);
}

// Torna o usuário ativo (aplica regra de negócios)
void UserService::enableUser(int id) {
    // Busca usuário pelo ID
    auto userOpt = userRepository.findById(id);
    if (!userOpt) {
        return;
    }

    // Cria uma cópia mutável do usuário
    User user = userOpt.value();

    // Ativa o usuário (altera o estado interno do objeto)
    user.enable();

    // Salva a alteração no repositório
    userRepository.save(user);
}

// Retorna todos os usuários cadastrados
std::vector<User> UserService::listUsers() const {
    return userRepository.findAll();
}