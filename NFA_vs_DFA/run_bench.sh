rm pcre re2c regex
echo "\n"
gcc -o regex regex.c; ./regex
echo "\n"
gcc -o pcre pcre.c -lpcre; ./pcre
echo "\n"
gcc -o re2c re2c_new.c; ./re2c
echo "Benchmark end\n Regex NFA vs DFA\n"
