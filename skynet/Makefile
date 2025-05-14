# Компилятор
CXX = g++
# Флаги компиляции
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic
# Имя исполняемого файла
TARGET = sky

# Все исходные .cpp файлы
SRCS = sky.cpp bubble.cpp 
# Генерируем список объектных файлов .o
OBJS = $(SRCS:.cpp=.o)

# Основная цель сборки
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для компиляции .cpp в .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка собранных файлов
clean:
	rm -f $(OBJS) $(TARGET)

# Указываем, что цели 'all' и 'clean' не являются реальными файлами
.PHONY: all clean
