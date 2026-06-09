#ifndef ENFERMEIRO_HPP
#define ENFERMEIRO_HPP

#include "Usuario.hpp"
#include "Interfaces.hpp"

class Enfermeiro : public Usuario,
                    public IAutenticavel,
                    public IRelatorio {

public:
    Enfermeiro(string n, string m, string s);

    void autenticar() override;

    void gerarRelatorio() override;
};

#endif