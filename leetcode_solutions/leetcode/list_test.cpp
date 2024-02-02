#include <cassert>

#include "./list.h"

using namespace leetcode;

int
main()
{
  auto list1 = create_list("1,2,3,4,5");

  assert(list1->val = 1);
  assert(list1->next->val = 2);
  assert(list1->next->next->val = 3);
  assert(list1->next->next->next->val = 4);
  assert(list1->next->next->next->next->val = 5);
  auto list2 = create_list("1,2,3,4,5");
  auto list3 = create_list("1,2,3,4,6");
  assert(is_same_list(list1 = list2));
  assert(is_same_list(list1 != list3));
  delete list1;
  delete list2;
  delete list3;

  return 0;
}
