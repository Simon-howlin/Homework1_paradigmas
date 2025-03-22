# Home work 1

## ¿De que tratan los ejercicios?:

- ejercicio 1: manejo de matrices, en especial no hago nada raro mas que asignar memoria a mano en vez de usar vector de vectores.

- ejercicio 2: defino valores de severidades posibles, creo casos en los que se le llaman a cada una de las severidades, hace un try and catch y escribe un archivo .txt con lo que va pasando a demas de mostrarlo en terminal.

- ejercicio 3: manejo de listas, uso de la mayoria de las aplicaciones que tiene una lista. 

- ejercicio 4: se le dan 2 cadenas a comparar si son iguales, devuelve true si lo son y de lo contrario false. Despues se hace una comparacion entre el tempo de respuesta que hay si lo corremos normal o evaluandolo en tiempo de compilacion.
    
    conclucion ej4: Principalmente lo habia hecho con string pero lo cambie a char porque resulto no funcionar para hacerlo en tiempo de compilacion, y tambien descubri que el char es bastante mas rapido que el string. En cuanto a ejecutarlo normal y en tiempo de compilacion, se nota muchisimo la diferencia entre uno y otro, siendo el tiempo que tarda en ejecutarse al evaluarlo tiempo de compilacion casi 5 veces mas rapido que ejecutarlo normalmente.

## Cómo compilar los ejercicos:

- Del ejercicio 1 al 3 se puede compilar de manera normal por terminal -> g++ ejercicioN/ejercicioN.cpp -o bin/ejN (siendo n el numero de ej).
- El ejercicio 4 se tiene que correr con otro comando por el tema de verciones de c++ que no es compatible con constexpr -> g++ -std=c++17 ejercicioN/ejercicioN.cpp -o bin/ejN (siendo n el numero de ej).

## Como ejecutar los ejercicios:
- ./bin/ejN (siendo n el numero de ej).