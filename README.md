# nextline

get_next_line(int fd): 
Esta función es como si quisieras leer una página del libro. El "descriptor de archivo fd" es la dirección del libro que quieres leer. Si la dirección del libro es inválida (es decir, fd < 0) o si el tamaño de la página es 0 o menos (BUFFER_SIZE <= 0), entonces la función termina y devuelve NULL, como si dijeras "No puedo leer este libro". Si todo está bien, la función intenta leer una página del libro.

create_list(&list, fd): Esta función es como abrir el libro en la dirección que proporcionaste. Crea una nueva lista (que es como un marcador de libro) para el libro que quieres leer. Si no puede abrir el libro, la función devuelve NULL.

list_to_line(list, &line): Esta función es como leer una línea de la página actual del libro y guardarla en line. Si la línea que leíste es vacía o NULL, entonces liberas la lista (como si cerraras el libro) y devuelves NULL.

clean_list(&list): Esta función es como limpiar tu marcador de libro. Después de leer una línea, limpias la lista para que esté lista para la próxima vez que quieras leer una línea.

read_to_node(int fd, int *read_count): Esta función es como leer una parte del libro y guardarla en una caja (que es un nodo de una lista enlazada). El "descriptor de archivo fd" es la dirección del libro y "read_count" es un contador de cuántas partes del libro has leído. Si algo sale mal (como si no pudieras encontrar el libro o si la caja no es lo suficientemente grande), entonces la función devuelve NULL.


Explicación de cada parte del archivo get_next_line.h utilizando el ejemplo del libro:

#ifndef GET_NEXT_LINE_H ... #endif: Esto es como una cubierta de libro. Si ya tienes una copia del libro (es decir, si ya has incluido get_next_line.h antes), no necesitas otra, así que la cubierta evita que obtengas otra copia.

# define BUFFER_SIZE 42: Esto es como definir el tamaño de las páginas del libro. En este caso, cada página tiene 42 caracteres.

# include <unistd.h> ... # include <stdio.h>: Estas son como las herramientas que necesitas para leer el libro. Incluyen cosas como un marcador de libro (<unistd.h>), una lámpara para leer en la oscuridad (<stdlib.h>), una llave para abrir el libro (<fcntl.h>) y unas gafas para leer (<stdio.h>).

typedef struct s_list ... t_list;: Esto es como definir qué es un marcador de libro. Un marcador de libro tiene un contenido (que es la página actual que estás leyendo) y un puntero al siguiente marcador de libro (que es la próxima página que quieres leer).

char *get_next_line(int fd); ... void free_list(t_list *list);: Estas son las instrucciones para leer el libro. Incluyen instrucciones para obtener la próxima línea del libro (get_next_line), leer una parte del libro y guardarla en un marcador de libro (read_to_node), encontrar una nueva línea en la página actual (find_newline), abrir el libro (create_list), leer una línea de la página actual (list_to_line), crear una línea para guardar lo que leíste (create_line), limpiar tu marcador de libro (clean_list), pasar al siguiente marcador de libro (pass_over_node) y liberar el marcador de libro cuando hayas terminado de leer (free_list).
