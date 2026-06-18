#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <string>
using namespace std;
class Pessoa{
    protected:
        string nome;
        string cpf;
    public:
        Pessoa(string nome, string cpf);
        void setNome(string nome);
        string getNome() const;
        void setCpf(string cpf);
        string getCpf() const;
        virtual void exibirDados();
        virtual ~Pessoa();
};
#endif