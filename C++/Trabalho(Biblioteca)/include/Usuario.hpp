#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "Pessoa.hpp"
class Usuario:public Pessoa{
    private:
        int matricula;
    public:
        Usuario(int matricula, string nome, string cpf);
        void consultarLivros();
        int getMatricula() const;
        void exibirDados() override;
};
#endif