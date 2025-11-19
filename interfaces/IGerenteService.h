#pragma once
#include "../entidades/Gerente.h"
#include <vector>

/**
 * @interface IGerenteService
 * @brief Interface para operações relacionadas a gestores (gerentes).
 */
class IGerenteService {
public:
    virtual ~IGerenteService() = default;

    /**
     * @brief Lista os gerentes existentes.
     * @return Vetor de gerentes.
     */
    virtual std::vector<Gerente> listarGerentes() const = 0;

    /**
     * @brief Cria um novo gerente.
     * @param gerente Gerente a ser cadastrado.
     */
    virtual void criarGerente(const Gerente& gerente) = 0;

    /**
     * @brief Remove um gerente pelo ramal (identificador).
     * @param ramal Ramal do gerente.
     */
    virtual void removerGerente(const std::string& ramal) = 0;
};
