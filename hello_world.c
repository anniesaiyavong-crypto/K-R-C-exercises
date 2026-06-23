int main() {
	const char msg[] = "hello, world\n";
	__asm__(
			"mov $1, %%rax\n"
			"mov $1, %%rdi\n"
			"mov %0, %%rsi\n"
			"mov $13, %%rdx\n"
			"syscall\n"
			:
			: "r"(msg)
			: "%rax", "%rdi", "%rsi", "%rdx"
	       );

			return 0;
}

