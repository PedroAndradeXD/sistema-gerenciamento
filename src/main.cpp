#include <iostream>
#include <string>

#include "domain/User.h"
#include "repository/UserRepository.h"
#include "service/UserService.h"


// Função para exibir o menu
void showMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Criar usuário\n";
    std::cout << "2. Atualizar usuário\n";
    std::cout << "3. Desabilitar usuário\n";
    std::cout << "4. Habilitar usuário\n";
    std::cout << "5. Listar usuários\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
}

// Função para exibir método createUser
void showCreateUser(UserService& service) {
    std::string name, email;

    std::cout << "Informe o nome do usuário: ";
    std::getline(std::cin, name);
    std::cout << "Informe o email do usuário: ";
    std::getline(std::cin, email);

    if (service.createUser(name, email)) {
        std::cout << "Usuário criado com sucesso!\n";
    } else {
        std::cout << "Email já cadastrado.\n";
    }
}

int main() {
    UserRepository repo; //Cria o repositório
    UserService service(repo); //Passa o repositório para o service
    int option; // Variável de opção para o menu interativo
    
    do {
    showMenu();
    std::cin >> option;
    std::cin.ignore();

    switch (option) {
        case 1:
            showCreateUser(service);
            break;
        case 2:
            // update
            break;
        case 3:
            // disable
            break;
        case 4:
            // enable
            break;
        case 5:
            // list
            break;
        case 0:
            std::cout << "Encerrando programa...\n";
            break;
        default:
            std::cout << "Opção inválida.\n";
    }

    } while (option != 0);

    }