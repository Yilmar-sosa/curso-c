# Progreso del curso de C

Estudiante: Yilmar
Carpeta del curso: C:\Users\USUARIO\Documents\c
Última sesión: 2026-09-01 (mañana) — inventario_a_corregir.c completado; Taller Ruta 1 tarea1 en proceso (encabezado binario leído, falta bucle de estudiantes)
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
- etapa4-arreglos/notas.c ✔ (arreglo + promedio + mayor + menor, integrado paso a paso)
- etapa4-arreglos/maxmin.c ✔ (mayor y menor en arreglo)
- etapa5-strings/nombre.c ✔ (fgets con espacios, toupper, strcspn)
- etapa6-punteros/intercambiar.c ✔ (punteros modifican el original, no copias)
- etapa7-structs/estudiante.c ✔ (struct Estudiante: nombre, edad, promedio)
- etapa7-structs/reporteprueba.c ✔ (array de structs + puntero aritmético (est+i)->campo,
  buffer cleanup, fgets con espacios, mostrarEstudiantes)
- etapa8-archivos/guardar.c ✔ (fopen w/r, fwrite/fprintf, fgets, leer lo guardado)
- etapa9-memoria/dinamico.c EN PROCESO (malloc + free; falta calcular el máximo)

## Retos prácticos superados
- RETO ETAPA 1 "desglosador de segundos" ✔
- RETO ETAPA 2 "cajero automático" ✔ (lógica aprobada; pulido pendiente)
- RETO ETAPA 3 "cajero con funciones" ✔ (arquitectura de funciones aprobada; pulido menor pendiente)

## Progreso por etapas (2026-08-27)
- ETAPA 1 Variables ✔ | ETAPA 2 Condicionales ✔ | ETAPA 3 Funciones ✔
- ETAPA 4 Arrays ✔ (incluye bubble sort) | ETAPA 5 Strings ✔
- ETAPA 6 Punteros ✔ (intercambiar) | ETAPA 7 Structs ✔ (array + punteros)
- ETAPA 8 Archivos ✔ (guardar/leer) | ETAPA 9 Memoria dinámica EN CURSO (malloc, falta máximo)
- Quedan: terminar Etapa 9, Etapa 10 proyecto integrador (deadline 31-ago)
- Estructura de carpetas organizada en etapa1..etapa9, ejercicios de Etapa1-2 movidos a su carpeta

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

## SESIÓN 2026-08-29 — TALLER INSTITUCIONAL "Etapa 1 - Homework" COMPLETADO
- PUNTO 1 (WORK PRIMERA.C) — swap/reverseArray/printArray + malloc/realloc/free: validadas por falsos positivos (memoria+compilador) y output EXACTO del enunciado
- PUNTO 2 (punto2_lista.c) — lista sobre arreglo, 7 funciones completas y verificadas, salida EXACTA:
  `10 -> 20 -> 30 / 5 -> 10 -> 20 -> 30 / 5 -> 10 -> 20 -> 25 -> 30 / 5 -> 20 -> 25 -> 30 / Length: 4`
- Guardias implementadas: lista llena (inserts), lista vacía + índice inválido (delete), cada una con su mensaje propio
- Conceptos conquistados hoy: regla del paso de parámetros (puntero si modifica / valor si lee / arreglo SIEMPRE por puntero); el arreglo decae a puntero; `listSize` como "fuente de verdad"; deslizamiento derecha→izquierda en inserts (y espejo en delete); off-by-one del delete (`i < *listSize - 1`); patrón separador "no primero" (`i > 0`); distinción mensaje preciso vs engañoso (causa real, no síntoma)
- Bugs cazados hoy: `*listSize++` → `(*listSize)++`; `return 0` en función `void`; `;` fantasma tras el `for`; condición imposible `i < *listSize` en print (else nunca corría); off-by-one en delete; frontera `>` vs `>=` en guardia de índice
- DEBILIDAD DECISIVA detectada: dice "listo" HABITUALMENTE sin haber aplicado el cambio al disco (×3 en esta sesión). Regla acordada: editar → guardar → MIRAR la línea con los ojos → recién compilar; confirmar línea modificada antes de afirmar
- Pendiente: EXAMEN DE PRUEBA de la institución (Student lo rinde hoy); al regreso, continuar Etapa 10 (Agenda integrador) — deadline 31-ago
- Ritual de cierre ejecutado: archivos organizados (renombre a punto2_lista.c, borrado basura), PROGRESS actualizado, commit+push

