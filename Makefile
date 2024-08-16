# Имя исполняемого файла
TARGET = replace_numbers

# Компилятор
CC = gcc

# Флаги компилятора
CFLAGS = -Wall -Wextra -std=c99

# Исходные файлы
SRCS = main.c

# Правило по умолчанию
all: $(TARGET)

# Правило для создания исполняемого файла
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Правило для очистки
clean:
	rm -f $(TARGET)
