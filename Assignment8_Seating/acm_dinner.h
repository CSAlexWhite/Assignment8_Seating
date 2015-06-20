/* ACM Dinner Header File */

#ifndef ACM_DINNER
#define ACM_DINNER

std::list<int> set_candidates(int n);
void print_table(const int* table, int size);
void print_list(std::list<int> list);
bool is_valid(const int* list, int size);
int seat(int* table, std::list<int> attendees, int table_size);
int get_team(int member);
int get_sex(int member);
int main();

#endif
