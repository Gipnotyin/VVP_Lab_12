#include <iostream>
#include <stdbool.h>
#include <string>

using namespace std;

void days(int a);
void mounths(int b);
int g(char h);
void spat(int f);
void num1(int x1);
void num2(int x2);
void num3(int x3);
void colours(int col);
void pets(int pet);

int main()
{
	setlocale(LC_ALL, "ru");
	string arr{'W', 'N', 'E', 'S'};
	int number, day, mounth, variable, a, b, n;
	char h;
	bool end = true;
	while (end == true) {
		cout << "Выберите задание для проверки:\n" <<
			"1. Дан номер дня – целое число от 1 до 31 и месяца — целое число в диапазоне 1–12 (1 — январь, 2 — февраль и т. д.).\nВывести дату в виде текста (например, «пятое января»).\n"<<
			"2. Робот может перемещаться в четырех направлениях («С» — север, «З» — запад, «Ю» — юг, «В» — восток) и принимать три цифровые команды:\n0 — продолжать движение,\n1 — поворот налево,\n-1 — поворот направо.\nДан символ C — исходное направление робота и целое число N — посланная ему команда.\nВывести направление робота после выполнения полученной команды.\n" <<
			"3. Дано целое число в диапазоне 10–40, определяющее количество учебных заданий по некоторой теме.\nВывести строку-описание указанного количества заданий, обеспечив правильное согласование числа со словами «учебное задание», например: 18 — «восемнадцать учебных заданий».\n" <<
			"4. Дано целое число в диапазоне 100–999. Вывести строку-описание данного числа, например:\n256 — «двести пятьдесят шесть», 814 — «восемьсот четырнадцать».\n" <<
			"5. В восточном календаре принят 60-летний цикл, состоящий из 12- летних подциклов, обозначаемых названиями цвета: зеленый, красный, желтый, белый и черный.\nВ каждом подцикле годы носят названия животных: крысы, коровы, тигра, зайца, дракона, змеи, лошади, овцы, обезьяны, курицы, собаки и свиньи.\nПо номеру года определить его название, если 1984 год — начало цикла: «год зеленой крысы».\n" <<
			"\nДля выхода нажмите любую цифру!!!\n";
		cin >> number;
		if (number >= 1 && number <= 5) {
			switch (number)
			{
			case 1:
				cout << "Введите номер месяца: ";
				cin >> mounth;
				cout << "Введите номер дня: ";
				cin >> day;
				if (mounth == 2) {
					cout << "Какой год?\n" <<
						"1. Високосный год.\n" <<
						"2. Обычный год.\n";
					cin >> variable;
					if (variable != 1 && variable != 2) {
						cout << "Ошибка ввода\n";
						end = false;
						break;
					}
				}
				if ((mounth == 1 or mounth == 3 or mounth == 5 or mounth == 7 or mounth == 8 or mounth == 10 or mounth == 12) && day <= 31) {
					cout << "Сегодня: ";
					days(day);
					mounths(mounth);
				}
				else if ((mounth == 4 or mounth == 6 or mounth == 9 or mounth == 11) && day <= 30) {
					cout << "Сегодня: ";
					days(day);
					mounths(mounth);
				}
				else if (mounth == 2 && day <= 28 && variable == 2) {
					cout << "Сегодня: ";
					days(day);
					mounths(mounth);
				}
				else if (mounth == 2 && day <= 29 && variable == 1) {
					cout << "Сегодня: ";
					days(day);
					mounths(mounth);
				}
				else {
					cout << "Ошибка ввода, введите корректные данные!!!\n";
				}
				break;
			case 2:
				cout << "Введите начальное положение: " <<
					"«N» — север\n" << "«W» — запад\n" << "«S» — юг\n" << "«E» — восток\n";
				cin >> h;
				cout << "Выберите команду:\n" <<
					"0 — продолжать движение\n" <<
					"1 — поворот налево\n" <<
					"-1 — поворот направо\n";
				cin >> b;
				n = g(h);
				if (b == 0) {
					cout << "Направление робота: " << arr[n] << endl;
				}
				else if (b == 1) {
					cout << "Робот повернул налево, его положение теперь: " << arr[(4 + (n - 1)) % 4] << endl;
				}
				else if (b == -1) {
					cout << "Робот повернул направо, его положение теперь: " << arr[(n + 1) % 4] << endl;
				}
				else
					cout << "Ошибка ввода!!!\n";
				break;
			case 3:
				cout << "Введите целое число в диапозоне 10-40: ";
				cin >> n;
				if (n % 10 == 1 && n != 11) {
					cout << n << " - <<";
					spat(n);
					cout << " учебное задание>>\n";
				}
				else if (n >= 10 and n <= 40) {
					cout << n << " - <<";
					spat(n);
					cout << " учебных заданий>>\n";
				}
				else {
					cout << "Ошибка ввода, будьте умнее, выберите то, что просят!!!\n";
				}
				break;
			case 4:
				cout << "Введите целое число в диапозоне 100-999: ";
				cin >> n;
				if (n > 999 or n < 100) {
					cout << "Вы снова ввели не корректные данные!!!\n";
				}
				else {
					if ((n / 10) % 10 == 1) {
						cout << n << " - <<";
						num1(n / 100);
						spat(n % 100);
						cout << ">>\n";
					}
					else {
						cout << n << " - <<";
						num1(n / 100);
						num2((n % 100) / 10);
						num3(n % 10);
						cout << ">>\n";
					}
				}
				break;
			case 5:
				cout << "Введите год: ";
				cin >> n;
				if (n < 0) {
					cout << "И снова ошибка ввода!!!\n";
				}
				else {
					cout << n << " - <<год ";
					colours(n);
					pets(n%12);
					cout << ">>\n";
				}
				break;
			}
		}
		else {
			cout << "Спасибо за прверку лабы!!! :)\n";
			end = false;
		}
	}
}

