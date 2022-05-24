#include "Queue.hpp"

int main()
{

	Queue<size_t> q;

	q.push(3);
	q.push(10);

	std::cout << q.peek() << std::endl;
	q.pop();

	std::cout << q.peek() << std::endl;
	q.pop();
	return 0;
}
