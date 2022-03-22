#include <stdio.h>
#include <memory>

struct hello {
	hello() {
		printf("say hi to the world\n");
	}

	static void sayHelloTo(const char *name) {
		printf("hi %s\n");
	}

	~hello() {
		printf("say goodbye to the world\n");
	}
};

static struct hello *hi = new hello();
static std::unique_ptr<hello> ptr{new hello()};

struct mem {
	char *ptr;
	char ca[4];
};

int main(void)
{
	struct mem *mem1 = new struct mem;
	mem1->ptr = new char[4];

	struct mem mem2;
	
	printf("%p\n", mem1);
	printf("%p\n", mem1->ptr);
	printf("%p\n", &(mem1->ca));
	printf("%p\n", &mem2);
	printf("%p\n", &(mem2.ca));
}
