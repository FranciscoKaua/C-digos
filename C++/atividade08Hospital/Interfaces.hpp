#ifndef INTERFACES_HPP
#define INTERFACES_HPP

class IAutenticavel {
public:
    virtual void autenticar() = 0;
};

class IRelatorio {
public:
    virtual void gerarRelatorio() = 0;
};

class IAssinaturaDigital {
public:
    virtual void assinarDocumento() = 0;
};

class IAuditoria {
public:
    virtual void registrarLog() = 0;
};

#endif