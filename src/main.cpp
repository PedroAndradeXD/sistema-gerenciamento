#include <iostream>
#include <string>
#include <limits>

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

// Exibe a interface de criação de usuário no terminal
// Responsável apenas por coletar dados e delegar a criação ao UserService
void showCreateUser(UserService& service) {
    // Variáveis para armazenar os dados informados pelo usuário
    std::string name, email;

    // Solicita o nome do usuário
    std::cout << "Informe o nome do usuário: ";
    std::getline(std::cin, name);
    
    // Solicita o email do usuário
    std::cout << "Informe o email do usuário: ";
    std::getline(std::cin, email);

    // Tenta criar o usuário através da camada de serviço
    if (service.createUser(name, email)) {
        std::cout << "Usuário criado com sucesso.\n";
    } else {
        std::cout << "Email já cadastrado.\n";
    }
}


// Exibe a interface de atualização de usuário no terminal
// Coleta os dados, chama o serviço e trata os possíveis resultados
void showUpdateUser(UserService& service) {
    // Variáveis para armazenar os dados informados pelo usuário
    int id;
    std::string name, email;

    // Solicita o ID do usuário a ser atualizado
    std::cout << "Informe o ID do usuário: ";
    std::cin >> id;

    // Limpa o buffer de entrada para evitar problemas com getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Solicita o novo nome do usuário
    std::cout << "Informe o nome do usuário: ";
    std::getline(std::cin, name);
    
    // Solicita o novo email do usuário
    std::cout << "Informe o email do usuário: ";
    std::getline(std::cin, email);

    // Executa a atualização através da camada de serviço
    UpdateUserResult result = service.updateUser(id, name, email);

    // Trata o resultado da atualização com mensagens específicas
    switch (result) {
        case UpdateUserResult::SUCCESS:
            std::cout << "Usuário atualizado com sucesso.\n";
            break;
        case UpdateUserResult::ID_NOT_FOUND:
            std::cout << "Usuário não encontrado.\n";
            break;
        case UpdateUserResult::EMAIL_ALREADY_EXISTS:
            std::cout << "Email já em uso.\n";
            break;
    }
}

void showDisableUser(UserService& service) {
    int id;

    // Solicita o ID do usuário
    std::cout << "Informe o ID do usuário: ";
    std::cin >> id;

    // Limpa o buffer de entrada para evitar problemas com getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Tenta desabilitar o usuário via camada de serviço
    if (service.disableUser(id)) {
        std::cout << "Usuário desabilitado com sucesso.\n";
    } else {
        std::cout << "Usuário não encontrado.\n";
    }
}

void showEnableUser(UserService& service) {
    int id;

    // Solicita o ID do usuário a ter o status modificado
    std::cout << "Informe o ID do usuário: ";
    std::cin >> id;

    // Limpa o buffer de entrada para evitar problemas com getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Tenta habilitar o usuário através da camada de serviço
    if (service.enableUser(id)) {
        std::cout << "Usuário habilitado com sucesso.\n";
    } else {
        std::cout << "Usuário não encontrado.\n";
    }
}

int main() {
    UserRepository repo; //Cria o repositório
    UserService service(repo); //Passa o repositório para o service
    int option; // Variável de opção para o menu interativo
    
    do {
    showMenu();
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (option) {
        case 1:
            showCreateUser(service);
            break;
        case 2:
            showUpdateUser(service);
            break;
        case 3:
            showDisableUser(service);
            break;
        case 4:
            showEnableUser(service);
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