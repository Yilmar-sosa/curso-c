# Progreso del curso de C

Estudiante: Yilmar
Carpeta del curso: C:\Users\USUARIO\Documents\c
Última sesión: 2026-08-23

## Estado de etapas
- ETAPA 1 COMPLETADA ✔ (reto: desglosador de segundos)
- ACTUAL: ETAPA 2 — Control del programa

## Conceptos completados
- Estructura de programa C, main, printf/scanf
- Variables y tipos: int, float, char (+ arrays char[20] explorados por su cuenta)
- Especificadores: %d, %.2f, %c, %s
- Operadores aritméticos (+ - * / %), división entera vs real
- Cast de tipos: (float)num1 / num2
- Errores de compilador vs warnings vs errores del linker
- Orden de ejecución: pedir → calcular → imprimir
- if / else / else-if en cadena; guard clauses (early return)
- Operador lógico && (usado por su cuenta antes de verlo en clase)
- while: inicialización / condición / actualización; evaluación previa de la condición
- Ámbito dentro/fuera de llaves (qué se repite y qué no)
- Terminal: pwd, cd, ls, ./ y directorio actual

## Ejercicios resueltos
- hola.c ✔
- promc.c ✔ (ficha interactiva básica)
- ficha.c ✔ (3 scanf: %s %d %f)
- calculadora.c ✔ (5 operaciones + cast para división real)
- inspector.c ✔ (par/impar + signo, con manejo del cero)
- maximo.c ✔ (mayor de 3 con los 4 escenarios de empate)
- lanzamiento.c ✔ (cuenta regresiva while + caso N=0 resuelto con criterio propio)
- Ubicación: varios quedaron sueltos en raíz del curso en vez de sus carpetas de etapa — pendiente de ordenar

## Retos prácticos superados
- RETO ETAPA 1 "desglosador de segundos" ✔ (segundos.c) — tras refactor guiado: eliminó bucles innecesarios y siguió su propio algoritmo verbal

## Temas débiles detectados
- Salta la fase de predicción/testing propio (mejorando: predijo bien el caso N=0)
- Detalles estéticos persistentes: \n finales, consistencia de textos, indentación
- Tendencia a sobrecomplicar/anidar — mejorando con cadenas planas
- Razonamiento modular fino (propiedades del %) necesita trazas concretas

## Pendientes menores del estudiante
- Espacio en "Multiplicacion%d" (calculadora.c)
- Organizar archivos sueltos en carpetas de etapa

## Siguiente paso
- for como reempaque de while (3 piezas en una línea) → ejercicio tabla de multiplicar
- Predicciones obligatorias antes de codificar (casillas del for, printf con varios %d)
- Después: do-while + juego "adivina el número"; formalizar || y ! ; switch; break/continue
