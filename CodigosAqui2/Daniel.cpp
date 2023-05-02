#include <iostream>
#include <set>
#include <iomanip>
class Cadastro{
public:
    std::string nome;
    unsigned int idade;
    std::string rh;
    double altura;
};
class Comparadora{
public:
bool operator()(const Cadastro &a, const Cadastro &b){
    return a.nome < b.nome;
}
};

int main(){
    std::set<Cadastro, Comparadora> ficha;
    Cadastro *aux = new Cadastro;
    unsigned int ad = 1;
    while(aux->nome != "s"){
        std::cout << "pessoa n" << ad << std::endl;
        std::cout << "-----------------------" << std::endl;
        ad++;
        getline(std::cin, aux->nome);
        if(aux->nome == "s"){
            break;
        }
        std::cin >> aux->idade;
        std::cin.ignore();
        getline(std::cin, aux->rh);
        std::cin >> aux->altura;
        std::cin.ignore();
        ficha.insert(*aux);
        aux = new Cadastro;
     }

    for(Cadastro a : ficha){
    std::cout << std::setprecision(3);
    std::cout << "Nome: " << a.nome << " "<< "Idade: " << a.idade << " "<< "rh: " << a.rh << " " << "Altura: ";
    printf("%0.2lf\n",a.altura);
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

    }
    return 0; 
}