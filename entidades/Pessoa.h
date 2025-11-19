// Pessoa.h
#pragma once
#include "../dominios/Nome.h"
#include "../dominios/Email.h"

/**
 * @brief Classe base abstrata para pessoas.
 */
class Pessoa {
protected:
    Nome nome;
    Email email;
public:
    Pessoa(const Nome& n, const Email& e) : nome(n), email(e) {}
    void setNome(const Nome& n) { nome = n; }
    void setEmail(const Email& e) { email = e; }
    Nome getNome() const { return nome; }
    Email getEmail() const { return email; }
    virtual ~Pessoa() {}
};
