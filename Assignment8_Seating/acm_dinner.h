/* ACM Dinner Header File */

#ifndef ACM_DINNER
#define ACM_DINNER

std::list<int> set_candidates(int n);
void print_list(std::list<int> list);
bool legitimate_neighbors(int last, int next);
int seat(int last_person, int new_person, std::list<int> people, std::list<int> table);
int get_team(int member);
int get_sex(int member);
void arrange(int num_teams);
int main();

#endif
