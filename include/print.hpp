#include <string>
#include <fstream>
#include <iostream>

void print(const std::string& text, std::ostream& out = std::cout); // вывод строки в стандартный поток std::cout
void print(const std::string& text, std::ofstream& out);  // вывод в файловый поток
