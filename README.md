# nextline

get_next_line(int fd): Esta función es como si quisieras leer una página del libro. El "descriptor de archivo fd" es la dirección del libro que quieres leer. Si la dirección del libro es inválida (es decir, fd < 0) o si el tamaño de la página es 0 o menos (BUFFER_SIZE <= 0), entonces la función termina y devuelve NULL, como si dijeras "No puedo leer este libro". Si todo está bien, la función intenta leer una página del libro.

create_list(&list, fd): Esta función es como abrir el libro en la dirección que proporcionaste. Crea una nueva lista (que es como un marcador de libro) para el libro que quieres leer. Si no puede abrir el libro, la función devuelve NULL.

list_to_line(list, &line): Esta función es como leer una línea de la página actual del libro y guardarla en line. Si la línea que leíste es vacía o NULL, entonces liberas la lista (como si cerraras el libro) y devuelves NULL.

clean_list(&list): Esta función es como limpiar tu marcador de libro. Después de leer una línea, limpias la lista para que esté lista para la próxima vez que quieras leer una línea.

read_to_node(int fd, int *read_count): Esta función es como leer una parte del libro y guardarla en una caja (que es un nodo de una lista enlazada). El "descriptor de archivo fd" es la dirección del libro y "read_count" es un contador de cuántas partes del libro has leído. Si algo sale mal (como si no pudieras encontrar el libro o si la caja no es lo suficientemente grande), entonces la función devuelve NULL.

