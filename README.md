# examen-tema-3
https://github.com/31persson/examen-tema-3.git
Parte 1: Preguntas de elección múltiple (20%)
 1. ¿Cuál es el propósito principal de la clase Variant en el lenguaje Tiny Lisp?: b) Representar cualquier tipo de dato Lisp
 2. ¿Qué representación se obtiene al utilizar el método to_string() en un objeto Variant?: a) Una cadena de texto que representa una instancia de Variant
 3. ¿Qué función cumple el método to_json_string() en la clase Variant? :b) Convierte un objeto Variant a una cadena JSON
 4. ¿Qué función cumple el método from_json_string() en la clase Variant?: c) Parsea un objeto JSON a un objeto Variant 
Parte 2: Pregunta de desarrollo de código (80%):Sistema de Scripting para Motor de Videojuegos Indie
  1. Estructura Básica: Comienza definiendo la estructura básica de la clase Environment, asegurando que integra un std::map para la tabla de símbolos: He utilizado la plantilla std::variant para representar diferentes tipos de datos en la clase Variant. Puedes extender o modificar la clase Variant según tus necesidades específicas. Además, la clase Environment utiliza esta clase Variant para gestionar la tabla de símbolos.
  2. Insertar Símbolos: Implementa y prueba el método insert, asegurándote de que se puedan añadir nuevos símbolos al entorno sin conflictos: He agregado el método insert a la clase Environment. Este método verifica si el símbolo ya existe en la tabla de símbolos antes de insertarlo. Si el símbolo ya existe, imprime un mensaje de error; de lo contrario, inserta el nuevo símbolo en el entorno.
  3. Búsqueda de Símbolos: Implementa y prueba el método lookup, considerando casos en los que el símbolo pueda no existir en el entorno: He agregado el método lookup a la clase Environment. Este método busca un símbolo en el entorno y maneja el caso en el que el símbolo no existe, imprimiendo un mensaje de error y devolviendo un valor predeterminado. 
  4. Gestión de Errores: Introduce mecanismos de manejo de excepciones para gestionar casos en los que se intenta acceder a un símbolo no existente o se intenta insertar un símbolo ya existente con un valor diferente: He modificado las funciones getVariable, insert, y lookup para lanzar excepciones en lugar de imprimir mensajes en la salida estándar. El bloque try-catch en la función main maneja estas excepciones y muestra un mensaje de error en caso de que ocurran.
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
 6. Expandiendo Funcionalidades: Diseña y añade al menos dos funciones adicionales que consideres relevantes para la clase Environment, como eliminar un símbolo, verificar si existe, entre otros: He añadido dos funciones adicionales: remove: Permite eliminar un símbolo del entorno. Si el símbolo no existe, se lanza una excepción. exists: Verifica si un símbolo existe en el entorno y devuelve un valor booleano. Estas funciones añaden más flexibilidad y control sobre la gestión de símbolos en el entorno.
 7. Casos de Uso: Proporciona ejemplos de cómo un diseñador o desarrollador de videojuegos podría usar la clase Environment en conjunto con Variant para personalizar el comportamiento de un juego:
   Ajuste de Parámetros del Juego: Almacena y ajusta valores como velocidad y dificultad durante el desarrollo del juego:
   env.setVariable("characterSpeed", Variant(10.0));
env.setVariable("gameDifficulty", Variant(2));

double speed = env.getVariable("characterSpeed").get<Variant::DoubleType>();
int difficulty = env.getVariable("gameDifficulty").get<Variant::IntType>();
   Configuración de Niveles: Define configuraciones específicas para cada nivel del juego:
   env.setVariable("level1.obstacleDensity", Variant(0.5));
env.setVariable("level1.enemyCount", Variant(10));

double level1ObstacleDensity = env.getVariable("level1.obstacleDensity").get<Variant::DoubleType>();
int level2EnemyCount = env.getVariable("level2.enemyCount").get<Variant::IntType>();
   Desbloqueo de Contenido: Controla el acceso a contenido basado en los logros del jugador:
   if (jugadorCompletaNivel1) {
    env.setVariable("unlockedLevels.level2", Variant(true));
}

bool nivel2Desbloqueado = env.getVariable("unlockedLevels.level2").get<Variant::IntType>();
 8. Reflexión y Mejoras: Basándote en tu implementación, discute posibles mejoras o extensiones que podrían beneficiar al sistema de scripting en el futuro. Considera aspectos como la optimización, expansión de la tabla de símbolos, o la introducción de funciones más avanzadas.
   1. Optimización de Acceso a Variables: Considerar estructuras de datos más eficientes, como unordered_map, para mejorar la velocidad de acceso.
   2. Tipos de Datos Adicionales: Extender Variant para admitir tipos más avanzados, como estructuras complejas o funciones.
   3. Funciones Incorporadas: Permitir la definición de funciones directamente en el entorno de scripting para lógica más compleja.
   4. Manejo de Eventos: Implementar un sistema para que los scripts puedan suscribirse y responder a eventos del juego.
   5. Serialización y Deserialización: Agregar métodos para guardar y cargar el estado del entorno, facilitando la persistencia de datos.
   6. alidación de Tipos Dinámica: Mejorar la seguridad mediante la introducción de validación de tipos dinámica al acceder a variables.
   7. Integración con Herramientas de Desarrollo: Facilitar la integración con herramientas visuales o de depuración para mejorar la productividad.
   8. Optimización de Excepciones: Evaluar y optimizar el uso de excepciones para mejorar el rendimiento en situaciones críticas.
