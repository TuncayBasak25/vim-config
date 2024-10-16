#ifndef LIB_H
# define LIB_H

char	*str_new(size_t capacity);
char	*str_ext(char *str, size_t capacity);

char	*get_file_content(const char *filename);

#endif
