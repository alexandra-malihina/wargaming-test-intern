// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <string>

//Начало работы программы
const clock_t start = clock();
//Функция вывода комментария в консоль
void writeComment(std::string str)
{
    std::cout <<"\n\n######################################"<< std::endl;
    std::cout << str <<"\n\n" << std::endl;
}

//Время выполнения программы с самого начала до текущего момента
double  Duration() {
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
}

//Функция проверки четнсти элемента из Задания№1
void isEven(int value) {
    std::cout << value << " " << (value % 2 == 0) << std::endl;

}
//Улучшенный вариант функции проверки четности элемента. Использует бинарное умножение.
// Поскольку нечетные числа в двоичной системе всегда оканчиваются 1, то при бинарном умножении числа на 1 нечетное число будет равно 1, а четное 0.
void isEvenNew(int value) {
    std::cout <<value <<" "<< !(value&1) << std::endl;
}


//Первый класс циклического FIFO на основе статического массива
class ArrayFIFO {
private:
    int arrayLength, head, tail; //Длина массива, индекс головы и хвоста
    int* arrayValues; // Массив - буфер
public:
    ArrayFIFO(int length) { // Конструктор. создание массива определенной длины. обнуление головы и хвоста.
        arrayLength = length;
        arrayValues = new int[length];
        head = tail = 0;
    }
    void getArray() { // метод вывода значений буфера
        if (head != tail) // если FIFO не пуст, то выводим его
        {
            for (int i = head; i < tail; i++)
            {
                std::cout << arrayValues[i] << ' ';
            }
            std::cout << std::endl;
        }
        else { // иначе выводим сообщение, что массив пуст
            std::cout << "FIFO is empty" << std::endl;
        }
        
    }
  
    void add(int val) { // метод добавления нового элемента
        int p = tail + 1; //вспомогательная переменная
        if (p == arrayLength+1) // если достигли конца массива, то пере ходим в его начало
        {
            p = 0;
        }
        if (p == head)// если будущее положение хвоста будет равно положению головы - значит массив полон и добавить новый элемент нельзя
        {
            std::cout << "FIFO is full" << std::endl;
        }
        else { // если можно добавить новый элемент - добавляем
            arrayValues[tail] = val;
            tail = p;
        }
    }

    void push() { //метод удаления элемента
        if (head != tail) //если положение головы не совподает с положением хвоста, то FIFO не пуст
        {
            if (++head == arrayLength) // изменение положение хвоста
            {
                head = 0;
                if (tail == arrayLength) // если голова переходит в 0, то проверяем положение хвоста. Если указывал на самый последний элемент( уже вытащили его), значит переводим в 0.
                    tail = 0;
            }
            
        }
        else
        {
            std::cout << "FIFO is empty" << std::endl;
        }

    }
};

//Реализация класса циклического FIFO для задания№2 . способо 2.
struct fifoElement { //структура, описывающая элемент FIFO
    int value; //данные
    fifoElement* next;// указатель на следующий элемент
};

class DynamicFIFO {     //класс
private: 
    int size; // текущий размер буффера
    int maxSize;//максимальный размер буффера
    fifoElement* head, * tail; //начало и конец FIFO
public:
    DynamicFIFO(int maxSizeValue) { //конструктор . обнуление головы и хвоста, установление максимального значения размера буффера
        head  = tail = nullptr;
        maxSize = maxSizeValue;
        size = 0;
    }
    ~DynamicFIFO() { //деструктор. т.к. динамическое выделение памяти, то следует удалить использованную память
        
        while (head != nullptr)
        {
            fifoElement* temp = head;
            head = head->next;
            delete temp;
        }
        std::cout <<"delete dynamicFIFO"<< std::endl;
    }
    void add(int val) { //методдобавления элемента
        if (size < maxSize) // если FIFO не заполнен, то добавляем элемент
        {
            fifoElement* temp = new fifoElement; //создаем новый элемент
            temp->value = val; //добавляем данные
            temp->next = nullptr; // обнуляем указатель на следующий элемент
            if (head != nullptr) { //если FIFO не пуст, то 
                tail->next = temp; //созданный элемент становится хвостом
                tail = temp;
            }
            else
            {
                head = tail = temp; // иначе созданный элемент становится и головой и хвостом
            }
            size++;//увеличивается текущий размер FIFO
        }
        else {
            std::cout << "FIFO is full" << std::endl;
        }
        
    }

    void push() { //метод удаления первого элемента
        if (size==0) { // если FIFO пуст, то выводим сообщение
            std::cout << "FIFO is empty" << std::endl;
        }
        else { // иначе удаляем первый элемент и перемещаем голову на следующий элемент
            fifoElement* temp = head->next;
            delete head;
            head = temp;
            size--;// уменьшаем текущий размер FIFO
        }
    }

    void getFIFO() { //метод вывода FIFO
        if (size == 0)
        {
            std::cout << "FIFO is empty" << std::endl;
        }
        else {

            fifoElement* temp = head;
            while (temp != nullptr)
            {

                std::cout << temp->value << ' ';
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        
    }
    
};

int main()
{   
    double durationEven = 0.0;
    double durationEvenNew = 0.0;
    writeComment("Ex/ #1");
    
    for (int i = 0; i < 100; i++) {
        isEven(i);
    }
    durationEven = Duration();
   
    
    for (int i = 0; i < 100; i++) {
        isEvenNew(i);
    }
    durationEvenNew = Duration();

    writeComment("Output of the array processing time by the first and second functions");
    std::cout << durationEven << '-' << durationEvenNew - durationEven << std::endl;


    writeComment("EX/2");
    writeComment("staticarrayFIFO");

    double durationNum1 = 0.0;
    double durationNum2 = 0.0;
    durationEven = Duration();

    ArrayFIFO* arrayFIFO = new ArrayFIFO(10);
    arrayFIFO->getArray();

    for (int i = 0; i < 15; i++)
    {
        arrayFIFO->add(i);
        arrayFIFO->getArray();
    }

    for (int i = 0; i < 15; i++)
    {
        arrayFIFO->push();
        arrayFIFO->getArray();
    }
    durationEvenNew = Duration();
    durationNum1 = durationEvenNew - durationEven;

    writeComment("EX/2");
    writeComment("dynamiccarrayFIFO");
    
    durationEven = Duration();
    DynamicFIFO* dynamicFIFO = new DynamicFIFO(10);
    dynamicFIFO->getFIFO();

    for (int i = 0; i < 15; i++)
    {
        dynamicFIFO->add(i);
        dynamicFIFO->getFIFO();
    }
  //  writeComment("EX/2");
    for (int i = 0; i < 15; i++)
    {
        dynamicFIFO->push();
        dynamicFIFO->getFIFO();
    }
    durationEvenNew = Duration();
    durationNum2 = durationEvenNew - durationEven;


    writeComment("Output of the array processing time by the first and second functions");
    std::cout << durationNum1 << '-' << durationNum2 << std::endl;


   // writeComment("EX/2");
    delete dynamicFIFO;
    delete arrayFIFO;


   
   
   // std::cout << durationEvenNew-durationEven << std::endl;

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
