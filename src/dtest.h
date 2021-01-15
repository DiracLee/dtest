#ifndef DTEST_DTEST_H_
#define DTEST_DTEST_H_

#include "color.h"

constexpr int N = 100;

struct {
  void (*func)();
  const char* func_name;
  bool statuc;
} func_arr[N];
int func_cnt = 0;

void add_test_func(void (*func)(), const char* func_name) {
  func_arr[func_cnt].func = func;
  func_arr[func_cnt].func_name = func_name;
  ++func_cnt;
}

#define TEST(test_suite_name, test_name)                                 \
  void dtest_##test_suite_name##_##test_name();                          \
  __attribute__((constructor)) void reg_##test_suite_name##test_name() { \
    add_test_func(dtest_##test_suite_name##_##test_name,                 \
                  #test_suite_name "." #test_name);                      \
  }                                                                      \
  void dtest_##test_suite_name##_##test_name()

#define EXPECT_PRED_FORMAT2(pred_format, val1, val2)                          \
  {                                                                           \
    __typeof(val1) __val1 = (val1), __val2 = (val2);                          \
    if (!((__val1)pred_format(__val2))) {                                     \
      printf(YELLOW("  %s:%d: Failure\n"), __FILE__, __LINE__);               \
      printf(YELLOW("    Expected: (%s) %s (%s), actual: %d vs %d\n"), #val1, \
             #pred_format, #val2, __val1, __val2);                            \
    }                                                                         \
  }

#define EXPECT_EQ(val1, val2) EXPECT_PRED_FORMAT2(==, val1, val2)

#define EXPECT_NE(val1, val2) EXPECT_PRED_FORMAT2(!=, val1, val2)

int RUN_ALL_TEST() {
  for (int i = 0; i < func_cnt; i++) {
    printf(GREEN("[ RUN      ] ") "%s\n", func_arr[i].func_name);
    func_arr[i].func();
  }
  return 0;
}

#endif  // DTEST_DTEST_H_
