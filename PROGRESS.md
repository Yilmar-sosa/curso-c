# Progreso del curso de C

Estudiante: Yilmar
Carpeta del curso: C:\Users\USUARIO\Documents\c
Última sesión: 2026-08-24 (cierre de Etapa 2 + inicio Etapa 3)
Repositorio: https://github.com/Yilmar-sosa/curso-c

## Estado de etapas
- ETAPA 1 COMPLETADA ✔ (reto: desglosador de segundos)
- ETAPA 2 COMPLETADA ✔ (reto: cajero automático — lógica aprobada; pulido de detalles quedó de tarea)
- ACTUAL: ETAPA 3 — Funciones

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
- || y ! formalizados; !(...) sobre condiciones complejas
- switch/case/default: valores exactos, fall-through sin break, break como freno legítimo
- Variables sin inicializar = basura (total en cafeteria.c)
- continue como guard clause dentro de bucles (introducido, pendiente de aplicar)
- Funciones propias: anatomía, return, composición suma(10, resta(7,2))
- Prototipos: menú arriba / main (salón) / definiciones (cocina abajo); error "implicit declaration"
- El prototipo deja al compilador verificar llamadas ("too few arguments")
- void: corta el cable del return (antes del nombre) o el de los parámetros (entre paréntesis);
  NUNCA afecta printf — tres canales: parámetros / return / pantalla
- Parámetros = fotocopias (paso por valor): duplicar no cambia el original
- stdio.h = menú de prototipos ajenos; cuerpos precompilados en la librería (conexión hecha por él)
- Terminal: pwd, cd, ls, ./, mv ; git básico (init, add, commit, push)

## Ejercicios resueltos
- hola.c, promc.c, ficha.c, calculadora.c (cast) ✔
- inspector.c ✔ + inspector_v2.c (ejemplo tutor: guard clause)
- segundos.c ✔ RETO ETAPA 1
- maximo.c ✔ (4 escenarios de empate con >=)
- lanzamiento.c ✔ (while + caso N=0)
- tabla.c ✔ (for, del 1 al 10)
- adivina.c ✔ (do-while, pistas abajo/arriba, contador de intentos, sin mensajes falsos al ganar)
- pin.c ✔ (guardián: || para rango, ! en el while, validación que no cuenta intentos)
- cafeteria.c ✔ (switch + total preparado dentro de los case, guard clause con return)
- cajero.c ✔ RETO ETAPA 2 (PIN + menú do-while + switch + validación de montos con || y !)
  - Tarea de pulido: \n faltantes (x4), typos accceder/CAEJERO, mensaje del default,
    refactor continue guard clause en retiro, renombrar saldoInicial → saldo
- Ubicación: varios sueltos en raíz — ordenar en carpetas de etapa algún día
- etapa3-funciones/funciones.c ✔ (suma/resta/multiplicacion + prototipos, reestructurado profesional)
- etapa3-funciones/duplicar.c ✔ (parámetros como fotocopias: dentro 10, fuera 5)
- EJERCICIO 5 EN PAUSA (modernizar funciones.c con pedirNumero y mostrarResultado):
  instrucciones de 4 pasos ya entregadas; el archivo aún no se ha modificado

## Retos prácticos superados
- RETO ETAPA 1 "desglosador de segundos" ✔
- RETO ETAPA 2 "cajero automático" ✔ (lógica aprobada; pulido pendiente)

## Temas débiles detectados
- Predicción antes de ejecutar: mejora pero tiende a saltarla
- \n finales: mejoró en programas cortos, recae en programas largos (cajero x4)
- Typos en mensajes al usuario (intetos, accceder, CAEJERO): releer los printf antes de compilar
- Mensajes que culpan al sistema cuando el usuario se equivoca ("Algo fallo")
- Decir "listo" sin haber aplicado el ejercicio (ocurrió x2 esta sesión) — verificar siempre el archivo
- Se pierde en instrucciones largas: dar UNA tarea concreta por mensaje, pasos numerados cortos
- Creencia resuelta hoy: "solo imprime lo que está en main" / "printf vive en main" → venía de
  que sus funciones solo hacían return; duplicar.c refutó la teoría con datos
- Resumen invertido de void corregido con drill de "tres cables" — repasar al inicio de próxima sesión

## Pendientes menores
- TERMINAR EJERCICIO 5 (pasos 1-4 ya redactados; meta visible: 10 + 4 = 14 ...)
- Pulir cajero.c (lista en Ejercicios resueltos)
- Espacio en "Multiplicacion%d" (calculadora.c)
- Organizar archivos sueltos en carpetas
- Hábito nuevo sugerido: compilar a output/ para no versionar binarios

## Plan próxima sesión (Etapa 3 — Funciones, continuación)
1. Repaso exprés: tres cables (parámetros/return/pantalla) + menú-salón-cocina
2. Terminar Ejercicio 5: pedirNumero(void) y mostrarResultado(char,...) — receta completa ya dada
3. Narración pedida: "el viaje del número 4" del teclado a la pantalla
4. RETO ETAPA 3: reconstruir el cajero con arquitectura de funciones
   (mínimo: pedirPin, mostrarMenu, depositar, retirar, consultarSaldo — todas con prototipo)
5. Después: char en profundidad o arreglos, según ritmo

## Ritual de cierre de sesión
- Actualizar PROGRESS.md → git add -A → commit → push ✔ (hecho 2026-08-24)
