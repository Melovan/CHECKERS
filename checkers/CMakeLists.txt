# CMakeList.txt: проект CMake для checkers; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (checkers "checkers.cpp" "checkers.h" "controller.cpp" "controller.h" "view.cpp" "view.h" "model.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
