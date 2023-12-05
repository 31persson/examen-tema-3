#include <iostream>
#include <stdexcept>
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

    void remove(const std::string& name) {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            symbolTable.erase(it);
        } else {
            throw std::runtime_error("No se puede eliminar. Símbolo '" + name + "' no encontrado en el entorno.");
        }
    }

    bool exists(const std::string& name) const {
        return symbolTable.find(name) != symbolTable.end();
    }
};

int main() {
    try {
        Environment env;

        // Almacenar y recuperar variables
        env.setVariable("playerScore", Variant(100));
        Variant score = env.getVariable("playerScore");
        std::cout << "Player Score: " << score.get<Variant::IntType>() << std::endl;

        // Insertar variable con manejo de excepciones
        env.insert("newVariable", Variant(42));

        // Verificar si un símbolo existe
        if (env.exists("playerScore")) {
            std::cout << "El símbolo 'playerScore' existe en el entorno." << std::endl;
        } else {
            std::cout << "El símbolo 'playerScore' no existe en el entorno." << std::endl;
        }

        // Eliminar un símbolo
        env.remove("playerScore");

        // Intentar obtener un símbolo eliminado
        Variant deletedSymbol = env.lookup("playerScore");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
