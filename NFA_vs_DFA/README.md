Install libs and compiler:
```
$ sudo apt install libpcre2-dev gcc make
```

To run:
```
$ sh run_bench.sh
```

Benchmark on my machine:
```
cooler@cooler-swamp:~/Desktop/DFA_vs_NFA_REGEX/optimizing_treasures/NFA_vs_DFA$ cat /proc/cpuinfo | head -n 5 | uname -a; date; cat /prox/cpuinfo; sh run_bench.sh 
Linux cooler-swamp 5.4.0-122-generic #138-Ubuntu SMP Wed Jun 22 15:00:31 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
qui 11 ago 2022 02:33:47 -03
cat: /prox/cpuinfo: No such file or directory


::: Posix regex: 2559430  cicles
Array size of words is: 245 
Benchmark match posix regex [0-9]{4}(-| )[0-9]{4} - total matches : 96 


::: PCRE regex: 349704  cicles
Array size of words is: 245 
Benchmark PCRE \d{4}( |-){1}\d{4} matchs is: 96 



::: Re2c : 3242  cicles
Array size of words is: 245 
Benchmark match posix regex [0-9]{4}(-| )[0-9]{4} - total matches : 96 
Benchmark end
 Regex NFA vs DFA

```