## SESIÓN 2026-08-31 — EXAMENES DE PRUEBA (etapa1 homework + repaso)
- EXAMEN PRUEBA 1 (examen-practica/examenpueba1.c): "Longest Word" estilo coderbyte.
  Busca la palabra MÁS LARGA de una frase ignorando puntuación. 2 casos de ejemplo CORRECTOS.
  - Acierto clave: `if(strlen(actual) > strlen(larga))` con `>` guarda la PRIMERA en empate
    (love vs dogs -> love, correcto).
  - Mejora pendiente: `isalnum()` acepta dígitos; si el enunciado es "solo letras" usar
    `isalpha()` (los `&`/`!` ya se ignoran con ambos).
  - Bug anterior corregido: main llamaba LongestWord DOS veces (prueba manual + la del
    sistema) y eso concatenaba salidas tipo "encantanlove". Se quita la llamada manual.
- EXAMEN PRUEBA 2 (examen-practica/inventario_a_corregir.c): Sistema de Inventario (Producto)
  con malloc/realloc y paso por referencia. Guardado TAL CUAL para corregir juntos.
- REVISIÓN académica del examen 2 (8 errores encontrados, quedan pendientes de corregir):
  1. Regla de acceso por firma (CRÍTICA, se vio hoy): una estrella `Producto *` -> `inventario[i]`;
     dos estrellas `Producto **` -> `(*inventario)[i]`. Se usó `(**)[i]` en funciones con una estrella.
  2. `*` suelto en línea propia (sintaxis inválida).
  3. Comparar `*capacidad == NULL` incorrecto (capacidad es int; NULL es para punteros;
     debe ser `*inventario == NULL`).
  4. Falta `;` en `precio = precio`; varias funciones sin llaves de cierre balanceadas.
  5. Bug lógico buscarProductoPorId: `else return -1` corta en la primer posición sin revisar
     el resto -> debe revisar todo el arreglo y retornar -1 DESPUÉS del for.
  6. calcularValorTotal: `.valor` no existe (es `.cantidad`); `[i+1]` mal -> debe ser
     `[i].cantidad * [i].precio`.
  7. imprimirInventario: usa `cantidad` (no existe) en vez de `cantidadProductos`;
     `inventario.cantidad` -> `inventario[i].cantidad`.
  8. liberarInventario: `free(**inventario)` -> `free(*inventario)`; typo "invertario";
     falta `;`.
- CONCEPTOS REFORZADOS hoy: puntero no es arreglo hasta que se le asigna memoria con malloc;
  `Producto *temp` guarda lo que devuelve realloc (apunta al primer Producto del bloque, los
  demás son contiguos); el `temp` intermedio protege el puntero original si realloc falla;
  `(*inventario)[i]` entre paréntesis porque `[]` tiene más precedencia que `*`.
- Pendiente: corregir inventario_a_corregir.c función por función; continuar Etapa 10 (Agenda
  integrador módulo2 archivos) — deadline 31-ago.

## SESIÓN 2026-09-01 (mañana) — INVENTARIO CORREGIDO + CHULETA AMPLIADA
- inventario_a_corregir.c COMPLETADO: compila con -Wall (exit 0) y salida 100% correcta.
  Verificado: inventario inicial (3 productos), realloc al agregar 4º, actualizar Mouse 15->20,
  buscar Monitor por id 3, valor total 1580.00 = 10*25.5+20*12.75+5*150+8*40.
- Errores corregidos en sesión: (1) `*` suelto, (2) comparar `*capacidad==NULL` -> `*inventario==NULL`,
  (3) `(*(inventario))[i]` mal con una estrella -> `inventario[i]`, (4) PRECEDENCIA de `[]` sobre `*`
  -> por eso `(*inventario)[i]` con paréntesis, (5) `wash.tiempo`? no: `[i+1]` -> `[i]`, falta `;`,
  (6) llaves desbalanceadas (imprimirInventario dejó 1 `{` sin cerrar), (7) dead code tras `return;`
  (`*inventario=tem; *capacidad=nuevacap;` después del return NUNCA corrían), (8) agregar producto
  DENTRO del if(está lleno) -> solo agregaba cuando cabía (cantidad nunca incrementaba),
  (9) mensaje fantasma "no encontrado": patrón `e != indice` defectuoso -> reemplazado por BANDERA
  `encontrado = 0/1` + `if(!encontrado)` tras el for, (10) `return 0;` como no-encontrado -> -1.