void days(int a) {
	switch (a)
	{
	case 1:
		cout << "Первое ";
		break;
	case 2:
		cout << "Второе ";
		break;
	case 3:
		cout << "Третье ";
		break;
	case 4:
		cout << "Четвёртое ";
		break;
	case 5:
		cout << "Пятое ";
		break;
	case 6:
		cout << "Шестое ";
		break;
	case 7:
		cout << "Седьмое ";
		break;
	case 8:
		cout << "Восьмое ";
		break;
	case 9:
		cout << "Девятое ";
		break;
	case 10:
		cout << "Десятое ";
		break;
	case 11:
		cout << "Одиннадцатое ";
		break;
	case 12:
		cout << "Двенадцатое ";
		break;
	case 13:
		cout << "Тринадцатое ";
		break;
	case 14:
		cout << "Четырнадцатое ";
		break;
	case 15:
		cout << "Пятнадцатое ";
		break;
	case 16:
		cout << "Шестнадцатое ";
		break;
	case 17:
		cout << "Семнадцатое ";
		break;
	case 18:
		cout << "Восемнадцатое ";
		break;
	case 19:
		cout << "Девятнадцатое ";
		break;
	case 20:
		cout << "Двадцатое ";
		break;
	case 21:
		cout << "Двадцать первое ";
		break;
	case 22:
		cout << "Двадцать второе ";
		break;
	case 23:
		cout << "Двадцать третье ";
		break;
	case 24:
		cout << "Двадцать четвёртое ";
		break;
	case 25:
		cout << "Двадцать пятое ";
		break;
	case 26:
		cout << "Двадцать шестое ";
		break;
	case 27:
		cout << "Двадцать седьмое ";
		break;
	case 28:
		cout << "Двадцать восьмое ";
		break;
	case 29:
		cout << "Двадцать девятое ";
		break;
	case 30:
		cout << "Тридцатое ";
		break;
	case 31:
		cout << "Тридцать первое ";
		break;
	}
}

void mounths(int b) {
	switch (b)
	{
	case 1:
		cout << "января\n";
		break;
	case 2:
		cout << "февраля\n";
		break;
	case 3:
		cout << "марта\n";
		break;
	case 4:
		cout << "апреля\n";
		break;
	case 5:
		cout << "мая\n";
		break;
	case 6:
		cout << "июня\n";
		break;
	case 7:
		cout << "июля\n";
		break;
	case 8:
		cout << "августа\n";
		break;
	case 9:
		cout << "сентября\n";
		break;
	case 10:
		cout << "октября\n";
		break;
	case 11:
		cout << "ноября\n";
		break;
	case 12:
		cout << "декабря\n";
		break;
	}
}

int g(char h) {
	if (h == 'W' or h == 'w') {
		return 0;
	}
	else if (h == 'N' or h == 'n') {
		return 1;
	}
	else if (h == 'E' or h == 'e') {
		return 2;
	}
	else if (h == 'S' or h == 's') {
		return 3;
	}
}

