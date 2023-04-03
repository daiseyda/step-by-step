#include "s21_tests.h"

START_TEST(test_1) {
  char str[] = "0123456789";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_2) {
  char str[10] = "\00123456789";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_3) {
  char str[] = "0123456789";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_4) {
  char str[10] = "";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_5) {
  char str[10] = "\t\t\t\t\t\t\t\t";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_6) {
  char str[10] = "\t\t\t\t\t\t\t\t";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_7) {
  char str[10] = "";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_8) {
  char str[10] = "123\0123";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_9) {
  char str[] = "123\0123";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_10) {
  char str[] = "первая строка\0вторая строка";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_11) {
  char str[10] = "\0\0\0\0\0\0\0\0\0";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_12) {
  char str[] =
      "qWOdYDYIOuygZHh8BOIqx5vqI2yuhjnLPWuxXhaCZGm0kFllmSiJCwuqwrvGwQ9bAIhlToIZ"
      "eLvfMkb7TC7sF9exJb5vMoqEVmmPyGtIEguDzoQbK2a0YRZRqQ1q3sqmrAmEhghJQHWvuFLD"
      "dXnLiQaY4vIhhzV3Bv8OnzWdTtzTk325o9y0J6eirLujWCRrLzp4wRyXDg2DjsYrMLcxcywW"
      "I5y6fK4lG5yV3bgJLPkX3WjKyiFMANqUPsUFVNJ3GxfDBxskmyOYIPeI3Vt6Wo61NQJS3pcf"
      "7VQakDcVH2Wxi7nvru6zzRMTSwC2nYeb5KqlZ9J9xFcHkCPixIFbpN5CMwmEPti2C1KU01Ip"
      "1ftNv2lu7HJDNewBfse8jWBPsdrRolUWJf734YAv6nicsebsTU9NU13pZpUHdLnjval8CtYi"
      "pktpI62P54IR1qbjL0yJbuCTDszD70GPiI18yAV6N60It461SyYFtrqzy7X1PHLCxAVrAdyv"
      "6phn5tLKLaMCxon6kGJs85D4YG1nJEfxBq8Iy2KgmQMOxwqnLrvu39pDyUeQOuhZK5LqBakl"
      "gsy6tnxzHy8wA4SDZepiJIewIhQOaaMtw3dtpEHuaBy2Wxx8bKkj5gowS80G29fW7pr3ic5N"
      "3P0vf4Ef5jKEPK8e5M0D7Macn4OIpuIEK5S8XZRk5t4d2AZDcSiUAJkjoRwUsTRAXD50kVlL"
      "YaRxd9P0T7B9B1NbbQxfwKQYQKrDfWwmY5VlUfPJO8U9hqRBMdekF9f1Bt6Bb50gaIIzZcPe"
      "3YrijL9Ih0fZFuVGcP622QXp0VqlKwgRtVnszub46i1k4oYCn587mJB6P8FdnUBFAHfEsoAR"
      "jVcUxQg4OkgOfPKQZJhl48EZ9HnRalzckJ8S2uis7NlYTsusq8rP3sCO0GqSmuJxYtLbLO6D"
      "cf3yAdAcWYx3MTnXO4j749WR669WQTyYrYLWTILAC435kIjWfcrGbATfmj5DWaXbDkI4f4lK"
      "ssYW8B3o9tOjyMkG";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_13) {
  char str[] =
      "qWOdYDYIOuygZHh8BOIqx5vqI2yuhjnLPWuxXhaCZGm0kFllmSiJCwuqwrvGwQ9bAIhlToIZ"
      "eLvfMkb7TC7sF9exJb5vMoqEVmmPyGtIEguDzoQbK2a0YRZRqQ1q3sqmrAmEhghJQHWvuFLD"
      "dXnLiQaY4vIhhzV3Bv8OnzWdTtzTk325o9y0J6eirLujWCRrLzp4wRyXDg2DjsYrMLcxcywW"
      "I5y6fK4lG5yV3bgJLPkX3WjKyiFMANqUPsUFVNJ3GxfDBxskmyOYIPeI3Vt6Wo61NQJS3pcf"
      "7VQakDcVH2Wxi7nvru6zzRMTSwC2nYeb5KqlZ9J9xFcHkCPixIFbpN5CMwmEPti2C1KU01Ip"
      "1ftNv2lu7HJDNewBfse8jWBPsdrRolUWJf734YAv6nicsebsTU9NU13pZpUHdLnjval8CtYi"
      "pktpI62P54IR1qbjL0yJbuCTDszD70GPiI18yAV6N60It461SyYFtrqzy7X1PHLCxAVrAdyv"
      "6phn5tLKLaMCxon6kGJs85D4YG1nJEfxBq8Iy2KgmQMOxwqnLrvu39pDyUeQOuhZK5LqBakl"
      "gsy6tnxzHy8wA4SDZepiJIewIhQOaaMtw3dtpEHuaBy2Wxx8bKkj5gowS80G29fW7pr3ic5N"
      "3P0vf4Ef5jKEPK8e5M0D7Macn4OIpuIEK5S8XZRk5t4d2AZDcSiUAJkjoRwUsTRAXD50kVlL"
      "YaRxd9P0T7B9B1NbbQxfwKQYQKrDfWwmY5VlUfPJO8U9hqRBMdekF9f1Bt6Bb50gaIIzZcPe"
      "3YrijL9Ih0fZFuVGcP622QXp0VqlKwgRtVnszub46i1k4oYCn587mJB6P8FdnUBFAHfEsoAR"
      "jVcUxQg4OkgOfPKQZJhl48EZ9HnRalzckJ8S2uis7NlYTsusq8rP3sCO0GqSmuJxYtLbLO6D"
      "cf3yAdAcWYx3MTnXO4j749WR669WQTyYrYLWTILAC435kIjWfcrGbATfmj5DWaXbDkI4f4lK"
      "ssYW8B3o9tOjyMkG"
      "GkMyjOt9o3B8WYssKl4f4IkDbXaWD5jmfTAbGrcfWjIk534CALITWLYrYyTQW966RW947j4O"
      "XnTM3xYWcAdAy3fcD6OLbLtYxJumSqG0OCs3Pr8qsusTYlN7siu2S8JkczlaRnH9ZE84lhJZ"
      "QKPfOgkO4gQxUcVjRAosEfHAFBUndF8P6BJm785nCYo4k1i64buzsnVtRgwKlqV0pXQ226Pc"
      "GVuFZf0hI9LjirY3ePcZzIIag05bB6tB1f9FkedMBRqh9U8OJPfUlV5YmwWfDrKQYQKwfxQb"
      "bN1B9B7T0P9dxRaYLlVk05DXARTsUwRojkJAUiScDZA2d4t5kRZX8S5KEIupIO4ncaM7D0M5"
      "e8KPEKj5fE4fv0P3N5ci3rp7Wf92G08Swog5jkKb8xxW2yBauHEptd3wtMaaOQhIweIJipeZ"
      "DS4Aw8yHzxnt6ysglkaBqL5KZhuOQeUyDp93uvrLnqwxOMQmgK2yI8qBxfEJn1GY4D58sJGk"
      "6noxCMaLKLt5nhp6vydArVAxCLHP1X7yzqrtFYyS164tI06N6VAy81IiPG07DzsDTCubJy0L"
      "jbq1RI45P26IptkpiYtC8lavjnLdHUpZp31UN9UTsbescin6vAY437fJWUloRrdsPBWj8esf"
      "BweNDJH7ul2vNtf1pI10UK1C2itPEmwMC5NpbFIxiPCkHcFx9J9ZlqK5beYn2CwSTMRzz6ur"
      "vn7ixW2HVcDkaQV7fcp3SJQN16oW6tV3IePIYOymksxBDfxG3JNVFUsPUqNAMFiyKjW3XkPL"
      "Jgb3Vy5Gl4Kf6y5IWwycxcLMrYsjD2gDXyRw4pzLrRCWjuLrie6J0y9o523kTztTdWznO8vB"
      "3VzhhIv4YaQiLnXdDLFuvWHQJhghEmArmqs3q1QqRZRY0a2KbQozDugEItGyPmmVEqoMv5bJ"
      "xe9Fs7CT7bkMfvLeZIoTlhIAb9QwGvrwquwCJiSmllFk0mGZCahXxuWPLnjhuy2Iqv5xqIOB"
      "8hHZgyuOIYDYdOWq";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_14) {
  char str[] =
      "GkMyjOt9o3B8WYssKl4f4IkDbXaWD5jmfTAbGrcfWjIk534CALITWLYrYyTQW966RW947j4O"
      "XnTM3xYWcAdAy3fcD6OLbLtYxJumSqG0OCs3Pr8qsusTYlN7siu2S8JkczlaRnH9ZE84lhJZ"
      "QKPfOgkO4gQxUcVjRAosEfHAFBUndF8P6BJm785nCYo4k1i64buzsnVtRgwKlqV0pXQ226Pc"
      "GVuFZf0hI9LjirY3ePcZzIIag05bB6tB1f9FkedMBRqh9U8OJPfUlV5YmwWfDrKQYQKwfxQb"
      "bN1B9B7T0P9dxRaYLlVk05DXARTsUwRojkJAUiScDZA2d4t5kRZX8S5KEIupIO4ncaM7D0M5"
      "e8KPEKj5fE4fv0P3N5ci3rp7Wf92G08Swog5jkKb8xxW2yBauHEptd3wtMaaOQhIweIJipeZ"
      "DS4Aw8yHzxnt6ysglkaBqL5KZhuOQeUyDp93uvrLnqwxOMQmgK2yI8qBxfEJn1GY4D58sJGk"
      "6noxCMaLKLt5nhp6vydArVAxCLHP1X7yzqrtFYyS164tI06N6VAy81IiPG07DzsDTCubJy0L"
      "jbq1RI45P26IptkpiYtC8lavjnLdHUpZp31UN9UTsbescin6vAY437fJWUloRrdsPBWj8esf"
      "BweNDJH7ul2vNtf1pI10UK1C2itPEmwMC5NpbFIxiPCkHcFx9J9ZlqK5beYn2CwSTMRzz6ur"
      "vn7ixW2HVcDkaQV7fcp3SJQN16oW6tV3IePIYOymksxBDfxG3JNVFUsPUqNAMFiyKjW3XkPL"
      "Jgb3Vy5Gl4Kf6y5IWwycxcLMrYsjD2gDXyRw4pzLrRCWjuLrie6J0y9o523kTztTdWznO8vB"
      "3VzhhIv4YaQiLnXdDLFuvWHQJhghEmArmqs3q1QqRZRY0a2KbQozDugEItGyPmmVEqoMv5bJ"
      "xe9Fs7CT7bkMfvLeZIoTlhIAb9QwGvrwquwCJiSmllFk0mGZCahXxuWPLnjhuy2Iqv5xqIOB"
      "8hHZgyuOIYDYdOWq";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_15) {
  char str[10] = "123123123";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

START_TEST(test_16) {
  char str[10] = "9";
  s21_size_t lib_result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);
  ck_assert_uint_le(s21_result, lib_result);
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *suite = suite_create("s21_strlen");

  TCase *test_core = tcase_create("core");

  tcase_add_test(test_core, test_1);
  tcase_add_test(test_core, test_2);
  tcase_add_test(test_core, test_3);
  tcase_add_test(test_core, test_4);
  tcase_add_test(test_core, test_5);
  tcase_add_test(test_core, test_6);
  tcase_add_test(test_core, test_7);
  tcase_add_test(test_core, test_8);
  tcase_add_test(test_core, test_9);
  tcase_add_test(test_core, test_10);
  tcase_add_test(test_core, test_11);
  tcase_add_test(test_core, test_12);
  tcase_add_test(test_core, test_13);
  tcase_add_test(test_core, test_14);
  tcase_add_test(test_core, test_15);
  tcase_add_test(test_core, test_16);

  suite_add_tcase(suite, test_core);

  return suite;
}
