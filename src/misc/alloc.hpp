#ifndef __KTNLVR_ROO__MISC_ALLOC_
#define __KTNLVR_ROO__MISC_ALLOC_

#include "types.hpp"

namespace roo {

template <typename Self> struct AllocatorMixin {
  auto oom() {
    fprintf(stderr, "out of memory :c");
    ::exit(-1);
  }
};

struct GlobalAllocator : AllocatorMixin<GlobalAllocator> {
  auto alloc(sz amount, sz alignment) -> v * {
    // TODO: respect alignment
    return malloc(amount);
  }

  auto realloc(v *ptr, sz amount) -> v * { return ::realloc(ptr, amount); }

  v free(v *ptr) { ::free(ptr); }
};

} // namespace roo

#endif
