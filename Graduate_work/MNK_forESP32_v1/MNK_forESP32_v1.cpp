// MNK_forESP32_v1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "xserial.hpp"
#include "xserial.cpp"
using namespace std;


int main() {

    std::cout << "Hello World!\n";
    // инициализируем доступный COM порт, без проверки бита четности, с 8-мью битами данных и одним стоп битом.
    const int baudRate = 115200; // скорость порта
    const int dataBits = 8; // длина данных
    const int numComPort = 6; // номер порта
    xserial::ComPort serial; /*
    
    serial.open(); // открыть указанный порт с настройкой скорости

    serial.printListSerialPorts();

    if (!serial.getStateComPort()) { // Если порт не открылся
        cout << "Error: com port is not open!" << endl;
        return 0;
    }

    if (serial.getStateComPort()) { // Если порт не открылся
        cout << serial.getLine() << endl;
    }
    // выводим список доступных портов
    serial.printListSerialPorts();*//*
    
    // получаем текст до символа \n
    cout << "Test getLine()..." << endl;
    serial << "Test 1\n";
    cout << serial.getLine() << endl;

    // проверяем функцию проверки количества принятых байт
    cout << "Test bytesToRead()..." << endl;
    //serial.print("Test 2\n");
    int k = serial.bytesToRead();
    cout << "bytes to read = " << k << endl;
    while (k < 6) {
        k = serial.bytesToRead();
    }
    cout << "bytes to read = " << k << endl;

    // проверяем функцию чтения
    char data[512];
    cout << "Test read()..." << endl;
    serial.read(data, 7);
    cout << data << endl;

    // проверяем функцию чтения слова
    //serial.print("Bla Bla Bla\n");
    cout << "Test getWord(), print Bla Bla Bla" << endl;
    cout << "Word 1: " << serial.getWord() << endl;
    cout << "Word 2: " << serial.getWord() << endl;
    cout << "Word 3: " << serial.getWord() << endl;
    */
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
