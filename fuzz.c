#include <stdio.h>
#include <unistd.h>

#define DEBUG
#define fopen(path, mode) NULL
#define getchar() EOF
#include "src/interpreter.c"
#include "src/io.c"
#include "src/lexer.c"
#include "src/libs/common_lib.c"
#include "src/libs/core_lib.c"
#include "src/libs/datastructures_lib.c"
#include "src/libs/debug_lib.c"
#include "src/libs/io_lib.c"
#include "src/libs/math_lib.c"
#include "src/libs/modules_lib.c"
#include "src/libs/string_lib.c"

__AFL_FUZZ_INIT();

int main(void)
{
    #ifdef __AFL_HAVE_MANUAL_CONTROL
    __AFL_INIT();
    #endif

    char *src = 0;
    unsigned char *buf = __AFL_FUZZ_TESTCASE_BUF;
    while (__AFL_LOOP(10000)) {
        int len = __AFL_FUZZ_TESTCASE_LEN;
        src = realloc(src, len);
        memcpy(src, buf, len);
        beryl_eval(src, len, true, BERYL_ERR_PROP);
    }
    return 0;
}
