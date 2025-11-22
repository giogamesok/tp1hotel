#!/bin/bash
echo "Gerando documentação Doxygen..."
doxygen Doxyfile
echo "Documentação gerada em: docs/html/"
echo "Abra docs/html/index.html no navegador"