#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Иерархия классов, определяющая аспекты поведения

/// <summary>
/// Виртуальный класс для открытия двери
/// </summary>
class Action
{
public:
	/// <summary>
	/// Виртуальный деструктор
	/// по умолчанию ничего не делает
	/// </summary>
	virtual ~Action() {}
	/// <summary>
	/// Чисто виртуальный метод типа открытия двери
	/// </summary>
	virtual void act() = 0;
};
/// <summary>
/// Класс открытия двери КЛЮЧОМ
/// </summary>
class Key : public Action
{
public:
	/// <summary>
	/// Выводит тип открытия (ключом)
	/// </summary>
	void act() {
		cout << "Door is unlocking with key!" << endl;
	}
};
/// <summary>
/// Класс открытия двери ЩЕКОЛДОЙ
/// </summary>
class Latch : public Action
{
public:
	/// <summary>
	/// Выводит тип открытия (щеколдой)
	/// </summary>
	void act() {
		cout << "Door is unlocking with latch!" << endl;
	}
};
/// <summary>
/// Виртуальный класс для проверки состояния двери
/// </summary>
class Checker
{
public:
	/// <summary>
	/// Виртуальный деструктор
	/// по умолчанию ничего не делает
	/// </summary>
	virtual ~Checker() {}

	/// <summary>
	/// Чисто виртуальный метод
	/// Выводит состояние (открыта или закрыта дверь)
	/// </summary>
	virtual void check() = 0;
};
/// <summary>
/// Класс ОТКРЫТОЙ двери
/// </summary>
class Opened : public Checker
{
public:
	/// <summary>
	/// Выводит, что дверь открыта
	/// </summary>
	void check() {
		cout << "Door is opened!" << endl;
	}
};
/// <summary>
/// Класс ЗАКРЫТОЙ двери
/// </summary>
class Closed : public Checker
{
public:
	/// <summary>
	/// Выводит, что дверь закрыта
	/// </summary>
	void check() {
		cout << "Door is closed!" << endl;
	}
};

// Класс для использования

/// <summary>
/// Класс для работы с дверью
/// </summary>
class Door
{
public:
	/// <summary>
	/// Конструктор, инициализирует тип двери и её состояние
	/// </summary>
	Door(Action* act, Checker* chk) :
		door(act), checker(chk) {}
	/// <summary>
	/// Деструктор, удаляет указатели на тип двери и её состояние
	/// </summary>
	~Door() {
		delete door;
		delete checker;
	}
	/// <summary>
	/// Определение метода открытия (типа) двери
	/// </summary>
	void act() {
		door->act();
	}
	/// <summary>
	/// Определение состояние (откр/закр) двери
	/// </summary>
	void check() {
		checker->check();
	}
private:
	Action* door; ///< тип двери
	Checker* checker; ///< состояние двери
};

int main()
{
	Door* key = new Door(new Key(), new Opened());
	key->act();
	key->check();
	delete key;
	std::cout << std::endl;

	key = new Door(new Key(), new Closed());
	key->act();
	key->check();
	delete key;
	std::cout << std::endl;

	Door* la = new Door(new Latch(), new Opened());
	la->act();
    la->check();
	delete la;
	std::cout << std::endl;

	la = new Door(new Latch(), new Closed());
	la->act();
	la->check();
	delete la;

	return 0;
}