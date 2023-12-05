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

    // Método para insertar nuevos símbolos sin conflictos
    void insert(const std::string& name, const Variant& value) {
        auto it = symbolTable.find(name);
        if (it == symbolTable.end()) {
            // El símbolo no existe, podemos insertarlo
            symbolTable[name] = value;
        } else {
            std::cerr << "Simbolo '" << name << "' ya existe en el entorno." << std::endl;
            // Puedes manejar el conflicto de alguna manera, como lanzar una excepción
            // o actualizar el valor del símbolo existente, dependiendo de tus necesidades.
        }
    }
};

int main() {
    Environment env;

    env.insert("playerScore", Variant(100)); // Insertar un nuevo símbolo

    Variant score = env.getVariable("playerScore");
    std::cout << "Player Score: " << score.get<Variant::IntType>() << std::endl;

    // Intentar insertar el mismo símbolo nuevamente
    env.insert("playerScore", Variant(200));

    return 0;
}
