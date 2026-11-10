1. Mochila Fraccional (Fractional Knapsack)

Estrategia Voraz: Ordena los objetos en función del ratio valor/peso ($v_i / w_i$) en orden descendente. Inserta objetos completos mientras haya capacidad y toma una fracción continua del último objeto para llenar la mochila.
Complejidad Temporal: $\mathcal{O}(n \log n)$ por ordenamiento.
Complejidad Espacial: $\mathcal{O}(n)$ para almacenar los objetos.

2. Cobertura de Antenas WiFi

Estrategia Voraz: Identifica la primera casa sin cobertura $x_{\text{izq}}$ y coloca la antena en $x_{\text{izq}} + R$, cubriendo hasta $x_{\text{izq}} + 2R$. Minimiza el número global de transmisores requeridos.
Complejidad Temporal: $\mathcal{O}(n \log n)$ por ordenamiento previo de posiciones.
Complejidad Espacial: $\mathcal{O}(k)$ donde $k$ es el número de antenas instaladas.


El proyecto necesita:

Compilador de C++ compatible con C++11 o superior
Un sistema operativo ya sea Ventanas, Linux o MacOS
Una IDE como VisualStudio

Con todos estos requisitos solo es necesario crear un nuevo proyecto en la IDE de preferencia, copiar el contenido del main.cpp de este proyecto y compilar.
