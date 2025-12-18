# 🧑‍💻 Sistema de Gerenciamento de Usuários em C++

![Status](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)
![C++](https://img.shields.io/badge/lang-C%2B%2B-blue)

Sistema completo de gerenciamento de usuários, desenvolvido em C++ com foco em **POO**, arquitetura limpa e boas práticas.  
O sistema permite criar, consultar, atualizar e gerenciar usuários de forma segura e organizada.

---

## Funcionalidades Principais

- **Gerenciamento de Usuários**
  - Criar novos usuários com `id`, `nome`, `email` e status (`ativo`/`inativo`)
  - Atualizar dados de usuários existentes
  - Ativar ou desativar usuários
  - Garantir unicidade de emails

- **Consulta e Listagem**
  - Buscar usuário por ID
  - Buscar usuário por email
  - Listar todos os usuários cadastrados

- **Repositório em memória**
  - Armazena os usuários de forma segura
  - Permite operações de CRUD sem depender de banco externo
  - Usa `std::optional` para buscas que podem não retornar resultado

- **Serviços e Validações**
  - `UserService` gerencia regras de negócio
  - Validação de dados e consistência do sistema
  - Separação clara entre armazenamento (UserRepository) e regras de negócio (UserService)

---

## Estrutura do Projeto

/meu-projeto
├── User.h # Entidade usuário
├── UserRepository.h/.cpp # Repositório para CRUD em memória
├── UserService.h/.cpp # Lógica de negócio e validações
├── main.cpp # Ponto de entrada para testes e demonstração
└── README.md

---

## Propósito do Projeto

O sistema foi desenvolvido como **exercício avançado de C++** e **prática de arquitetura limpa**, permitindo:

- Aprender e aplicar conceitos de POO
- Criar um backend simples para gerenciamento de usuários
- Implementar repositórios em memória e serviços de lógica de negócio
- Fornecer uma base escalável para integrar futuras funcionalidades, como persistência em banco de dados ou interface gráfica

---

## Como executar

Clone o repositório:

```bash
git clone https://github.com/PedroAndradeXD/sistema-gerenciamento.git
```

Acesse a pasta raiz do projeto:

```bash
cd sistema-gerenciamento
```

Compile o projeto:

```bash
g++ -std=c++17 -Wall -Wextra -g3 \
src/main.cpp \
src/domain/User.cpp \
src/repository/UserRepository.cpp \
src/service/UserService.cpp \
-o output/main.exe
```

Execute:

```bash
./output/main.exe
```

Nota: atualmente os dados são armazenados apenas em memória.

Autor

Pedro Andrade

