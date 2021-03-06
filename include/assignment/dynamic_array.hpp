#pragma once

#include <vector>  // НЕЛЬЗЯ ИСПОЛЬЗОВАТЬ

#include "assignment/private/list.hpp"  // List

namespace assignment {

  /**
   * Структура данных "массив переменной длины".
   *
   * Элементы находятся последовательно в памяти (по соседним адресам).
   */
  struct DynamicArray : List {
   private:
    // поля структуры
    int size_{0};         // кол-во элементов в массиве
    int capacity_{0};     // емкость массива (кол-во ячеек в массиве)
    int* data_;  // указатель на выделенный блок памяти

   public:
    // константы структуры
    static constexpr int kInitCapacity = 10;  // начальная емкость массива
    static constexpr int kCapacityGrowthCoefficient = 5;  // коэффициент увеличения размера массива

    /**
     * Создание массива с указанной емкостью ~ O(n).
     *
     * Выделенные ячейки массива инициализируются нулевым значением.
     *
     * @param capacity - начальная емкость массива (опционально)
     * @throws invalid_argument при указании неположительной емкости массива
     */
    explicit DynamicArray(int capacity = kInitCapacity);

    /**
     * Деструктор ~ O(1).
     *
     * Высвобождает выделенную память.
     * Устанавливает поля в нулевые значения.
     */
    ~DynamicArray() override;

    /**
     * Добавление элемента в конец массива ~ O(1) или O(n).
     *
     * При недостаточной емкости массив расширяется
     * на kCapacityGrowthCoefficient с сохранением элементов.
     *
     * @param value - значение добавляемого элемента
     */
    void Add(int value) override;

    /**
     * Вставка элемента в массив по индексу ~ O(n).
     *
     * При недостаточной емкости массив расширяется
     * на kCapacityGrowthCoefficient с сохранением элементов.
     *
     * @param index - позиция для вставки элемента в массив
     * @param value - значение вставляемого элемента
     * @return true - операция прошла успешно, false - индекс за пределами массива
     */
    bool Insert(int index, int value) override;

    /**
     * Изменение значения элемента массива по индексу ~ O(1).
     *
     * @param index - позиция изменяемого элемента в массиве
     * @param new_value - новое значение элемента
     * @return true - операция прошла успешно, false - индекс за пределами массива
     */
    bool Set(int index, int new_value) override;

    /**
     * Удаление элемента из массива по индексу ~ O(n).
     *
     * @param index - позиция удаляемого элемента в массиве
     * @return значение удаленного элемента или ничего (индекс за пределами списка)
     */
    std::optional<int> Remove(int index) override;

    /**
     * Очистка массива ~ O(1).
     *
     * Обнуляет размер массива.
     */
    void Clear() override;

    /**
     * Получение значения элемента массива по индексу ~ O(1).
     *
     * @param index - позиция элемента в массиве
     * @return значение найденного элемента или ничего (индекс за пределами списка)
     */
    std::optional<int> Get(int index) const override;

    /**
     * Поиск индекса первого вхождения элемента с указанным значением ~ O(n).
     *
     * @param value - значение элемента
     * @return индекс найденного элемента или ничего (в случае отсутствия элемента)
     */
    std::optional<int> IndexOf(int value) const override;

    /**
     * Проверка наличия элемента в массиве по значению ~ O(n).
     *
     * @param value - значение элемента
     * @return true - при наличии элемента в массиве, false - при отсутствии элемента
     */
    bool Contains(int value) const override;

    /**
     * Проверка пустоты массива ~ O(1).
     *
     * @return true - массив пустой, false - в массиве есть элементы
     */
    bool IsEmpty() const override;

    /**
     * Возвращает размер массива ~ O(1).
     *
     * @return количество элементов в массиве
     */
    int size() const override;

    /**
     * Возвращает емкость массива ~ O(1).
     *
     * @return количество выделенных ячеек массива
     */
    int capacity() const;

    /**
     * Увеличение емкости массива ~ O(n).
     *
     * @param new_capacity - новая емкость массива
     * @return true - операция прошла успешно, false - новая емкость меньше или равна текущей
     */
    bool Resize(int new_capacity);

    // ДЛЯ ТЕСТИРОВАНИЯ
    DynamicArray(const std::vector<int>& values, int capacity);

    std::vector<int> toVector(std::optional<int> size = std::nullopt) const;
  };

}  // namespace assignment