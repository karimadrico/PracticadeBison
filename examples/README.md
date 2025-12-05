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
bison -v -d parser.y
flex lexer.l
# Compilar
gcc -o compilador parser.tab.c lex.yy.c -lfl
# Ejecutar sobre un ejemplo
./compilador examples/ejemplo1.cob > ejemplo1.stdout 2> ejemplo1.stderr
cat ejemplo1.stdout
cat ejemplo1.stderr
# En PowerShell
.\compilador.exe .\examples\ejemplo1.cob > .\ejemplo1.stdout 2> .\ejemplo1.stderr
Get-Content .\ejemplo1.stdout
Get-Content .\ejemplo1.stderr
