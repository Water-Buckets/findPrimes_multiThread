#include "includes/main.h"

int main(int argc, char *argv[]) {
    switch (argc) {
        case 1:
            // 无参数时打印帮助信息
            printHelp();
            break;
        case 5:
            // 有参数时执行
            argInput(argv);
            break;
        default:
            // 参数数量错误时抛出异常
            throw std::invalid_argument("Invalid input.");
    }
}
