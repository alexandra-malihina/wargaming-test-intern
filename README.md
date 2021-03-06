# wargaming-test-intern
Тестовое задание на позицию Programming intern в компании Wargaming Санкт-Петербург

#ЗАДАНИЕ №1 (обязательное)
--------------------------------------
На языке Python или С/С++, написать алгоритм (функцию) определения четности целого числа, который будет аналогичен нижеприведенному по функциональности, но отличен по своей сути.
Объяснить плюсы и минусы обеих реализаций.
- Python example:
 def isEven(value):return value%2==0
- C/C++ example:
 bool isEven(int value){return value%2==0;
 
 Решение  (C++ - файл first_two.cpp, Python - first.py)
 ----------------
Улучшенный вариант функции проверки четности элемента. Использует бинарное умножение.
Поскольку нечетные числа в двоичной системе всегда оканчиваются 1, то при бинарном умножении числа на 1 нечетное число будет равно 1, а четное 0.
Улучшенный вариант работает быстрее.

С++
----------------------------
void isEvenNew(int value) {
    return !(value&1);
}

Python
-------------------------
def isEvenNew(value):
 return( not value&1)


#ЗАДАНИЕ №2 (обязательное)
--------------------------------------
На языках Python(2.7) и/или С++, написать минимум по 2 класса реализовывающих циклический буфер FIFO.
                Объяснить плюсы и минусы каждой реализации.
                
 Решение  (C++ - файл first_two.cpp, Python - second.py)
 ----------------
 Первый вариант - на основе статического массива, а второй на основе динамического. 
 Динамическое выделение памяти по сравнению со статическим выделением памяти дает следующие преимущества:
-	память выделяется по мере необходимости программным путем;
-	нет лишних затрат неиспользованной памяти. Выделяется столько памяти сколько нужно и если нужно;
-	можно выделять память для массивов информации, размер которых заведомо неизвестен. Определение размера массива формируется в процессе выполнения программы;
-	удобно осуществлять перераспределение памяти. Или другими словами, удобно выделять новый фрагмент для одного и того же массива, если нужно выделить дополнительную память или освободить ненужную;
-	при статическом способе выделения памяти трудно перераспределять память для переменной-массива, поскольку она уже выделена фиксировано. В случае динамического способа выделения, это делается просто и удобно.

Преимущества статического способа выделения памяти:
-	статическое (фиксированное) выделение памяти лучше использовать, когда размер массива информации заведомо известен и есть неизменным на протяжении выполнения всей программы;
-	статическое выделение памяти не требует дополнительных операций освобождения с помощью оператора delete. Отсюда вытекает уменьшение ошибок программирования. Каждому оператору new должен соответствовать свой оператор delete;
-	естественность (натуральность) представления программного кода, который оперирует статическими массивами.

Рещение на Pthon
-----------------
К сожалению, не смогла написать второй класс на Python. Но по сравнению с С++, реализация (написание кода) быстрее, объем программы тоже меньше.
Код прилагается


#ЗАДАНИЕ №3 (Дополнительно, будет бонусом)
---------------------------
На языке Python или С/С++, написать функцию, которая быстрее всего (по процессорным тикам) отсортирует данный ей массив чисел.
               <p> Массив может быть любого размера со случайным порядком чисел (в том числе и отсортированным).
               <p> Объяснить почему вы считаете, что функция соответствует заданным критериям.
                 
Решение (C++ - Sort_C++.cpp, Python - sortPy.py)
-------------------
Для решения данной задачи ярешила использовать сортировку Timsort.
Timsort — гибридный алгоритм сортировки, сочетающий сортировку вставками и сортировку слиянием.
Сортировка вставками более эффективна на небольших массивах. В моей реализации – массивы не более 64 элемента.

<p> Описание алгоритма:
  
1 Сортировка вставками:

-	Разбиение исходного массива на подмассивы размером не более 64 элемента с проверкой – отсортирован ли подмассив изначально
-	если подмассив не отсортирован, то сортировка вставками

<p>2 Сортировка слиянием, если размеры исходного массива больше 64 элементов и массив не был отсротирован с самого начала, то:
  
- если подмассивов больше 1,то происходит слияние первого и второго подмассивов в первый подмассив с удалением второго подмассива.
-  Иначе, первый подмассив – отсортированный исходный массив.

