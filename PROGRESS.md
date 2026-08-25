# Progreso del curso de C

Estudiante: Yilmar
Carpeta del curso: C:\Users\USUARIO\Documents\c
Última sesión: 2026-08-25 (Etapa 3 cerrada + Etapa 4 iniciada: arreglos)
Repositorio: https://github.com/Yilmar-sosa/curso-c

## Estado de etapas
- ETAPA 1 COMPLETADA ✔ (reto: desglosador de segundos)
- ETAPA 2 COMPLETADA ✔ (reto: cajero automático — lógica aprobada; pulido de detalles quedó de tarea)
- ETAPA 3 COMPLETADA ✔ (reto: cajero con funciones aprobado; pulido menor pendiente)
- ACTUAL: ETAPA 4

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
- Arreglos: declaración `int notas[5]`, acceso con corchetes `notas[i]`, recorrido con for
- Un arreglo de N tiene posiciones 0 a N-1 (NOT N) — out of bounds = comportamiento indefinido
- Inicializar max con `notas[0]` después de leer datos, NO con 0 ni antes del scanf
- No modificar el contador del for dentro del cuerpo (i++ en vez de e++ = bugs sutiles)
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
- etapa3-funciones/tablamultiplicar.c ✔ (tabla con función, prototipo, void, scanf interno)
- etapa3-funciones/cajerofuncion.c ✔ RETO ETAPA 3 (cajero reconstruido con funciones:
  pedirPin, mostrarMenu, consultarSaldo, depositar, retirar — todas con prototipo)
- etapa3-funciones/notas.c ✔ (arreglo de5 notas, promedio con float cast, cada nota con posición)
- etapa4-arreglos/maxmin.c EN PROCESO (buscar mayor y menor en arreglo; intento en notas.c
  causó acumulación de bugs; estrategia: crear archivo limpio, integrar después)

## Retos prácticos superados
- RETO ETAPA 1 "desglosador de segundos" ✔
- RETO ETAPA 2 "cajero automático" ✔ (lógica aprobada; pulido pendiente)
- RETO ETAPA 3 "cajero con funciones" ✔ (arquitectura de funciones aprobada; pulido menor pendiente)

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
- Frustración con debugging acumulado: cuando un código tiene múltiples bugs, es mejor reiniciar
  limpio que intentar corregir todo a la vez — lección de ingeniería, no de C
- Tendencia a modificar código funcional sin checkpoint: guardar versión antes de agregar complejidad

## Pendientes menores
- Crear etapa4-arreglos/maxmin.c limpio (mayor y menor en arreglo de5 notas)
- Integrar max/min de vuelta en notas.c (si student quiere complementar ejercicio original)
- Pulir cajerofuncion.c: \n en "Monto invalido" (retirar), typo CAEJERO, prototipo pedirPin vs definición
- Pulir cajero.c Etapa 2 (lista en Ejercicios resueltos)
- Espacio en "Multiplicacion%d" (calculadora.c)
- Organizar archivos sueltos en carpetas
- Hábito nuevo sugerido: compilar a output/ para no versionar binarios
- Ejercicio 5 pendiente: pedirNumero(void) y mostrarResultado(char,...) — instrucciones entregadas

## Plan próxima sesión (ETAPA 4 — continuación)
1. Crear maxmin.c limpio con lógica de mayor y menor
2. Integrar max/min de vuelta en notas.c (paso a paso: cambio → compilar → probar)
3. Arrays como parámetros de funciones (pasar arreglo + tamaño)
4. Mini-reto ETAPA 4 (procesamiento de datos con arreglos)

## Ritual de cierre de sesión
- Actualizar PROGRESS.md → git add -A → commit → push (pendiente: conectar GitHub)
