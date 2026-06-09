#ifndef MEDICO_HPP
#define MEDICO_HPP

#include "Usuario.hpp"
#include "Interfaces.hpp"

class Medico : public Usuario,
                public IAutenticavel,
                public IRelatorio,
                public IAssinaturaDigital {

public:
    Medico(string n, string m, string s);

    void autenticar() override;

    void gerarRelatorio() override;

    void assinarDocumento() override;
};

#endif