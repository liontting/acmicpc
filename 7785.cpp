#include <iostream>
#include <string>
#include <set>
using namespace std;
int n;
string name, memory;
set<string> person;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	set<string>::reverse_iterator iter;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> memory;
		if (memory == "enter")
			person.insert(name);
		else
			if (person.find(name) != person.end())
				person.erase(person.find(name));
	}
	for (iter = person.rbegin(); iter != person.rend(); iter++)
		cout << *iter << "\n";
	return 0;
}