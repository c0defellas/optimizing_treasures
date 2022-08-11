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
cooler@cooler-swamp:~/Desktop/DFA_vs_NFA_REGEX/optimizing_treasures/NFA_vs_DFA$ cat /proc/cpuinfo | head -n 5; uname -a; date; sh run_bench.sh 
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 142
model name	: Intel(R) Core(TM) i7-8650U CPU @ 1.90GHz
Linux cooler-swamp 5.4.0-122-generic #138-Ubuntu SMP Wed Jun 22 15:00:31 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
qui 11 ago 2022 02:37:32 -03


::: Posix regex: 2596158  cicles
Array size of words is: 245 
Benchmark match posix regex [0-9]{4}(-| )[0-9]{4} - total matches : 96 


::: PCRE regex: 349138  cicles
Array size of words is: 245 
Benchmark PCRE \d{4}( |-){1}\d{4} matchs is: 96 



::: Re2c : 3632  cicles
Array size of words is: 245 
Benchmark match posix regex [0-9]{4}(-| )[0-9]{4} - total matches : 96 
Benchmark end
 Regex NFA vs DFA


```
