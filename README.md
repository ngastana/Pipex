🧩 Pipex
Pipex es un proyecto de 42 que recrea el comportamiento del mítico pipe de Unix (|) — ese símbolo mágico que permite encadenar comandos como si fueran una sola sinfonía de procesos 🎶.
En pocas palabras: tu programa toma la salida de un comando y la usa como entrada del siguiente, exactamente como lo hace la shell.
🧠 Project Overview
Vas a construir un programa que imite este comando del shell:
$ < infile cmd1 | cmd2 > outfile
Pero lo harás funcionar así:
$ ./pipex infile cmd1 cmd2 outfile
Tu programa debe:
📂 Abrir infile para lectura.
⚙️ Ejecutar cmd1 usando infile como entrada.
🔗 Conectar la salida de cmd1 a la entrada de cmd2 mediante un pipe.
💾 Redirigir la salida de cmd2 hacia outfile.
En resumen: un mini shell que maneja redirecciones y pipes...
✨ pero sin la ayuda de autocompletado, ni los bonitos mensajes de error del bash 😅
🧰 Example
🏗️ Compilación
make
Esto generará el ejecutable pipex.
🚀 Ejemplo de ejecución
./pipex infile "grep something" "wc -l" outfile
Equivalente a:
< infile grep something | wc -l > outfile
⚙️ Allowed Functions
Durante el viaje solo podrás usar las siguientes joyas del sistema 🛠️:
open, close, read, write
pipe, dup, dup2
fork, execve
wait, waitpid
access, perror, strerror
malloc, free
Nada de atajos como system()… ¡esto es 42! 🧱
💥 Error Handling
Tu programa debe saber comportarse incluso cuando todo sale mal 💣:
❌ Si el archivo no existe → mostrar un error y salir con gracia.
⚠️ Si el comando no es válido → imprimir command not found.
🧼 Y por supuesto: sin fugas de memoria (ni una sola).
