## brainfree
A try to create relatively small code-base and slow brainfuck interpreter.\
Things were improved from [brainfuck-rt](https://github.com/rilysh/brainfuck-rt)

### Performance
- brainfuck-rt
```
real	0m28.158s
user	0m28.117s
sys	0m0.032s
```
- brainfree
```
real	0m24.154s
user	0m24.142s
sys	0m0.004s
```
#### Info
Things like ternary, vectorization, and several other glibc functions helped this. Previously usage of "putc_unlocked" and then flushing was a big issue. However, there are a lot of other things can be improved, anyway, this version is more focused on less code :)\
Note: Don't use it anywhere else, except for playing
