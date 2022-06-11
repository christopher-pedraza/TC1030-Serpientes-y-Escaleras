# TC1030-actividad-herencia

## PARA COMPILAR EL PROGRAMA
### WINDOWS:
1) Utiliza g++ para compilar EL programa con la siguiente instrucción desde línea de comandos:  
> g++ -o main ./*.cpp && ./main
2) Una vez compilado, se puede probar el programa desde una línea de comandos con la siguiente instrucción: 
> main.exe

### PROVISTO POR LA DOCUMENTACIÓN:
1) Utiliza g++ para compilar EL programa con la siguiente instrucción desde línea de comandos:  
> g++ snakes.cpp -o snakes.out
2) Una vez compilado, se puede probar el programa desde una línea de comandos con la siguiente instrucción: 
> ./snakes.out


## JUSTIFICACIÓN DE PROGRAMACIÓN ORIENTADA A OBJETOS
En este programa, se utilizó la herencia y el polimorfismo en varias clases: Boards heredó Ladders, Snakes y Tiles; MyGame heredó Board, Dice, Player, Automatic y Manual. Además, MyGame utilizó el polimorfismo con Automatic y Manual para poder usar el mismo método solo cambiando algunas líneas de código. El motivo de esta decisión es que los atributos y métodos de cada objeto eran necesarios para el funcionamiento final del juego, pero de incluir todo en una misma clase, aparte de no haber mucho orden, sería dificil para una persona que esté revisando el código. De esta manera, la persona puede relacionar el programa con objetos de la vida real con ciertos atributos y funciones que puede hacer dicho objeto, al igual que todo está presentado de una manera más entendible. Adicionalmente, esto permite la reutilización de código tanto dentro de este proyecto como para proyectos alternos. En el caso de este proyecto, si se necesita hacer varias copias de un mismo objeto, solo se necesita crear una clase como plantilla y de allí se hacen diversas instancias. En el caso de un proyecto externo, debido a que está separado por objetos, si un proyecto necesita incluir el mismo objeto, puede solo reutilizar ese código, mientras que si los atributos y métodos del objeto estuvieran entrelazados con la clase principal, sería más complicado este proceso.

## SOBRECARGA DE OPERADORES
Para el proyecto, se sobrecargaron 2 operadores: + y <<. El primero se cambió su función para que se pueda usar tanto para sumar la bonificación por caer en la casilla de escalera, como restar la penalización por caer en una casilla de serpiente. El segundo operador sobrecargado permite de una manera más rápida y corta imprimir todos los datos de un turno cada iteración del juego. En general, estos cambios a los operadores permiten una programación futura más eficiente y en ciertos casos, que sea más entendible el proceso que se está siguiendo.

## MANEJO DE EXCEPCIONES EN EL PROGRAMA
Para el manejo de las excepciones en el programa, se implementaron 2 excepciones customizadas, lo que permitió configurar los mensajes de salida cuando se presentaban los errores que atrapaban dichas excepciones. Una de las excepciones se utilizó para asegurarse que el usuario solo introduzca 'C' o 'E' en cada turno, y de no presionar esas teclas por un máximo de 5 ocasiones, el error terminaría el programa; antes de llegar al número máximo, solo se mostraría un mensaje de advertencia y guía. La segunda excepción se utilizó para prevenir que el usuario Introduzca parámetros iniciales incorrectos al configurar un juego customizado. En caso de hacerlo, se terminaba la ejecución del programa.

## DOCUMENTACIÓN
![serpientes y escaleras](https://user-images.githubusercontent.com/62347713/173199899-8a8f5e96-9d33-4896-876f-406cb4fe8557.png)
