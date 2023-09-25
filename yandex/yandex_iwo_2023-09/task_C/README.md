# C. Наследование репозиториев

| Ограничение времени | 1 секунда                        |
| ------------------- | -------------------------------- |
| Ограничение памяти  | 512Mb                            |
| Ввод                | стандартный ввод или input.txt   |
| Вывод               | стандартный вывод или output.txt |

В системе контроля версий SEHR GUT можно наследовать репозиторий и вносить изменения кода в какую либо версию кода. При этом изменение, внесенное в версию кода, автоматически вносится во все репозитории, из которых был наследован код.

Исходно в системе есть только репозиторий $0$. Если от него были пронаследованы репозитории $1$ и $2$, а от репозитория $1$ был наследован репозиторий $3$ и изменения были внесены в репозиторий $3$, то они также внесутся в репозитории $1$ и $0$ (но не в репозиторий $2$).

Вася хочет внести изменение в один репозиторий таким образом, чтобы они оказались в как можно большем количестве репозиториев.

## Формат ввода

Во входном файле записано число $N$ — общее количество наследованных репозиториев ($1 ≤ N ≤ 100000$). Затем следует описание наследования репозиториев: в $i$-ой строке записано число $R_i$ — номер репозитория, наследником которого является $i$-ый репозиторий ($0 ≤ R_i < i$). Начальный репозиторий имеет номер $0$.

## Формат вывода

Выведите номер репозитория, в который нужно внести изменения Васе. Если правильных ответов несколько — выведите любой из них.

### Пример 1

### Ввод

```textile
3
0
0
1
```

### Вывод

```textile
3
```

### Пример 2

### Ввод

```textile
8
0
1
2
0
4
5
6
4
```

### Вывод

```textile
7
```

## Примечания

Первый пример соответствует ситуации, описанной в условии. Репозитории номер $1$ и $2$ пронаследованы от репоизитория с номером $0$. Репозиторий номер $3$ пронаследован от репозитория номер $1$. Если внести изменение в репозиторий номер $3$, то это изменение окажется в репозиториях с номерами $3$, $1$ и $0$.