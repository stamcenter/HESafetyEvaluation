// start from openssl
// $arg1 -> %rdi
// $arg2 -> %rsi
// $arg3 -> %rdx
// remove backslashes
// abi-omnipotent -> @function
// remove endbranch

.globl  CRYPTO_memcmp
.type   CRYPTO_memcmp,@function
.align  16
CRYPTO_memcmp:
.cfi_startproc
        xor     %rax,%rax
        xor     %r10,%r10
        cmp     $0,%rdx
        je      .Lno_data
        cmp     $16,%rdx
        jne     .Loop_cmp
        mov     (%rdi),%r10
        mov     8(%rdi),%r11
        mov     $1,%rdx
        xor     (%rsi),%r10
        xor     8(%rsi),%r11
        or      %r11,%r10
        cmovnz  %rdx,%rax
        ret

.align  16
.Loop_cmp:
        mov     (%rdi),%r10b
        lea     1(%rdi),%rdi
        xor     (%rsi),%r10b
        lea     1(%rsi),%rsi
        or      %r10b,%al
        dec     %rdx
        jnz     .Loop_cmp
        neg     %rax
        shr     $63,%rax
.Lno_data:
        ret
.cfi_endproc
.size   CRYPTO_memcmp,.-CRYPTO_memcmp
