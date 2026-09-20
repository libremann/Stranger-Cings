# Game with restrict
Here, by intentionally violating the `restrict` contract, we were able to make the program produce two different outputs at two different compiler optimization levels.


## How to Compile

```bash
➜ gcc -O0 main.c ; ./a.out
20
➜ gcc -O1 main.c ; ./a.out
10
```

```bash
➜ clang -O0 main.c ; ./a.out
20
➜ clang -O1 main.c ; ./a.out
10
```
