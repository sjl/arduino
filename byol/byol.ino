#define CONS 0
#define NUMBER 1
#define SYMBOL 2


// Types
typedef struct sexp {
	char tag;
} sexp;
typedef struct cons {
	char tag;
	sexp* car;
	sexp* cdr;
} cons;
typedef struct number {
	char tag;
	int value;
} number;
typedef struct symbol {
	char tag;
	char* name;
} symbol;

// Alloc
number* allocate_number(int value) {
	number* result = (number*)malloc(sizeof(number));
	result->tag = NUMBER;
	result->value = value;
	return result;
}

cons* allocate_cons(sexp* car, sexp* cdr) {
	cons* result = (cons*)malloc(sizeof(cons));
	result->tag = CONS;
	result->car = car;
	result->cdr = cdr;
	return result;
}

symbol* allocate_symbol(const char* name) {
	symbol* result = (symbol*)malloc(sizeof(symbol));
	result->tag = SYMBOL;
	result->name = strdup(name);
	return result;
}

// Free
void free_symbol(symbol* expr) {
	free(expr->name);
	free(expr);
}
void free_number(number* expr) {
	free(expr);
}
void free_cons(cons* expr) {
	free(expr);
}

void _free(sexp* expr) {
	if (expr->tag == CONS) free_cons((cons*) expr);
	else if (expr->tag == NUMBER) free_number((number*) expr);
	else if (expr->tag == SYMBOL) free_symbol((symbol*) expr);
}

// Print
void print_cons(cons* expr) {
	Serial.print("(");
	print(expr->car);
	Serial.print(" . ");
	print(expr->cdr);
	Serial.print(")");
}

void print_number(number* expr) {
	Serial.print(expr->value);
}

void print_symbol(symbol* expr) {
	Serial.print(expr->name);
}

void print(sexp* expr) {
	if (expr->tag == CONS) print_cons((cons*) expr);
	else if (expr->tag == NUMBER) print_number((number*) expr);
	else if (expr->tag == SYMBOL) print_symbol((symbol*) expr);
}

// Main
void setup() {
	Serial.begin(9600);
	Serial.setTimeout(60 * 60 * 1000);
	Serial.print("BYOL v0");
	Serial.println("");

	symbol* foo = allocate_symbol("foo");
	number* bar = allocate_number(420);
	cons* c = allocate_cons((sexp*) foo, (sexp*) bar);

	print((sexp*) c);

	_free((sexp*) foo);
	_free((sexp*) bar);
	_free((sexp*) c);
}

void loop() {
	while(1);
}
