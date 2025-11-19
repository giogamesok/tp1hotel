#pragma once
#include "../entidades/Quarto.h"
#include <vector>

/**
 * @interface IQuartoService
 * @brief Interface para operações sobre quartos.
 */
class IQuartoService {
public:
    virtual ~IQuartoService() = default;

    virtual std::vector<Quarto> listarQuartos() const = 0;
    virtual void adicionarQuarto(const Quarto& quarto) = 0;
    virtual void removerQuarto(const std::string& codigo) = 0;
};
