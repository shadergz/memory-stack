#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>

template<typename T>
class MemoryStack
{
public:
	MemoryStack(T* data_ptr, size_t arena_size) : m_data_ptr(data_ptr), m_arena_size(arena_size)
	{
		memset(m_data_ptr, 0, sizeof(T) * arena_size);
		assert(m_data_ptr);
	}
	~MemoryStack() = default;

	auto lenght() const
	{
		return m_arena_size;
	}

	auto alloca(T value)
	{
		m_data_ptr[m_cursor++] = value;
		assert((m_cursor <= m_arena_size));
	}
	auto operator[](size_t index) const {
		return m_data_ptr[index];
	}
	auto get(size_t index) const
	{
		return m_data_ptr[index];
	}

	typedef T* iterator;

	iterator begin() 
	{
		return &m_data_ptr[0];
	}

	iterator end() 
	{ 
		return &m_data_ptr[m_cursor];
	}

private:
	size_t m_arena_size{};
	size_t m_cursor{};
	T* m_data_ptr{};
};

int main()
{
	int arri[105];
	MemoryStack<int> arena(arri, sizeof(arri)/sizeof(int));
	int i = 0;
	srand(time(nullptr));

	auto lenght = arena.lenght();
	for (i = 0; i < lenght; i++) {
		arena.alloca(rand() % 1000);
	}

	for (int k : arena) {
		std::printf("%d\n", k);
	}

	return 0;
}


