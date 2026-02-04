CC = gcc
CFLAGS = -Wall -Wno-stringop-overflow -fno-stack-protector -z execstack -O0

all: auth

auth: auth.c
	$(CC) $(CFLAGS) $< -o $@

test: auth
	# Test valid password
	printf "s3cr3t\nq\n" | ./auth | grep "Access granted"
	# Test invalid password
	printf "wrong\nq\n" | ./auth | grep "Access denied"
	# Test password length
	printf "abcdefghijklmnopqrstuvwxyz\nq\n" | ./auth | grep "Terminating session"

clean:
	rm -f auth