- CONCEPTOS NUEVOS HOY (clave examen):
  - REGLA `*` vs `**`: 1 estrella -> `inv[i]`; 2 estrellas -> `(*inv)[i]`. 2 estrellas SOLO cuando
    la función cambia a dónde apunta el puntero (realloc). `[]` tiene más precedencia que `*`.
  - El if(está lleno) es SOLO para crecer (realloc); el agregar + n++ van SIEMPRE fuera del if.
  - Bandera booleana: `encontrado=0` (asumo NO existe), `encontrado=1` al encontrarlo, `if(!encontrado)`
    = "nunca se marcó" -> mensaje. La bandera es sí/no, NO guarda posición (eso es el contador `i`).
  - "No encontrado" se revisa DESPUÉS de recorrer todo, jamás dentro con `else return`.
  - return -1 como centinela de no-encontrado (0 sería índice válido).
  - isalpha vs isalnum: "solo letras" -> isalpha; alfanumérico -> isalnum.
- CHULETA notas-examen/index.html AMPLIADA con: regla `*` vs `**` (tabla), realloc correcto
  paso a paso, dead-code-tras-return, patrón bandera, devolver -1, patrón palabra más larga,
  fantasmas 12-15, y recordatorios finales. HTML validado (ningún div abierto).
- Ritual pendiente: commit + push de la sesión (hicieron push en las 07:14 y 08:43 por su cuenta,
  verificar al cierre).

## SESIÓN 2026-09-02 — TAREA 1 TALLER RUTA 1 (guía + examen final cerca)
- TAREA 1 completada como SOLUCIÓN-GUÍA en TALLER-ETAPA1/tarea1_SOLUCION_guia.c (archivo aparte,
  sin tocar primernombre_apellido_tarea1.c). Compila con -Wall -Wextra sin avisos y verificado
  (filtro 18-18 imprime solo los de 18 con género correcto).
- ESTRUCTURA DEL BINARIO descifrada por ingeniería inversa (xxd + mini-programa desechable):
  encabezado 14 bytes (magic uint16 + studentCount/courseCount/enrollCount uint32) y luego 1000
  estudiantes de 32 bytes c/u: id(4) → flags(1) → nombre[23] → edad(4). El flags guarda el género
  en el bit 7: 0x80/0xC0 = F, 0x00/0x40 = M (verificadas 611 F / 389 M). El archivo sigue con
  cursos y matrículas (no necesarios en tarea 1).
- CONCEPTOS NUEVOS hoy: argc/argv (todo en terminal es texto, argc cuenta incluyendo argv[0],
  atoi convierte y para en la 1ra letra: "12años"→12, "a17"→0); el for NO mueve el archivo,
  cada fread avanza solo la posición interna; el encabezado se lee para "saltarlo"; endianness
  little-endian (aa ae → leído 0xAEAA, magic real 0xAAAE; 12 00 00 00 = 18); números gigantes
  al imprimir = bytes corridos/campos en mal orden; máscara de bits flags & 0x80 (== 0x80 es
  trampa con 0xC0); ternario (cond)?A:B; descubrir formato = buscar texto legible con xxd +
  correlacionar campos.
- CHULETA AMPLIADA: nueva sección "16. Línea de comandos y archivos binarios" (argc/argv, fread,
  endianness, máscaras) + 5 recordatorios nuevos en la 17. HTML validado (39 div balanceados).
- ACUERDO con estudiante: mañana intentará la TAREA 1 SOLO con la lógica aprendida;
  la guía queda como referencia. Lección pendiente para tareas 2 y 3: los otros bloques del binario
  (cursos/matrículas) — estructura distinta, mismo método. Faltan los enunciados de tareas 2 y 3.
- Pendiente: opcional commit+push de hoy (guía + PROGRESS + chuleta).
