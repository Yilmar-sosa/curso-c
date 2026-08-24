# Progreso del curso de C

Estudiante: Yilmar
Carpeta del curso: C:\Users\USUARIO\Documents\c
Última sesión: 2026-08-23 (sesión intensiva: Etapa 2 avanzada)
Repositorio: https://github.com/Yilmar-sosa/curso-c

## Estado de etapas
- ETAPA 1 COMPLETADA ✔ (reto: desglosador de segundos)
- ACTUAL: ETAPA 2 — Control del programa (~70% recorrida)

## Conceptos completados
- Estructura de programa C, main, printf/scanf, return 0
- Variables y tipos: int, float, char (+ char[20] explorado por su cuenta)
- Especificadores: %d, %.2f, %c, %s
- Operadores aritméticos (+ - * / %), división entera vs real, cast (float)
- Errores: compilador / warnings / linker; leerlos y actuar
- Orden de ejecución: pedir → calcular → imprimir
- if / else-if / else en cadenas planas; guard clauses (early return)
- && (autodidacta), anidamiento vs cadenas planas
- while: init/condición/actualización; evaluación previa; loop infinito
- for como reempaque del while (3 casillas)
- do-while: garantiza al menos una vuelta; condición = continuación
- Diseño por omisión vs salidas activas (break reservado para emergencias)
- Ámbito: lo declarado dentro de {} vive y muere ahí (contador fuera del bucle)
- Terminal: pwd, cd, ls, ./ ; git básico (init, add, commit, push)

## Ejercicios resueltos
- hola.c, promc.c, ficha.c, calculadora.c (cast) ✔
- inspector.c ✔ + inspector_v2.c (ejemplo tutor: guard clause)
- segundos.c ✔ RETO ETAPA 1
- maximo.c ✔ (4 escenarios de empate con >=)
- lanzamiento.c ✔ (while + caso N=0)
- tabla.c ✔ (for, del 1 al 10)
- adivina.c ✔ (do-while, pistas abajo/arriba, contador de intentos, sin mensajes falsos al ganar)
- Ubicación: varios sueltos en raíz — ordenar en carpetas de etapa algún día

## Retos prácticos superados
- RETO ETAPA 1 "desglosador de segundos" ✔

## Temas débiles detectados
- Predicción antes de ejecutar: mejora pero tiende a saltarla
- Detalles estéticos persistentes: \n final del ÚLTIMO mensaje de cada programa (crónico 😄), indentación ocasional
- Sobrecomplicar: mejorando mucho (aceptó diseño por omisión en adivina)

## Pendientes menores
- Espacio en "Multiplicacion%d" (calculadora.c)
- \n finales crónicos
- Organizar archivos sueltos en carpetas

## Plan próxima sesión (desde la institución)
1. Formalizar || y ! (ya usa && solo)
2. switch (días de la semana o menú simple)
3. break/continue en contexto legítimo
4. Mini-reto integrador ETAPA 2 (obligatorio para pasar a Etapa 3 — funciones)
   Idea candidata: cajero/menu con do-while + switch + validación de rango
5. Después: ETAPA 3 — Funciones

## Ritual de cierre de sesión
- Actualizar PROGRESS.md → git add -A → commit → push ✔ (hecho hoy)
