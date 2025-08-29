# RESPUESTAS

## Pregunta 1
El archivo **README.md** es clave porque permite entender de inmediato de qué trata el proyecto, cómo se usa y qué requisitos tiene. Para alguien que no estuvo desde el inicio, entrega una guía básica: explica qué hace el código, cómo compilarlo, en qué sistema operativo funciona y cuáles son las instrucciones mínimas para poder ejecutarlo. Sin este archivo, una persona nueva tendría que revisar todo el código para adivinar su funcionamiento.  

---

## Pregunta 2
Un **Makefile** simplifica mucho la compilación y el uso del programa. En vez de tener que escribir siempre los mismos comandos largos de compilación o ejecución, se puede usar directamente `make`, `make run` o `make clean`. Para otros usuarios es una ayuda porque cualquiera puede compilar el código sin conocer los detalles del compilador ni las banderas usadas.  
Además, no solo se limita a C++; también puede aplicarse en otros lenguajes como Fortran, Rust, Go o Java, siempre que se definan las reglas adecuadas. Eso sí, hay que tener cuidado con las rutas y la portabilidad para que funcione en distintos sistemas operativos.  

---

## Pregunta 3
El uso de **git** y de una plataforma como **GitHub** da orden y seguridad en el trabajo en equipo. Git permite tener un historial completo de cambios, trabajar en ramas separadas y volver atrás si algo falla. GitHub agrega herramientas de colaboración: revisiones de código mediante *pull requests*, control de permisos, seguimiento de tareas con Issues y la posibilidad de automatizar pruebas.  
En un grupo de tres o más personas, esto se traduce en que todos pueden trabajar en paralelo sin pisarse el trabajo, los errores se detectan antes gracias a las revisiones, y queda un registro claro de quién hizo qué y cuándo.  

---

## Pregunta 4
Documentar las funciones dentro del código es muy útil porque facilita entender qué hace cada una sin tener que leer toda la implementación. Esto ayuda a que otro programador pueda mantener o modificar el código sin problemas, y también evita confusiones en el futuro.  
No documentar significa depender solo del autor original: otros tendrán que invertir más tiempo en comprenderlo, lo que aumenta la probabilidad de cometer errores al modificarlo.  

---

## Pregunta 5
Las cuatro herramientas mencionadas se complementan muy bien:  
- El **README.md** entrega la explicación inicial.  
- El **Makefile** hace que compilar y ejecutar sea rápido y estandarizado.  
- **Git** permite llevar un control seguro de la evolución del código.  
- **GitHub** facilita la colaboración entre varias personas y mantiene todo centralizado.  

En conjunto logran que el proyecto sea más claro, mantenible y fácil de usar para personas externas. Gracias a ellas se garantiza que el código se pueda reproducir, compartir y mejorar de manera ordenada y eficiente.  

---
