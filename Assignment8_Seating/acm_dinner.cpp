#include <iostream>
#include <list>
#include "acm_dinner.h"
#include <chrono>
using namespace std;

int total_successes;
int nodes_visited;

/* [works] add teams to the list  */
list<int> set_candidates(int n)
{
	list<int> output;

	int position = 0;
	for (int i = 10; i <= n * 10; i += 10)
	{
		for (int j = 0; j < 2; j++)
		{
			output.push_back(i + j);
		}
	}

	return output;
}

/* [works] prints the entirety of a list/table  */
void print_list(list<int> list) //works
{
	for (std::list<int>::iterator i = list.begin(); i != list.end(); ++i)
	{
		cout << " " << *i;
	}

	cout << endl;
}

/* [works] checks the configuration for validity  */
bool is_valid(list<int> table)
{
	int current = 0, left_of = 0;

	for (std::list<int>::iterator person = table.begin(); person != table.end(); ++person)
	{
		list<int>::iterator next;
		if (*person == table.back()) next = table.begin();

		else
		{
			next = person;
			++next;
		}

		if (get_team(*person) == get_team(*next))
		{
			//cout << *person << " and " << *next << " are on the same team" << endl;
			return false;
		}

		if (get_sex(*person) == 0 && get_sex(*next) == 0)
		{
			//cout << *person << " and " << *next << " are both male" << endl;
			return false;
		}
	}

	return true;
}

/* [works] check if neighbors are allowed next to each other */
bool legitimate_neighbors(int last, int next){

	if (get_team(last) == get_team(next)) return false;
	if (get_sex(last) == 0 && get_sex(next) == 0) return false;
	return true;
}

int seat(int last_person, int new_person, list<int> people, list<int> table)
{
	++nodes_visited;

	last_person = new_person; 
	people.remove(new_person);
	table.push_back(new_person);

	if (people.empty()){ 

		if (legitimate_neighbors(table.front(), table.back())){
			
			/*cout << "Success: ";
			print_list(table);*/
			total_successes += 1;
			return 1;
		}

		return 0;
	}

	for (std::list<int>::iterator person = people.begin();  person != people.end(); ++person)
	{
		if (!legitimate_neighbors(last_person, *person)){ // pruning 

			continue;
		}

		seat(last_person, *person, people, table);
	}

	table.remove(new_person);
	people.push_back(new_person);
}

/* [works] returns the team that an integer represents */
int get_team(int member) //works
{
	return member / 10;
}

/* [works] returns the sex that an integer represents */
int get_sex(int member)
{
	return member % 2;
}

int unit_test()
{
	return 0;
}

void arrange(int num_teams)
{
	total_successes = 0;
	nodes_visited = 0;

	auto t1 = std::chrono::high_resolution_clock::now();
	list<int> candidates = set_candidates(num_teams);
	list<int> table;

	cout << "Candidates are: ";
	print_list(candidates);
	cout << endl;

	candidates.pop_front();
	seat(0,
		10,
		candidates, 
		table);
	cout << "Nodes visited: " << nodes_visited << endl;
	cout << "Successful configurations: " << total_successes / 2 << endl;
	auto t2 = std::chrono::high_resolution_clock::now();

	cout << "Total millis: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << endl;
	cout << "\n------------------------------------------------------\n" << endl;
}

int main()
{

	for(int i = 1; i<8; i++){

		cout << i << " teams" << endl;
		arrange(i);
	}
		
	system("pause");
}