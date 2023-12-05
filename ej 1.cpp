#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <stdexcept>

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
            throw std::runtime_error("Variable '" + name + "' no encontrada en el entorno.");
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
            throw std::runtime_error("Símbolo '" + name + "' ya existe en el entorno.");
        }
    }

    Variant lookup(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Símbolo '" + name + "' no encontrado en el entorno.");
        }
    }
};

int main() {
    try {
        Environment env;

        env.insert("playerScore", Variant(100));

        Variant score = env.lookup("playerScore");
        std::cout << "Player Score: " << score.get<Variant::IntType>() << std::endl;

        // Intentar buscar un símbolo que no existe
        Variant nonExistent = env.lookup("nonExistentSymbol");

        // Intentar insertar un símbolo que ya existe
        env.insert("playerScore", Variant(200));
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
