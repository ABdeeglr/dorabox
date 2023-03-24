#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>

/* ----- 可移植性拓展 -----
 * typedef __int32 size_t;
 * typedef __int64 size_t;
 */

static char* relative_path = "~/Manual";

//----------- Function Formulation ----------
// 当遇到错误时结束任务 [x]
void die(const char* message);

// 用于测试新的功能 [1]
int test_function(int argc, const char* argv[]);

// 解释这个程序的使用方式 [0]
void response_to_incorrect_use();

// 接收一个文件名,并将其翻译为位于 Manual 的地址 [0]
char *absolute_path(char* path);

// 根据命令行调用本程序时的输入，返回一个整数，这个整数将决定之后进行的任务 [0]
int status_analysis(const char** command);

// 读取 <filename> 并格式化输出其中的内容 [1]
void format_print(const char* filename);

// 在 ~/Manual 下创建一个名为 <filename> 的新说明，并使用 vim 编辑 [0]
void invoke_vim_to_create_manual(const char* filename);


// ------- 程序入口 -------
int main(int argc, const char *argv[])
{
    switch(status_analysis(argv)) {
    case 0:
        char* res = absolute_path(argv[1]);
        format_print(res);
        free(res);
        break;
        
    case 1:
        format_print(argv[1]);
        break;

    case 2:
        invoke_vim_to_create_manual(argv[2]);
        break;

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
    

    // execlp("cmatrix", "cmatrix", NULL);
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
    // die("exec failed\n");
    // printf("after exec\n");

    printf("\033red red red \033\n");

    return 0;
}


char *absolute_path(char * path) {
    char *input_path = path;
    char *head_path = "/home/abdeeglr/Manual/";
    
    int count = strlen(head_path);
    int countp = strlen(input_path);
    
    char *abs_path = malloc(count + countp);
    
    int i = 0;
    for (i = 0; i < count; i++) {
        abs_path[i] = head_path[i];
    }
    
    for (i = 0;i < countp; i++) {
        abs_path[i+count] = input_path[i];
    }

    return abs_path;
}


int status_analysis(const char** command) {
    int status = 0;
    return status;
}


void format_print(const char* filename) {
    // 由于缺少 TUI 库的认知，目前暂时搁置格式化输出的想法，毕竟具体遵循何种样式也有考虑过。
    // 目前的功能是如实打印文件中的内容。

    FILE *p_manual = fopen(filename, "r");

        char word;
        while((word = getc(p_manual)) != EOF) {
            putchar(word);
        }
        if (fclose(p_manual) != 0) die("File close error!");
    


}

void invoke_vim_to_create_manual(const char* filename) {
    int i = 0;
}