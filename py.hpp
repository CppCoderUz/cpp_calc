#include <iostream>
#include <fstream>

void print(std::string a){
    std::cout << a;
}

std::string input(){
    std::string __str;
    getline(std::cin, __str);
    return __str;
}


std::string calculator(std::string task){
    std::string py_code[] = {
        "from math import *",
        "try:a = eval(\"" + task + "\")",
        "except:a = 'Xatolik yuz berdi'",
        "with open('my_py_code_task_eval.txt', 'w') as file:file.write(str(a))",
        };
    std::ofstream open_py_file("my_py_file_id676756478545574.py");
    for (std::string a: py_code){
        open_py_file << a << std::endl;
    }
    open_py_file.close();
    /** Dastur ishlashi uchun system funksiyasini keraklisini kommentariyadan oching **/
    /// Agar siz windowsda bolsangiz quyidagi system funksiyasini ishlata olasiz
    // system("python my_py_file_id676756478545574.py");
    /// Mac ishlatsangiz bu qismni ishlatasiz
    // system("python3 my_py_file_id676756478545574.py");
    std::ifstream my_task_question("my_py_code_task_eval.txt");
    std::string a, b;
    while(getline(my_task_question, a)){
        b = a;
        break;
    }
    /// Dastur vaqt davomida 2 ta ortiqcha fayl yaratadi. 
    /* Agar ularni o'chirmoqchi bolsangiz kommentariyani olib tashlang */
    // system("rm my_py_file_id676756478545574.py"); system("rm my_py_code_task_eval.txt");
    
    return b;
}
