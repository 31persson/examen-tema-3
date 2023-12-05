#include <iostream>
#include <map>
#include <string>
#include <variant>

class Variant {
public:
    using IntType = int;
    using DoubleType = double;
    using StringType = std::string;
    using DataType = std::variant<IntType, DoubleType, StringType>;

    Variant() : data(0) {}
    Variant(IntType value) : data(value) {}
    Variant(DoubleType value) : data(value) {}
    Variant(const StringType& value) : data(value) {}

    template <typename T>
    T get() const {
        return std::get<T>(data);
    }

private:
    DataType data;
};

class Environment {
private:
    std::map<std::string, Variant> symbolTable;

public:
    Environment() {}

    Variant getVariable(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            std::cerr << "Variable '" << name << "' no encontrada en el entorno." << std::endl;
            return Variant();
        }
    }

    void setVariable(const std::string& name, const Variant& value) {
        symbolTable[name] = value;
    }

    void insert(const std::string& name, const Variant& value) {
        auto it = symbolTable.find(name);
        if (it == symbolTable.end()) {
            symbolTable[name] = value;
        } else {
            std::cerr << "Símbolo '" << name << "' ya existe en el entorno." << std::endl;
        }
    }

    // Método para buscar símbolos en el entorno
    Variant lookup(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            // Manejo de casos en los que el símbolo no existe
            std::cerr << "Símbolo '" << name << "' no encontrado en el entorno." << std::endl;
            // Puedes devolver un valor predeterminado o lanzar una excepción según tus necesidades.
            return Variant();
        }
    }
};

int main() {
    Environment env;

    env.insert("playerScore", Variant(100));

    Variant score = env.lookup("playerScore"); // Cambiado a lookup
    std::cout << "Player Score: " << score.get<Variant::IntType>() << std::endl;

    // Intentar buscar un símbolo que no existe
    Variant nonExistent = env.lookup("nonExistentSymbol");

    return 0;
}
