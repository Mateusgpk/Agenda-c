# Agenda-c
Este projeto é uma aplicação simples de linha de comando desenvolvida em linguagem C para gerenciamento de contatos. Ele permite adicionar, buscar, listar e excluir contatos, utilizando armazenamento em arquivo binário para persistência dos dados.

##Estrutura
O programa utiliza uma struct para representar cada contato:  

typedef struct   
{  
    int id;  
    char nome[50];  
    char telefone[20];  
    char email[100];  
} contato;  

## Armazenamento de dados  
- Os contatos são salvos no arquivo contatos.dat
- O arquivo é lido ao iniciar o programa
- Todas as alterações são salvas automaticamente após modificações

## Conceitos Utilizados
- Os dados são armazenados dinamicamente na memória usando malloc e realloc, e persistidos em arquivo binário.
- Alocação dinâmica (malloc, realloc, free)
- Manipulação de arquivos binários (fopen, fread, fwrite)
- Structs em C
- Strings (strstr, scanf, fgets)
- Controle de fluxo (switch, loops)