void spat(int f) {
	switch (f)
	{
	case 10:
		cout << "десять";
		break;
	case 11:
		cout << "одиннадцать";
		break;
	case 12:
		cout << "двенадцать";
		break;
	case 13:
		cout << "тринадцать";
		break;
	case 14:
		cout << "четырнадцать";
		break;
	case 15:
		cout << "пятнадцать";
		break;
	case 16:
		cout << "шестнадцать";
		break;
	case 17:
		cout << "семнадцать";
		break;
	case 18:
		cout << "восемнадцать";
		break;
	case 19:
		cout << "девятнадцать";
		break;
	case 20:
		cout << "двадцать";
		break;
	case 21:
		cout << "двадцать одно";
		break;
	case 22:
		cout << "двадцать два";
		break;
	case 23:
		cout << "двадцать три";
		break;
	case 24:
		cout << "двадцать четыре";
		break;
	case 25:
		cout << "двадцать пять";
		break;
	case 26:
		cout << "двадцать шесть";
		break;
	case 27:
		cout << "двадцать семь";
		break;
	case 28:
		cout << "двадцать восемь";
		break;
	case 29:
		cout << "двадцать девять";
		break;
	case 30:
		cout << "тридцать";
		break;
	case 31:
		cout << "тридцать одно";
		break;
	case 32:
		cout << "тридцать два";
		break;
	case 33:
		cout << "тридцать три";
		break;
	case 34:
		cout << "тридцать четыре";
		break;
	case 35:
		cout << "тридцать пять";
		break;
	case 36:
		cout << "тридцать шесть";
		break;
	case 37:
		cout << "тридцать семь";
		break;
	case 38:
		cout << "тридцать восемь";
		break;
	case 39:
		cout << "тридцать девять";
		break;
	case 40:
		cout << "сорок";
		break;
	default:
		cout << "Ошибка ввода!!!\n";
		break;
	}
}

void num1(int x1) {
	switch (x1)
	{
	case 1:
		cout << "сто ";
		break;
	case 2:
		cout << "двести ";
		break;
	case 3:
		cout << "триста ";
		break;
	case 4:
		cout << "четыреста ";
		break;
	case 5:
		cout << "пятьсот ";
		break;
	case 6:
		cout << "шестьсот ";
		break;
	case 7:
		cout << "семьсот ";
		break;
	case 8:
		cout << "восемьсот ";
		break;
	case 9:
		cout << "девятьсот ";
		break;
	}
}

void num2(int x2) {
	switch (x2)
	{
	case 2:
		cout << "двадцать ";
		break;
	case 3:
		cout << "тридцать ";
		break;
	case 4:
		cout << "сорок ";
		break;
	case 5:
		cout << "пятьдесят ";
		break;
	case 6:
		cout << "шестьдесят ";
		break;
	case 7:
		cout << "семьдесят ";
		break;
	case 8:
		cout << "восемьдесят ";
		break;
	case 9:
		cout << "девяноста ";
		break;
	}
}

void num3(int x3) {
	switch (x3)
	{
	case 1:
		cout << "один";
		break;
	case 2:
		cout << "два";
		break;
	case 3:
		cout << "три";
		break;
	case 4:
		cout << "четыре";
		break;
	case 5:
		cout << "пять";
		break;
	case 6:
		cout << "шесть";
		break;
	case 7:
		cout << "семь";
		break;
	case 8:
		cout << "восемь";
		break;
	case 9:
		cout << "девять";
		break;
	}
}

void colours(int col) {
	if (col % 60 >= 3 and col % 60 <= 14) {
		cout << "зелёной ";
	}
	else if (col % 60 >= 15 and col % 60 <= 26) {
		cout << "красной ";
	}
	else if (col % 60 >= 27 and col % 60 <= 38) {
		cout << "жёлтой ";
	}
	else if (col % 60 >= 39 and col % 60 <= 50) {
		cout << "белой ";
	}
	else if ((col % 60 >= 51 and col % 60 <= 59) or (col >=0 and col <= 2)) {
		cout << "чёрной ";
	}
}

void pets(int pet) {
	switch (pet)
	{
	case 0:
		cout << "обезьяны";
		break;
	case 1:
		cout << "курицы";
		break;
	case 2:
		cout << "собаки";
		break;
	case 3:
		cout << "свиньи";
		break;
	case 4:
		cout << "крысы";
		break;
	case 5:
		cout << "коровы";
		break;
	case 6:
		cout << "тигра";
		break;
	case 7:
		cout << "зайца";
		break;
	case 8:
		cout << "дракона";
		break;
	case 9:
		cout << "змеи";
		break;
	case 10:
		cout << "лошади";
		break;
	case 11:
		cout << "овцы";
		break;
	}
}