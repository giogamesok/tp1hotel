#pragma once
#include "../entidades/Pessoa.h"
#include <vector>

/**
 * @interface IPessoaService
 * @brief Interface genérica para operações sobre pessoas (hóspedes e gerentes).
 */
class IPessoaService {
public:
    virtual ~IPessoaService() = default;

    virtual std::vector<Pessoa> listarPessoas() const = 0;
    virtual void criarPessoa(const Pessoa& pessoa) = 0;
    virtual void removerPessoa(const std::string& email) = 0;
};
