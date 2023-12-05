#include <iostream>
#include <map>
#include <variant>

// Clase Variant para representar diferentes tipos de datos
class Variant {
public:
    // Puedes extender esta clase según tus necesidades específicas

    // Definir algunos tipos básicos
    using IntType = int;
    using DoubleType = double;
    using StringType = std::string;

    // Definir el tipo de datos como una variante
    using DataType = std::variant<IntType, DoubleType, StringType>;

    // Constructor predeterminado
    Variant() : data(0) {}

    // Constructor para tipos específicos
    Variant(IntType value) : data(value) {}
    Variant(DoubleType value) : data(value) {}
    Variant(const StringType& value) : data(value) {}

    // Obtener el valor como un tipo específico
    template <typename T>
    T get() const {
        return std::get<T>(data);
    }

private:
    DataType data;
};

// Clase Environment
class Environment {
private:
    std::map<std::string, Variant> symbolTable;

public:
    // Constructor
    Environment() {}

    // Función para obtener el valor de una variable en el entorno
    Variant getVariable(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            // Manejo de error o valor predeterminado
            std::cerr << "Variable '" << name << "' no encontrada en el entorno." << std::endl;
            return Variant(); // Puedes devolver un valor predeterminado o lanzar una excepción según tus necesidades.
        }
    }

    // Función para asignar el valor de una variable en el entorno
    void setVariable(const std::string& name, const Variant& value) {
        symbolTable[name] = value;
    }
};

// Ejemplo de uso
int main() {
    // Crear un entorno
    Environment env;

    // Asignar una variable en el entorno
    env.setVariable("playerScore", Variant(100));

    // Obtener el valor de una variable del entorno
    Variant score = env.getVariable("playerScore");
    std::cout << "Player Score: " << score.get<Variant::IntType>() << std::endl;

    return 0;
}
