class A {
public:
	int a;
	virtual void f();
	virtual void h();
};

class B {
public:
	int b;
	virtual void h();
	// virtual void h();
};

class C : public A, public B{
public:
	int c;
	virtual void h();
};

int main() {
    C c;
    return 0;
}
