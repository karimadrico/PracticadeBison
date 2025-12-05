# Ejemplos para la práctica
Archivos en este directorio:
- `ejemplo1.cob` — basado en el Ejemplo 1 del enunciado.
- `ejemplo2.cob` — basado en el Ejemplo 2 del enunciado.
- `ejemplo3.cob` — basado en el Ejemplo 3 del enunciado.

Cómo compilar y probar (en PowerShell, en la raíz del proyecto `Bison`):
powershell
# Ir a la carpeta 
cd /cygdrive/c/Users/kdraf/Downloads/Bison
ls -la
# Generar parser y lexer
bison -d parser.y -o parser.c
flex -o lexer.c lexer.l
# Compilar
gcc -std=c99 -O2 parser.c lexer.c -lfl -o compilador
# Ejecutar sobre un ejemplo
./compilador examples\ejemplo1.cob
