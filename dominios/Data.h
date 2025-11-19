// Data.h
#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Data {
private:
    int dia;
    std::string mes;
    int ano;
    std::vector<std::string> meses = {"JAN","FEV","MAR","ABR","MAI","JUN",
                                      "JUL","AGO","SET","OUT","NOV","DEZ"};
    std::vector<int> dias_mes = {31,29,31,30,31,30,31,31,30,31,30,31};
    bool bissexto(int a) {
        return (a % 400 == 0) || (a % 4 == 0 && a % 100 != 0);
    }
    void validar(int d, std::string m, int a) {
        auto it = std::find(meses.begin(), meses.end(), m);
        if (it == meses.end())
            throw std::invalid_argument("Mês inválido.");
        int idx = it - meses.begin();
        if (d < 1 || d > dias_mes[idx])
            throw std::invalid_argument("Dia inválido para o mês.");
        if (m == "FEV" && d == 29 && !bissexto(a))
            throw std::invalid_argument("Ano não bissexto para dia 29 de fevereiro.");
        if (a < 2000 || a > 2999)
            throw std::invalid_argument("Ano deve estar entre 2000 e 2999.");
    }
public:
    Data(int d, std::string m, int a) { validar(d,m,a); dia=d; mes=m; ano=a; }
    void setData(int d, std::string m, int a) { validar(d,m,a); dia=d; mes=m; ano=a; }
    std::string getData() const { return std::to_string(dia)+"-"+mes+"-"+std::to_string(ano); }
};
