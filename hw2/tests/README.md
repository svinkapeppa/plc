# Тесты

Тесты покрывают следующие случаи:
* Аварийное завершение при срабатвании исключения во время очистки стека [emergency.cpp](emergency.cpp)
* "Пролет" исключений [nestedexception.cpp](nestedexception.cpp)
* Типизация исключений [types.cpp](types.cpp)
  * Также в данном тесте показано использование нескольких CATCH блоков