# Get_Next_Line

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/1eca252eff32495bb0333a44d9ed365b)](https://app.codacy.com/app/gde-pass/GNL?utm_source=github.com&utm_medium=referral&utm_content=gde-pass/GNL&utm_campaign=Badge_Grade_Dashboard) ![https://img.shields.io/badge/Grade-125%2F100-green.svg](https://img.shields.io/badge/Grade-125%2F100-green.svg)

## What is Get_Next_Line ?
Get_next_line is a 42 Project and a useful function, that basically reads a file line by line.

```python
￼int get_next_line(int const fd, char **line);
```
The first parameter is the file descriptor from which to read , and the second is a pointer to where the client would like the next line to be placed. The function will return the next line of a file without the '\n' at the end. The function will return 1 if successful, 0 if the file has nothing to read, and -1 if there is an error.

## Authorized functions:
You probably will never have to use this function if you are not a 42 student. The goal is to get better at C. You can only use those three standard library functions:
* read
* malloc
* free

So it makes the project harder. But you can also use functions from your [libft](https://github.com/gde-pass/libft).

[Get_Next_Line.fr.pdf](https://cdn.intra.42.fr/pdf/pdf/661/get_next_line.fr.pdf) - Subject FR
