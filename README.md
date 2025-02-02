# binary-data-analyzer

## Структура проекта

* src

    * analyzer - основное приложение

    * tests - тесты

* utils - скрипты для работы с проектом

## Сборка

Для сборки используется система сборки **CMake** и компилятор **clang**

Сборку можно осуществить вызовом **utils/build.sh**

## Запуск

Запуск приложения осуществляется вызовом **utils/run.sh** с параметрами 

```
Params: 
        <file1> <file2> <result_file>

Ex: ./binary-analyzer dump1.txt dump2.txt result.txt
```

Вызов с `-h` позволяет вывести справку

## Тесты

Запуск тест кейсов осуществляется вызовом **utils/test.sh**

Тест-кейсы описаны в **src/tests/cases.h**
