PROGRAMA NESTED-CONTROL-STRUCTURES.
INICIO
      * Ejemplo de condicional anidada en un bucle while
       MUEVE 10 A V1.
       MUEVE 0 A V2.
       EJECUTA
          SI V2 ES MENOR QUE V1 ENTONCES
            MUESTRA V2.
          FIN-SI.
          SUMA 1 A V2.
       FIN-EJECUTA
       HASTA-QUE V1 ES IGUAL A V2.
      * Ejemplo de bucles anidados
       MUEVE 5 A V1.
       MUEVE 0 A C.
       EJECUTA
           RESTA 1 DE V1.
           EJECUTA
             SUMA 2 A C.
             MUESTRA V1, V2, C.
           FIN-EJECUTA
           HASTA-QUE C ES MAYOR QUE 10.
       FIN-EJECUTA
       HASTA-QUE V1 ES IGUAL A 0.
FIN.
