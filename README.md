# Квадратное уравнение

![](https://github.com/EntryFrager/square/blob/main/kvadratka_2.png?raw=true)
![](https://github.com/EntryFrager/square/blob/main/kvadratka_1.png?raw=true)
![](https://github.com/EntryFrager/square/blob/main/kvadratka_3.png?raw=true)

## Чтобы установить мою программу тебе нужно выполнить эти действия:

### 1.При помощи этой команды(её нужно вводить в командной строке) скачай все файлы в один свой файл.

    git clone https://github.com/EntryFrager/square.git

### 2. Далее в командной строке открой свой файл, куда ты установил программу и напиши:

    g++ main.cpp kvadratka.cpp test.cpp error.cpp -o quadratic_equation.exe

### 3. Все, программа готова к использованию, для этого в командной строке пропиши

    quadratic_equation.exe

***
>Чтобы открыть меню опций напиши в командную строку:

    quadratic_equation.exe -h

> Чтобы запустить тестирование программы, ты можешь написать:

    quadratic_equation.exe -t FILENAME.txt

> Вместо FILENAME.txt, ты должен написать имя своего файла, или ничего не писать, но тогда будет использоваться предустановленный файл для тестов.

>Если ты напишешь:
    
    quadratic_equation.exe FILENAME.TXT -t
>то программа продолжит свою работу в обычном режиме.

