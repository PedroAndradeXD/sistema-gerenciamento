#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <string>
#include <vector>

#include "../domain/User.h"

class UserRepository;

// Gerencia a lógica e as regras de negócio do sistema
class UserService {
    private:
        UserRepository& userRepository;

        // Gera o próximo ID disponível para um novo usuário
        int generateNextId();

    public:
        // Inicializa o serviço com o repositório de usuários
        UserService(UserRepository& userRepository) 
        : userRepository(userRepository) {}

        // Cria um novo usuário com nome e email, garantindo unicidade de email
        bool createUser(const std::string& name, const std::string& newEmail);

        // Atualiza o nome e/ou email de um usuário existente
        void updateUser(int id, const std::string& newName, const std::string& email);

        // Torna o usuário inativo (aplica regra de negócios)
        void disableUser(int id);

        // Torna o usuário ativo (aplica regra de negócios)
        void enableUser(int id);

        // Retorna todos os usuários cadastrados
        std::vector<User> listUsers() const;
};

#endif
