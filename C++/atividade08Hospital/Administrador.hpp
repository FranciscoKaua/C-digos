#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Usuario.hpp"
#include "Interfaces.hpp"

class Administrador : public Usuario,
                       public IAutenticavel,
                       public IAuditoria {

public:
    Administrador(string n, string m, string s);

    void autenticar() override;

    void registrarLog() override;
};

#endif