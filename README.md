# Get Next Line - 42 Barcelona

**Get Next Line** is a project at 42 that teaches you how to read a line from a file descriptor in C. The goal is to create a function that returns one line at a time from a file or standard input, handling multiple file descriptors and dynamic memory allocation.

---

## Table of Contents
1. [Introduction](#introduction)
2. [Project Overview](#project-overview)
3. [Function Prototype](#function-prototype)
4. [Installation](#installation)
5. [Usage](#usage)
6. [License](#license)

---

## Introduction

The **get_next_line** project is designed to help you understand file handling, dynamic memory allocation, and static variables in C. You will write a function that reads a file descriptor line by line, returning each line as a string. This project is a great introduction to working with system calls and managing memory efficiently.

---

## Project Overview

The goal of this project is to implement the `get_next_line` function, which reads a line from a file descriptor and returns it as a string. The function should handle multiple file descriptors and manage memory dynamically to avoid leaks.

---

## Function Prototype

The function prototype for `get_next_line` is:

### Parameters:

- fd: The file descriptor to read from.
- line: A pointer to a string where the line will be stored.

### Return Value:
- 1: A line has been read successfully.
- 0: EOF (End of File) has been reached.
- -1: An error occurred.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/nkaryoli/get_next_line.git

2. Navigate to the project directory:
   ```bash
   cd get_next_line

3. Compile the program:
   ```bash
   make

## Usage
To use the get_next_line function in your project:

1. Include the get_next_line.h header file in your source code or Makefile:
   ```bash
   #include "get_next_line.h"

2. Include get next line files when compiling:
   ```bash
   get_next_line.c
   get_next_line_utils.c

3. Example usage:
   ```bash
    int main(void)
    {
      int fd;
      char *line;

      fd = open("file.txt", O_RDONLY);
      while (get_next_line(fd, &line) > 0)
      {
          printf("%s\n", line);
          free(line);
      }
      close(fd);
      return (0);
    }

## License
This project is part of the 42 curriculum and is licensed under the 42 License. See the LICENSE file for details.

Good luck with your journey at 42 Barcelona! 🚀
