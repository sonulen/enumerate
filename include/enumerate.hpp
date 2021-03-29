#pragma once

#include <iterator>
#include <tuple>
#include <utility>

namespace mtl {

/**
   \brief Функция enumerate() применяется для итерируемых коллекций (строки,
   списки, словари и др.) и создает объект, который генерирует кортежи,
   состоящие из двух элементов - индекса элемента и ссылки на сам элемент.

   \tparam T Тип итерируемой коллекции
   \param iterable Итерируемая коллекция
   \return constexpr auto Новый итерируемый объект
 */
template <typename T>
constexpr auto enumerate(T&& iterable) {
    struct iterator {
        typedef decltype(std::begin(std::declval<T>())) iterator_type;

        int           i;
        iterator_type iter;

        bool operator!=(const iterator& rhs) const {
            return iter != rhs.iter;
        }
        void operator++() {
            ++i;
            ++iter;
        }

        auto operator*() const {
            return std::tie(i, *iter);
        }
    };

    struct wrapper {
        T    iterable;
        auto begin() {
            return iterator{0, std::begin(iterable)};
        }
        auto end() {
            return iterator{0, std::end(iterable)};
        }
    };

    return wrapper{std::forward<T>(iterable)};
}

}  // namespace mtl
