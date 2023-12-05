# examen-tema-3
https://github.com/31persson/examen-tema-3.git
Parte 1: Preguntas de elección múltiple (20%)
 1. ¿Cuál es el propósito principal de la clase Variant en el lenguaje Tiny Lisp?: b) Representar cualquier tipo de dato Lisp
 2. ¿Qué representación se obtiene al utilizar el método to_string() en un objeto Variant?: a) Una cadena de texto que representa una instancia de Variant
 3. ¿Qué función cumple el método to_json_string() en la clase Variant? :b) Convierte un objeto Variant a una cadena JSON
 4. ¿Qué función cumple el método from_json_string() en la clase Variant?: c) Parsea un objeto JSON a un objeto Variant 
Parte 2: Pregunta de desarrollo de código (80%):Sistema de Scripting para Motor de Videojuegos Indie
 1. Estructura Básica: Comienza definiendo la estructura básica de la clase Environment, asegurando que integra un std::map para la tabla de símbolos.
 2. Insertar Símbolos: Implementa y prueba el método insert, asegurándote de que se puedan añadir nuevos símbolos al entorno sin conflictos.
 3. Búsqueda de Símbolos: Implementa y prueba el método lookup, considerando casos en los que el símbolo pueda no existir en el entorno.
 4. Gestión de Errores: Introduce mecanismos de manejo de excepciones para gestionar casos en los que se intenta acceder a un símbolo no existente o se intenta insertar un símbolo ya existente con un valor diferente.
 5. Integración con Variant: Explica cómo la clase Environment trabaja en conjunto con Variant y demuestra su interacción mediante ejemplos prácticos:
    Almacenamiento de Variables:
    La función setVariable de Environment utiliza Variant para almacenar un valor asociado con un nombre de variable en la tabla de símbolos.
    env.setVariable("playerScore", Variant(100));
    Recuperación de Variables:
    La función getVariable de Environment utiliza Variant para devolver el valor asociado con un nombre de variable desde la tabla de símbolos.
    Variant score = env.getVariable("playerScore");
    Inserción de Variables con Control de Excepciones:
    La función insert de Environment utiliza Variant para insertar un nuevo símbolo en la tabla de símbolos. Se lanza una excepción si el símbolo ya existe.
    try {
    env.insert("newVariable", Variant(42));
} catch (const std::exception& e) {
    std::cerr << "Error al insertar variable: " << e.what() << std::endl;
}
    Búsqueda de Variables con Control de Excepciones:
    La función lookup de Environment utiliza Variant para buscar un símbolo en la tabla de símbolos. Se lanza una excepción si el símbolo no existe.
    try {
    Variant variable = env.lookup("nonExistentVariable");
} catch (const std::exception& e) {
    std::cerr << "Error al buscar variable: " << e.what() << std::endl;
}

