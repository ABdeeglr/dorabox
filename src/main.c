#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>

/* ----- 可移植性拓展 -----
 * typedef __int32 size_t;
 * typedef __int64 size_t;
 */

static char* relative_path = "~/Manual";

//----------- Function Formulation ----------
void die(const char* message); // 当遇到错误时结束任务
int test_function(int argc, const char* argv[]); // 用于测试新的功能
void response_to_incorrect_use(); // 解释这个程序的使用方式
char *absolute_path(char* path);// 接收一个文件名,并将其翻译为位于 Manual 的地址
int status_analysis(const char** command); // 根据命令行调用本程序时的输入，返回一个整数，这个整数将决定之后进行的任务。
void format_print(const char* filename); // 打开 <filename> 并格式化输入其中的内容。
void invoke_vim_to_create_manual(const char* filename); // 在 ~/Manual 下创建一个名为 <filename> 的新说明，并使用 vim 编辑.


// ------- 程序入口 -------
int main(int argc, char const *argv[])
{
    switch(status_analysis(argv)) {
    case 0:
        test_function(argc, argv);
        
    case 1:
        format_print(argv[1]);

    case 2:
        invoke_vim_to_create_manual(argv[2]);

    default:
        return 0;
    }

    return 0;
}




// ------------ Function Statement ------------

void die(const char* message) {
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}



void response_to_incorrect_use() {
    printf("在 ~ 目录下创建一个 Manual 文件夹，~/Manual目录将会是存放自定义说明的地方。\n");
    printf("输入 -h 获取使用指南\n");

    die("Good Luck.");
}


int test_function(int argc, const char* argv[]) {

    int index = 0;
    for (index = 1; index < argc; index ++) {
        printf("Parameter No.%d: %s\n", index, argv[index]);
    } // 当调用测试函数时，始终打印所有参数
    

    execlp("cmatrix", "cmatrix", NULL);
    /* execl(), execv(), execlp(), execvp() 函数接受三个参数段。
     * 在 shell 中使用命令时，比如 cat <path/file_name> [other_parameter]
     * 对应到 exec() 函数族中，函数的第一个参数段只接受一个类型为字符串类型变量
     * 用于表示跳转的程序名
     * 第二个参数段是若干个字符串或者一个字符串数组，用于给外部程序传参
     * 字符串数组的第一个字符串没有意义，但必须要写上，至于字符串内容任意
     * 其余每一项都是一次传参
     * 最后一个参数段是 NULL，代表给外部程序传参结束，不能省略。
     * 对于任意一个在 shell 中执行的命令，比如 vim   main.c 大致可以抽象为
     *                                    |      |
     *                          <programe_name>  |
     *                                         <path:file> [parameter]
     * 在对应的 exec() 函数中写成
     * exec(pgm_name, "any", "path:file", "parameter",..., NULL);
     * 注意：外部程序一旦被调用，调用者就将结束
     */
    
    // 如果 execl() 执行成功，下面执行不到，因为当前进程已经被执行的 ls 替换了
    die("exec failed\n");
    printf("after exec\n");
 

    return 0;
}


char *absolute_path(char * path) {
    unsigned short int length = strlen(path) + 8;

    char* res = malloc(length);
    unsigned short int index = 0;
    /* [string copy part]
    for (index = 0; index < 8; index++) {
        res[index] = *relative_path + index;
    }
    for (index = 8; index < length; index++) {
        res[index] = *path + index - 8;
    }
    */

    return res;
}


int status_analysis(const char** command) {
    int status = 0;
    return status;
}


void format_print(const char* filename) {
    int i = 0;
}

void invoke_vim_to_create_manual(const char* filename) {
    int i = 0;
}