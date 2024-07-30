#ifndef __KTNLVR_ROO__CONTAINERS_DARRAY_
#define __KTNLVR_ROO__CONTAINERS_DARRAY_

#include <stdlib.h>

#include "./misc/alloc.hpp"

namespace roo {

template <typename T, typename Alloc = GlobalAllocator> struct darray {
  darray() : _capacity(0), _size(0) {
    _data = (T *)_allocator.alloc(sizeof(T), alignof(T));
  }

  ~darray() {
    if (_data != nullptr)
      free(_data);
  }

  void push(const T &value) {
    _check_and_realloc();
    _data[_size++] = value;
  }

  void push(T &&value) {
    _check_and_realloc();
    _data[_size++] = std::move(value);
  }

  T &operator[](size_t i) { return _data[i]; }

  const T &operator[](size_t i) const { return _data[i]; }

  void _check_and_realloc() {
    if (_size == _capacity) {
      _capacity = (_capacity + 1) * 3;
      _data = (T *)_allocator.realloc(_data, sizeof(T) * _capacity);
      // TODO: handle nullptr
    }
  }

  T *_data;
  sz _capacity;
  sz _size;
  Alloc _allocator;
};

} // namespace roo

#endif
