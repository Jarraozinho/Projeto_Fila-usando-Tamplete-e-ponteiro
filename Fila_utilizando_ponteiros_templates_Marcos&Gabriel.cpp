// Marcos Fillipe Silva Souza - 2021004687 //
// Gabriel Henrique de Souza da Silva - 2022003648 //
// comentarios do .cpp
#include<iostream> // funcao padrao usada
#include <time.h> // funcao p/ mostrar dd/mm/aa e hora:minuto:segundo
#define SIZE 5   
// nao foi utilizada a ferramenta using namespace std,visando a reducao do arquivo
template < typename TemplateFila > class Fila {
    private:
        TemplateFila * arr;
    int findice, rIndice;
    public:
        Fila() {
            arr = new TemplateFila[SIZE];
            findice = 0;
            rIndice = 0;
        }
// template fila

    bool FilaCheia() {
        return (rIndice + 1) % SIZE == findice;
    }

    bool FilaVazia() {
        return rIndice == findice;
    }

    void Enfileirar(TemplateFila item) {
        if (FilaCheia()) {
            std::cout << "Fila esta cheia" << std::endl;
            std::cout << "Delete um elemento para inserir outro" << std::endl;
            return;
        }
        *(this->arr + this->rIndice) = item;
        this->rIndice = (this->rIndice + 1) % SIZE;
    }

    void Desenfileirar() {
        if (FilaVazia()) {
            std::cout << "Fila esta Vazia" << std::endl;
            std::cout << "Insira um elemento para deletar posteriomente" << std::endl;
            return;
        }
        std::cout<< front() << " deletado da fila" << std::endl;
        findice = (findice + 1) % SIZE;
    }

      TemplateFila front(){
        return FilaVazia() ? NULL : *(arr + findice);
    }
};

int main() {
    // funcao acrescida para fins de teste
    time_t now;
    time(&now);
    printf("%s", ctime(&now));

    bool salir = false;
    Fila < int > fila;
    int temp;
    do {
        std::cout << "====================================" << std::endl;
        printf("%s", ctime(&now));
        std::cout << "Selecione a opcao :" << std::endl;
        std::cout << "1 p/ Enfileirar" << std::endl;
        std::cout << "2 p/ Primeiro elemento da Fila" << std::endl;
        std::cout << "3 p/ Desenfileirar" << std::endl;
        std::cout << "4 p/ Salir del programa" << std::endl;
        int elegir;
        std::cin >> elegir;
        std::cout << "====================================" << std::endl;
        switch (elegir) {
            case 1:
                std::cout << "Digite um elemento para a fila:" << std::endl;
                std::cin >> temp;
                fila.Enfileirar(temp);
                break;
            case 3:
                fila.Desenfileirar();
                break;
            case 2:
                if (fila.FilaVazia()) {
                    std::cout << "Fila esta vazia" << std::endl;
                } else {
                    std::cout << "front: " << fila.front() << std::endl;
                }
                break;
            case 4:
                salir = true;
                break;
            default:
                std::cout << "Opcao Invalida ..... " << "Digite um elemento de 1 a 4" << std::endl;
                break;
        }
    } while (!salir);
    return 0;
}
