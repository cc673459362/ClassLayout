/*
 * @Author: jiafengchen jiafengchen@tencent.com
 * @Date: 2024-01-11 19:37:51
 * @LastEditors: jiafengchen jiafengchen@tencent.com
 * @LastEditTime: 2024-01-11 19:39:30
 * @FilePath: /test/fixfile.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    std::ifstream inputFile(argv[1]); // 替换为你的输入文件名
    std::ofstream outputFile(argv[2]); // 替换为你的输出文件名

    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        bool keepLines = false;

        while (std::getline(inputFile, line)) {
            if (line.find("*** Dumping AST Record Layout") != std::string::npos) {
                keepLines = true;
            }

            if (keepLines) {
                outputFile << line << std::endl;
            }

            if (line.empty()) {
                keepLines = false;
            }
        }

        inputFile.close();
        outputFile.close();

        std::cout << "Extraction complete." << std::endl;
    } else {
        std::cout << "Failed to open files." << std::endl;
    }

    return 0;
}