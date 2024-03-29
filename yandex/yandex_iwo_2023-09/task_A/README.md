# A. USB-порты

| Ограничение времени | 2 секунды                        |
| ------------------- | -------------------------------- |
| Ограничение памяти  | 256Mb                            |
| Ввод                | стандартный ввод или input.txt   |
| Вывод               | стандартный вывод или output.txt |

Вася подсчитал, что у него есть m гаджетов, которые нужно подключить к USB и всего $n$ USB-портов на компьютере. В ближайшем интернет-магазине продаются разветвители с одного USB на два за $c2$ рублей и USB-хабы с одного USB на пять по $c5$ рублей.

Разветвители и хабы можно подключать друг к другу и к USB-портам компьютера. Определите, какое минимальное количество рублей нужно потратить Васе, чтобы подключить все USB устройства. При этом можно обеспечить возможность подключить и больше $m$ гаджетов, главное минимизировать цену.

## Формат ввода

В первой строке входных данных записано число $n$ ($1≤n≤1015$) — количество USB-портов у компьютера. Во второй строке записано число $m$ ($1≤m≤1015$) — количество USB-гаджетов.

В следующих двух строках записаны целые числа $c2$ и $c5$ ($1≤c2,c5≤1000$).

## Формат вывода

Выведите одно целое число — минимальное количество рублей, которое надо потратить для покупки необходимого количества разветвителей и хабов.

### Пример 1

### Ввод

```textile
1
3
1
10
```

### Вывод

```textile
2
```

### Пример 2

### Ввод

```textile
2
4
9
10
```

### Вывод

```textile
10
```

### Пример 3

### Ввод

```textile
3
8
9
10
```

### Вывод

```textile
19
```
