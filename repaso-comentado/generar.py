# -*- coding: utf-8 -*-
import html, os, re

BASE = r"C:\Users\USUARIO\Documents\c\repaso-comentado"

# lista: (etiqueta_etapa, nombre_archivo)
archivos = [
    ("ETAPA 1 - Fundamentos, variables y operadores", "hola.c"),
    ("ETAPA 1 - Fundamentos, variables y operadores", "calculadora.c"),
    ("ETAPA 1 - Fundamentos, variables y operadores", "ficha.c"),
    ("ETAPA 1 - Fundamentos, variables y operadores", "inspector.c"),
    ("ETAPA 1 - Fundamentos, variables y operadores", "inspectorrecomendado.c"),
    ("ETAPA 1 - Fundamentos, variables y operadores", "maximo.c"),
    ("ETAPA 1 - Fundamentos, variables y operadores", "lanzamiento.c"),
    ("ETAPA 1 - Fundamentos, variables y operadores", "segundos.c"),
    ("ETAPA 1 - Fundamentos, variables y operadores", "segundosbucle.c"),
    ("ETAPA 2 - Condicionales y ciclos", "adivina.c"),
    ("ETAPA 2 - Condicionales y ciclos", "cafeteria.c"),
    ("ETAPA 2 - Condicionales y ciclos", "pin.c"),
    ("ETAPA 2 - Condicionales y ciclos", "tabla.c"),
    ("ETAPA 3 - Funciones", "cajerofuncion.c"),
    ("ETAPA 3 - Funciones", "duplicar.c"),
    ("ETAPA 3 - Funciones", "tablamultiplicar.c"),
    ("ETAPA 4 - Arreglos", "notas.c"),
    ("ETAPA 4 - Arreglos", "factorizarNotas.c"),
    ("ETAPA 4 - Arreglos", "Burbuja.c"),
    ("ETAPA 6 - Punteros", "punteros.c"),
    ("ETAPA 7 - structs", "estudiante.c"),
    ("ETAPA 7 - structs", "reporteprueba.c"),
    ("ETAPA 8 - Archivos", "guardar.c"),
    ("ETAPA 9 - Memoria dinamica", "dinamico.c"),
    ("ETAPA 9 - Memoria dinamica", "free.c"),
    ("ETAPA 10 - Proyecto integrador", "Agenda.c"),
    ("EXAMEN PRUEBA - Inventario", "inventario_a_corregir.c"),
    ("TALLER RUTA 1 - Tarea 2", "Yilmar_Galindo_tarea2.c"),
    ("TALLER RUTA 1 - Tarea 3", "Yilmar_Galindo_tarea3.c"),
]

css = """
  :root { --tinta:#1a1a2e; --acento:#0f3460; --fondo:#fff; --plomo:#f4f4f8; }
  * { box-sizing: border-box; }
  body { font-family:"Segoe UI",Arial,sans-serif; color:var(--tinta); max-width:900px; margin:0 auto; padding:24px 28px 60px; font-size:14px; line-height:1.4; }
  h1 { font-size:24px; color:var(--acento); text-transform:uppercase; letter-spacing:1px; margin:0 0 4px; }
  .subtitulo { color:#555; font-size:13px; margin:0 0 18px; }
  h2 { font-size:17px; margin:28px 0 8px; padding:6px 10px; background:var(--acento); color:#fff; border-radius:6px; break-after:avoid; }
  h3 { font-size:14px; margin:16px 0 4px; color:var(--acento); }
  code { font-family:Consolas,"Courier New",monospace; background:#eef; padding:1px 4px; border-radius:3px; font-size:12.5px; }
  pre { font-family:Consolas,"Courier New",monospace; background:#f7f7fb; border-left:4px solid var(--acento); padding:10px 12px; overflow-x:auto; font-size:12px; border-radius:4px; line-height:1.45; white-space:pre; }
  table { width:100%; border-collapse:collapse; margin:8px 0 14px; font-size:12.5px; }
  th,td { border:1px solid #ccd; padding:5px 7px; text-align:left; vertical-align:top; }
  th { background:var(--plomo); }
  @media print { body { max-width:100%; padding:10px; font-size:11px; } pre { font-size:10px; } h2 { break-after:avoid; } }
"""

def esc(code):
    return html.escape(code)

partes = []
partes.append("<!DOCTYPE html>\n<html lang=\"es\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>Repaso comentado de C - Todos los programas</title>\n<style>" + css + "</style>\n</head>\n<body>")
partes.append("<h1>Repaso comentado de C</h1>")
partes.append('<p class="subtitulo">Todos los programas funcionales del curso, comentados linea por linea para el examen · Yilmar · AvanzaTec</p>')

faltantes = []
etapa_actual = None
for etiqueta, nombre in archivos:
    ruta = os.path.join(BASE, nombre)
    if not os.path.exists(ruta):
        faltantes.append(nombre)
        continue
    with open(ruta, encoding="utf-8", errors="replace") as f:
        codigo = f.read()
    if etapa_actual != etiqueta:
        partes.append(f'<h2>{esc(etiqueta)}</h2>')
        etapa_actual = etiqueta
    partes.append(f'<h3>{esc(nombre)}</h3>')
    partes.append('<pre>' + esc(codigo.rstrip("\n")) + '</pre>')

partes.append("</body>\n</html>")

salida = "\n".join(partes)
with open(r"C:\Users\USUARIO\Documents\c\repaso-comentado\repaso_comentado.html", "w", encoding="utf-8") as f:
    f.write(salida)

print("Generado. Archivos faltantes:", faltantes if faltantes else "ninguno")
print("Tamano HTML:", os.path.getsize(r"C:\Users\USUARIO\Documents\c\repaso-comentado\repaso_comentado.html"), "bytes")
